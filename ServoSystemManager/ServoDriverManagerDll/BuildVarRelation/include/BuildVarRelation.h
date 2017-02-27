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
	int16   childNum;						//��һ���ӳ�Ա����
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
	int32 sev_chd_ofst;						//ƫ�ö��ǻ�����0��ƫ�á��������ƫ�þ�����0��ƫ�ü��������Ӧ��ƫ�á�
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

	VARST root;//��������
	VARST root_aux;

	list<VARST>* VarStList;//����var�ĳ�Ա����list
	int16 VarLevelNum;
	//��������
	void initVar(void);
	void SetRoot(void);
	void SetRootAux(void);
	void SetConstRoot(void);

	void FindChildNode(VARST& parent, int16& rt_childNum);
	bool CheckNode(VARST& node);
	void BuildVarList(void);									//��list��ʽ�洢tree�ĸ���Ԫ��

	int16 WriteFileForIarVarAddress(list<VARST>& member);
	int16 ChangeFormat(list<VARST>& list_c);

	AXIS_ADDR_OFST* axis_ofst;//ƫ�ƴ洢
	list<VARST>* VarStListAxis;//

	//��ȡiar���ɵĵ�ַ�ļ�
	int16 UpdateVarAddrOfst(wstring& filepath, list<VARST>& member, int16 sAxisNum);

	//�����������ƫ�ƣ��ŵ�VarStListAxis��
	int16 UpdateVarAddrOfstAxis(int16 sAxisNum);

	int16 FindVarLevelNum(int16 sAxisNum);
	int16 SplitVarLevel(int16 level, int16 sAxisNum);

	//���ڴ洢��״�ֲ��
	list<VARST>* VarStLevelList;
	list<VARST>** VarStLevelListAxis;


};
extern CBuildVarRelation* g_buildVarRelation;
#endif