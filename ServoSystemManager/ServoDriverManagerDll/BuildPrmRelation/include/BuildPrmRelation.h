//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	build prm relationship accoring to the var message			//
//	file				:	BuildPrmRelation.h											//
//	Description			:	use for build prm relationship								//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/1/20	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef __GTSD_BUILD_PRM_RELATION__
#define __GTSD_BUILD_PRM_RELATION__

//���幦��ģ��
typedef struct PrmPrty
{
	int16		axisNum;					//���
	wstring		memberType;					//��Ա����
	wstring		memberName;					//��Ա����
	wstring		parent;						//����Ա����
	wstring     unit;						//��λ
	wstring     introduction;				//���� ������
	double		uplimit;					//����
	double		downlimit;					//����
	double		value;						//ֵ
	int32		framAddr;					//fram��ַ �����ڹ���ģ����д��Ͷ�ȡfram
	bool operator==(const PrmPrty&);
}PRMPRTY;

class CBuildPrmRelation
{
public:
	CBuildPrmRelation();
	~CBuildPrmRelation();

	int16 PrmLevelNum;

	PRMPRTY constRootProperty;

	PRMPRTY rootProperty;
	PRMPRTY auxrootProperty;

	list<VARST>* PrmStList;			//�洢����
	
	list<VARST>* PrmStListParent;	//�洢����list��û�а����ĸ�Ԫ��
	
	list<VARST>* PrmStListAll;		//list��������������
	
	list<PRMPRTY>* PrmPrtyList;		//�洢�������Ե�list�ṹ,���ڹ���ģ���ɨ�裬��Ϊ����ģ�鲻��Ҫ���ڵ㡣���Բ���Ҫ�Ҹ��ڵ��property

	void initPrm(void);
	int16 BuildPrmList(CBuildVarRelation* var, wstring& FPGAfilename, wstring& Auxfilename);
	void setRootProperty(void);
	void setAuxRootProperty(void);
	void setConstRootProperty(void);
	int16 GetPrmChildModule(void);
	int16 UpdatePrmFramAddrOfst(void);
	int16 UpdatePrmFramAddrOfstAxis(int16 sAxisNum);

	//���ڴ洢����ģ������Сģ�鰴�ճ���˳��
	list<VARST>* PrmStListChildModule;

	static const int16					MODULE_CASCADE_FILTER_MAX		= 10;			//�˲����������Ϊ10��

	//���������ģ�����ʼ��ַ��(short��λ)
	//4k
	static const int32					MODULE_CUR_START_ADDR			= 0;
	static const int32					MODULE_CUR_END_ADDR				= 4095;

	//8k
	static const int32					MODULE_SPD_START_ADDR			= 4096;
	static const int32					MODULE_SPD_END_ADDR				= 12287;

	//12k
	static const int32					MODULE_POS_START_ADDR			= 12288;
	static const int32					MODULE_POS_END_ADDR				= 24575;

	//1k
	static const int32					MODULE_AUX_START_ADDR			= 24576;
	static const int32					MODULE_AUX_END_ADDR				= 25599;

	//3k
	static const int32					MODULE_OTHER_START_ADDR			= 25600;
	static const int32					MODULE_OTHER_END_ADDR			= 28671;

	//3.739k
	static const int32					MODULE_USER_START_ADDR			= 28672;
	static const int32					MODULE_USER_END_ADDR			= 32500;

	//ÿ����ĳ���32500�Ĳ�����Ϊ���ò��֣�������Щ������Ĳ�������˹���32500--32767������һ����ĺ󲿷���Ϊ����
	static const int32					MODULE_COMMON_START_ADDR		= 32501;
	static const int32					MODULE_COMMON_END_ADDR			= 32767;

	//��user�п���һƬ�ռ�����FPGA����100,FPGA��������Ե���ġ�
	static const int32					MODULE_FPGA_START_ADDR			= 28672;
	static const int32					MODULE_FPGA_END_ADDR			= 28771;

	//��user�п���һƬ�ռ�����LOG 200����Ե������ã�ǰ100��û��ô�ã���Ԥ����Ϊ�������ܵ������������100����Ϊlog�Ĳ���
	//static const int32					MODULE_AUX_START_ADDR			= 28772;
	//static const int32					MODULE_AUX_END_ADDR				= 28971;

	//���������ģ����Сģ�������ֵ
	static const int32					MODULE_CUR_STEP					= 100;
	static const int32					MODULE_SPD_STEP					= 100;
	static const int32					MODULE_POS_STEP					= 100;
	static const int32					MODULE_FPGA_STEP				= 100;
	static const int32					MODULE_AUX_STEP					= 100;
	static const int32					MODULE_OTHER_STEP				= 100;
	static const int32					MODULE_COMMOM_STEP				= 100;

	//��һ�����������е�ƫ��
	static const int32					MODULE_AXIS_OFFSET				= 32768;

	//8k
	static const int32					MODULE_AXIS_CUR_START_ADDR		= (MODULE_AXIS_OFFSET + MODULE_CUR_START_ADDR);
	static const int32					MODULE_AXIS_CUR_END_ADDR		= (MODULE_AXIS_OFFSET + MODULE_CUR_END_ADDR);

	//4k
	static const int32					MODULE_AXIS_SPD_START_ADDR		= (MODULE_AXIS_OFFSET + MODULE_SPD_START_ADDR);
	static const int32					MODULE_AXIS_SPD_END_ADDR		= (MODULE_AXIS_OFFSET + MODULE_SPD_END_ADDR);

	//12k
	static const int32					MODULE_AXIS_POS_START_ADDR		= (MODULE_AXIS_OFFSET + MODULE_POS_START_ADDR);
	static const int32					MODULE_AXIS_POS_END_ADDR		= (MODULE_AXIS_OFFSET + MODULE_POS_END_ADDR);

	//1k
	static const int32					MODULE_AXIS_AUX_START_ADDR		= (MODULE_AXIS_OFFSET + MODULE_AUX_START_ADDR);
	static const int32					MODULE_AXIS_AUX_END_ADDR		= (MODULE_AXIS_OFFSET + MODULE_AUX_END_ADDR);

	//3k
	static const int32					MODULE_AXIS_OTHER_START_ADDR	= (MODULE_AXIS_OFFSET + MODULE_OTHER_START_ADDR);
	static const int32					MODULE_AXIS_OTHER_END_ADDR		= (MODULE_AXIS_OFFSET + MODULE_OTHER_END_ADDR);

	//3.739k
	static const int32					MODULE_AXIS_USER_START_ADDR		= (MODULE_AXIS_OFFSET + MODULE_USER_START_ADDR);
	static const int32					MODULE_AXIS_USER_END_ADDR		= (MODULE_AXIS_OFFSET + MODULE_USER_END_ADDR);

	//common
	static const int32					MODULE_AXIS_COMMON_START_ADDR	= (MODULE_AXIS_OFFSET + MODULE_COMMON_START_ADDR);
	static const int32					MODULE_AXIS_COMMON_END_ADDR		= (MODULE_AXIS_OFFSET + MODULE_COMMON_END_ADDR);


	//��user�п���һƬ�ռ�����FPGA����100,FPGA��������Ե���ġ�
	static const int32					MODULE_AXIS_FPGA_START_ADDR		= (MODULE_AXIS_OFFSET + MODULE_FPGA_START_ADDR);
	static const int32					MODULE_AXIS_FPGA_END_ADDR		= (MODULE_AXIS_OFFSET + MODULE_FPGA_END_ADDR);
	
	//��user�п���һƬ�ռ����� aux ��200,LOG��100��������Ե���ġ�
	//static const int32					MODULE_AXIS_AUX_START_ADDR		= (MODULE_AXIS_OFFSET + MODULE_AUX_START_ADDR);
	//static const int32					MODULE_AXIS_AUX_END_ADDR		= (MODULE_AXIS_OFFSET + MODULE_AUX_END_ADDR);

	list<VARST>* PrmStListAllAxis;

	int16 FindPrmLevelNum(int16 sAxisNum);
	int16 SplitPrmLevel(int16 level, CBuildVarRelation* var, int16 sAxisNum);

	//���ڴ洢prmtree��axis�Ǵ�ȡ�������
	list<VARST>* PrmStLevelList;
	list<VARST>** PrmStLevelListAxis;

	//�洢�������Եķֲ�ṹ
	list<PRMPRTY>* PrmStLevelListPrty;    //�����������ʹ��

	vector<wstring> ScanPrmFuncWord;

	//�洢���ܲ���ģ��
	list<PRMPRTY>* PrmFuncList;			//��������ģ����ʹ��

	int16 GetPrmFuncList(int16 level);

	int16 PrintPrmMacroDefine(wstring& fileName);

};
extern CBuildPrmRelation* g_buildPrmRelation;
#endif