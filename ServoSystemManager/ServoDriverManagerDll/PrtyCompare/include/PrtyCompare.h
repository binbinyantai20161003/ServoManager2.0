//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	read the prty file to build the list of tree				//
//	file				:	PrtyTree.h													//
//	Description			:	use for operate the prty									//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/1/20	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef __GTSD_PRTY_TREE__
#define __GTSD_PRTY_TREE__

#include "Basetype_def.h"
//存储结构
typedef struct CPRTY_TREE_NODE
{
	int16							hasChildren;
	int16							childNumber;
	int16							treelevel;
	CPRTY_TREE_NODE*				parent;
	PRMPRTY							prty;
	vector<CPRTY_TREE_NODE*>        children;
}Cprty_tree_node;

class Cprty_tree
{
public:
	Cprty_tree();
	~Cprty_tree(void);
	
	vector<Cprty_tree_node*>* vector_prty_tree_node;
	stack<Cprty_tree_node*>* stack_prty_tree;

	//新特性表的tree 根node
	Cprty_tree_node* node;
	//旧特性表的tree 根node
	Cprty_tree_node* old_node;

	//分层用
	list<PRMPRTY>* ptryTreeList;

	void initVar(int16 level);
	void UpdateNewTree(void);
	void CopyTreeItem(Cprty_tree_node* newnode, Cprty_tree_node* oldnode);
	int16 findTreeElement(vector<wstring>& vec, int16 level, Cprty_tree_node* node, Cprty_tree_node** element);
	void DeleteTree(Cprty_tree_node** pnode);

	void splitTreeNode2Level(int16 level);
	void Node2Level(Cprty_tree_node* node, int16 level);
};
extern Cprty_tree* g_prty_tree;
#endif