//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	read the prty file to build the list of tree				//
//	file				:	PrtyTree.cpp												//
//	Description			:	use for operate the prty									//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/1/20	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BuildVarRelation.h"
#include "ParseFile.h"
#include "StringHandler.h"
#include "BuildPrmRelation.h"
#include "PrtyCompare.h"
#include "PrmCompare.h"

Cprty_tree* g_prty_tree = NULL;

Cprty_tree::Cprty_tree()
{
	vector_prty_tree_node	= new vector < Cprty_tree_node* > ;
	stack_prty_tree			= new stack < Cprty_tree_node* > ;
	node					= new Cprty_tree_node;
	old_node				= new Cprty_tree_node;	
}

Cprty_tree::~Cprty_tree(void)
{
	delete vector_prty_tree_node;			vector_prty_tree_node = NULL;
	delete stack_prty_tree;					stack_prty_tree = NULL;

	DeleteTree(&old_node);
	DeleteTree(&node);
	
	delete[] ptryTreeList;					ptryTreeList = NULL;
}

void Cprty_tree::DeleteTree(Cprty_tree_node** pnode)
{
	if ((*pnode) == NULL)
		return;
	if ((*pnode)->hasChildren)
	{
		for (vector<Cprty_tree_node*>::iterator it = (*pnode)->children.begin(); it != (*pnode)->children.end(); it++)
		{
			DeleteTree(&(*it));
		}
	}
	delete (*pnode);
	(*pnode) = NULL;
	return;
}

void Cprty_tree::initVar( int16 level )
{
	ptryTreeList = new list<PRMPRTY>[level];
}

void Cprty_tree::UpdateNewTree(void)
{
	//首先判断根node是否一致。不一致直接退出
	if (old_node->prty.memberName == node->prty.memberName)
	{
		node->prty.memberType		= old_node->prty.memberType;
		node->prty.memberName		= old_node->prty.memberName;
		node->prty.parent			= old_node->prty.parent;
		node->prty.unit				= old_node->prty.unit;
		node->prty.introduction		= old_node->prty.introduction;
		node->prty.uplimit			= old_node->prty.uplimit;
		node->prty.downlimit		= old_node->prty.downlimit;

		CopyTreeItem(node, old_node);
	}
	else
	{
		return;
	}
}

//////////////////////////////////////////////////////////////////////////
//内部迭代复制旧的信息到新的信息。
//////////////////////////////////////////////////////////////////////////
void Cprty_tree::CopyTreeItem(Cprty_tree_node* newnode, Cprty_tree_node* oldnode)
{
	//假如新的有child
	if ((newnode->hasChildren))
	{
		for (vector<Cprty_tree_node*>::iterator it_new = newnode->children.begin(); newnode->children.end() != it_new; it_new++)
		{
			//假如旧的有chilld
			if (oldnode->hasChildren)
			{
				//在旧的中找是否有和新的中匹配的，如果匹配就复制
				for (vector<Cprty_tree_node*>::iterator it_old = oldnode->children.begin(); oldnode->children.end() != it_old; it_old++)
				{
					if ((*it_old)->prty.memberName == (*it_new)->prty.memberName)
					{
						(*it_new)->prty.memberType			= (*it_old)->prty.memberType;
						(*it_new)->prty.memberName			= (*it_old)->prty.memberName;
						(*it_new)->prty.parent				= (*it_old)->prty.parent;
						(*it_new)->prty.unit				= (*it_old)->prty.unit;
						(*it_new)->prty.introduction		= (*it_old)->prty.introduction;
						(*it_new)->prty.uplimit				= (*it_old)->prty.uplimit;
						(*it_new)->prty.downlimit			= (*it_old)->prty.downlimit;
						//在旧的中找到新的值，那么就进入其下一层
						CopyTreeItem((*it_new), (*it_old));
					}
				}
			}
			
		}
	}
}

int16 Cprty_tree::findTreeElement(vector<wstring>& vec, int16 level, Cprty_tree_node* pnode, Cprty_tree_node** element)
{
	int16 rtn;
	//假如level是0时，如果一级比较不对，直接退出。
	if (level == 0)
	{
		if (pnode->prty.memberName != vec[0])
		{
			*element = NULL;
			return -1;
		}
		//假如只有一级，那么就是根节点。
		if (vec.size() == 1)
		{
			*element = pnode;
			return 0;
		}
	}
	//如果一级比较ok，进行下一级比较
	if (pnode->hasChildren)
	{		
		vector<Cprty_tree_node*>::iterator it;
		for (it = pnode->children.begin(); it != pnode->children.end(); it++)
		{
			level++;
			if (vec[level]==(*it)->prty.memberName)
			{
				//将找到的指针赋给element
				*element = (*it);

				//判断是否已经找到最底层
				if (level >= ((int16)(vec.size()-1)))
				{
					return 0; //已经找到最底层
				}
				rtn = findTreeElement(vec, level, (*it), element);

				if (rtn == 0)
				{
					return 0;
				}
				else
				{
					return rtn;
				}
				
			}
			level--;
		}
		if (it == pnode->children.end())
		{
			return -1; //输入的字符串不对。
		}
		else
		{
			return -3;
		}
	}
	else
	{
		return -2;
	}
}

void Cprty_tree::splitTreeNode2Level(int16 level)
{
	for (int32 j = 0; j < level; j++)
	{
		ptryTreeList[j].clear();
	}

	ptryTreeList[0].push_back(node->prty);

	if (node->hasChildren == 1)
	{
		Node2Level(node, 1);
	}
}

void Cprty_tree::Node2Level(Cprty_tree_node* node, int16 level)
{
	if (node->hasChildren == 1)
	{
		for (vector<Cprty_tree_node*>::iterator it = node->children.begin(); it != node->children.end();it++)
		{
			ptryTreeList[level].push_back((*it)->prty);
			level++;
			Node2Level((*it), level);
			level--;
		}
	}
}


