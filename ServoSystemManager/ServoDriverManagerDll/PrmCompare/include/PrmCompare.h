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

#ifndef __GTSD_PRM_COMPARE__
#define __GTSD_PRM_COMPARE__

//定义参数文件中的属性

typedef struct prm_file 
{
	wstring memberType;
	wstring memberName;
	wstring	value;
	int32	addressOffset;      

}PRM_FILE;

//定义节点
typedef struct CPRM_TREE_NODE
{
	//存储结构
	int16							hasChildren;
	int16							childNumber;
	int16							treelevel;
	CPRM_TREE_NODE*					parent;
	PRM_FILE						prmFile;
	vector<CPRM_TREE_NODE*>         children;

}Cprm_tree_node;

//定义树操作类

class Cprm_tree
{
public:
	Cprm_tree();
	~Cprm_tree(void);

	vector<Cprm_tree_node*>* vector_prmFile_tree_node ;
	stack<Cprm_tree_node*>* stack_prmFile_tree ;

	//新电机参数表的tree 根node
	Cprm_tree_node* prmFile_node ;

	//旧电机参数表的tree 根node
	Cprm_tree_node* prmFile_old_node ;

	//分层用
	list<PRM_FILE>* prmFile_TreeList ;

	void initVar(int16 level);
	void UpdateNewPrmFileTree(void);
	void CopyPrmFileTreeItem(Cprm_tree_node* newnode, Cprm_tree_node* oldnode);
	void DeletePrmFileTree(Cprm_tree_node** pnode);

	void splitPrmFileTreeNode2Level(int16 level);
	void PrmFileNode2Level(Cprm_tree_node* node, int16 level);
	
};

extern Cprm_tree* g_prm_tree;
#endif