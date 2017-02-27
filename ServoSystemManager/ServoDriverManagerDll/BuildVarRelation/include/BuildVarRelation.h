//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	build var relationship accoring to the parsed file message	//
//	file				:	BuildVarRelation.h											//
//	Description			:	use for build var relationship								//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/1/20	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef  __GTSD_BUILD_VAR_RELATION__
#define  __GTSD_BUILD_VAR_RELATION__

#include "Basetype_def.h"
//////////////////////////////////////////////////////////////////////////
typedef struct varSt
{
	int16   axisNum;
	wstring memberType;
	wstring memberName;
	wstring parent;
	bool	hasChild;                       //whether the node has child
	int16   childNum;						//下一层子成员个数
	bool	isBits;                         //is bit or not 
	int16   bitStart;						//bit start bit
	int16	bitWidth;                       //bit width
	int32	addressOffset;                  //if the node has child ,then the node has no address
	wstring value;
}VARST;

//////////////////////////////////////////////////////////////////////////
typedef struct axis_addr_ofst
{
	int16 axis;
	int32 sev_chd_ofst;						//偏置都是基于轴0的偏置。其它轴的偏置就是轴0的偏置加上这里对应的偏置。
	int32 sev_task_ofst;
	int32 sev_obj_ofst;
	int32 aux_prm;
	int32 aux_log;
}AXIS_ADDR_OFST;

//////////////////////////////////////////////////////////////////////////


class CBuildVarRelation
{
public:
	CBuildVarRelation();
	~CBuildVarRelation();
	
	VARST constRoot;

	VARST root;//定义根结点
	VARST root_aux;

	list<VARST>* VarStList;//定义var的成员变量list
	int16 VarLevelNum;
	//函数声明
	void initVar(void);
	void SetRoot(void);
	void SetRootAux(void);
	void SetConstRoot(void);

	void FindChildNode(VARST& parent, int16& rt_childNum);
	bool CheckNode(VARST& node);
	void BuildVarList(void);									//以list形式存储tree的各个元素

	int16 WriteFileForIarVarAddress(list<VARST>& member);
	int16 ChangeFormat(list<VARST>& list_c);

	AXIS_ADDR_OFST* axis_ofst;//偏移存储
	list<VARST>* VarStListAxis;//

	//读取iar生成的地址文件
	int16 UpdateVarAddrOfst(wstring& filepath, list<VARST>& member, int16 sAxisNum);

	//计算其它轴的偏移，放到VarStListAxis中
	int16 UpdateVarAddrOfstAxis(int16 sAxisNum);

	int16 FindVarLevelNum(int16 sAxisNum);
	int16 SplitVarLevel(int16 level, int16 sAxisNum);

	//用于存储树状分层的
	list<VARST>* VarStLevelList;
	list<VARST>** VarStLevelListAxis;


};
extern CBuildVarRelation* g_buildVarRelation;
#endif