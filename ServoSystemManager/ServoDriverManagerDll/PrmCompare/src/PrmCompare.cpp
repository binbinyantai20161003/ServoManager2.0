//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	read the PRM file to compare and update the file 			//
//	file				:	PrtyTree.h													//
//	Description			:	use for compare and update the prm file						//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/1/20	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <stack>
using namespace std;
#include "BuildVarRelation.h"
#include "ParseFile.h"
#include "StringHandler.h"
#include "BuildPrmRelation.h"
#include "PrtyCompare.h"
#include "PrmCompare.h"

Cprm_tree* g_prm_tree = NULL;

Cprm_tree::Cprm_tree()
{
	vector_prmFile_tree_node		= new vector < Cprm_tree_node* > ;
	stack_prmFile_tree				= new stack < Cprm_tree_node* > ;
	prmFile_node					= new Cprm_tree_node;
	prmFile_old_node				= new Cprm_tree_node;

}

Cprm_tree::~Cprm_tree(void)
{
	delete vector_prmFile_tree_node;			vector_prmFile_tree_node = NULL;
	delete stack_prmFile_tree;					stack_prmFile_tree = NULL;

	DeletePrmFileTree(&prmFile_old_node);
	DeletePrmFileTree(&prmFile_node);

	delete[] prmFile_TreeList;					prmFile_TreeList = NULL;
}

void Cprm_tree::DeletePrmFileTree(Cprm_tree_node** pnode)
{
	if ((*pnode) == NULL)
		return;
	if ((*pnode)->hasChildren)
	{
		for (vector<Cprm_tree_node*>::iterator it = (*pnode)->children.begin(); it != (*pnode)->children.end(); it++)
		{
			DeletePrmFileTree(&(*it));
		}
	}
	delete (*pnode);
	(*pnode) = NULL;
	return;
}

void Cprm_tree::initVar( int16 level )
{
	prmFile_TreeList = new list<PRM_FILE>[level+1];
}

void Cprm_tree::UpdateNewPrmFileTree(void)
{
	//首先判断根node是否一致。不一致直接退出
	if (prmFile_old_node->prmFile.memberName == prmFile_node->prmFile.memberName)
	{
		prmFile_node->prmFile.value = prmFile_old_node->prmFile.value;

		CopyPrmFileTreeItem(prmFile_node, prmFile_old_node);
	}
	else
	{
		return;
	}
}

//////////////////////////////////////////////////////////////////////////
//内部迭代复制旧的信息到新的信息。
//////////////////////////////////////////////////////////////////////////
void Cprm_tree::CopyPrmFileTreeItem(Cprm_tree_node* newnode, Cprm_tree_node* oldnode)
{
	//假如新的有child
	if ((newnode->hasChildren))
	{
		for (vector<Cprm_tree_node*>::iterator it_new = newnode->children.begin(); newnode->children.end() != it_new; it_new++)
		{
			//假如旧的有chilld
			if (oldnode->hasChildren)
			{
				//在旧的中找是否有和新的中匹配的，如果匹配就复制
				for (vector<Cprm_tree_node*>::iterator it_old = oldnode->children.begin(); oldnode->children.end() != it_old; it_old++)
				{
					if ((*it_old)->prmFile.memberName == (*it_new)->prmFile.memberName)
					{
						(*it_new)->prmFile.value = (*it_old)->prmFile.value;
						//在旧的中找到新的值，那么就进入其下一层
						CopyPrmFileTreeItem((*it_new), (*it_old));
					}
				}
			}

		}
	}
}

void Cprm_tree::splitPrmFileTreeNode2Level(int16 level)
{
	for (int32 j = 0; j < level; j++)
	{
		prmFile_TreeList[j].clear();
	}

	prmFile_TreeList[0].push_back(prmFile_node->prmFile);

	if (prmFile_node->hasChildren == 1)
	{
		PrmFileNode2Level(prmFile_node, 1);
	}
}

void Cprm_tree::PrmFileNode2Level(Cprm_tree_node* node, int16 level)
{
	if (node->hasChildren == 1)
	{
		for (vector<Cprm_tree_node*>::iterator it = node->children.begin(); it != node->children.end(); it++)
		{
			prmFile_TreeList[level].push_back((*it)->prmFile);
			level++;
			PrmFileNode2Level((*it), level);
			level--;
		}
	}
}







