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

//定义功能模块
typedef struct PrmPrty
{
	int16		axisNum;					//轴号
	wstring		memberType;					//成员类型
	wstring		memberName;					//成员名字
	wstring		parent;						//父成员名字
	wstring     unit;						//单位
	wstring     introduction;				//介绍 中文名
	double		uplimit;					//上限
	double		downlimit;					//下限
	double		value;						//值
	int32		framAddr;					//fram地址 ，用于功能模块中写入和读取fram
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

	list<VARST>* PrmStList;			//存储参数
	
	list<VARST>* PrmStListParent;	//存储参数list中没有包含的父元素
	
	list<VARST>* PrmStListAll;		//list包含上面两部分
	
	list<PRMPRTY>* PrmPrtyList;		//存储参数属性的list结构,用于功能模块的扫描，因为功能模块不需要父节点。所以不需要找父节点的property

	void initPrm(void);
	int16 BuildPrmList(CBuildVarRelation* var, wstring& FPGAfilename, wstring& Auxfilename);
	void setRootProperty(void);
	void setAuxRootProperty(void);
	void setConstRootProperty(void);
	int16 GetPrmChildModule(void);
	int16 UpdatePrmFramAddrOfst(void);
	int16 UpdatePrmFramAddrOfstAxis(int16 sAxisNum);

	//用于存储参数模块名，小模块按照程序顺序
	list<VARST>* PrmStListChildModule;

	static const int16					MODULE_CASCADE_FILTER_MAX		= 10;			//滤波器级联最大为10级

	//定义各个大模块的起始地址。(short单位)
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

	//每个轴的超过32500的部分作为共用部分，就是那些不分轴的参数，因此共有32500--32767，和另一个轴的后部分作为共用
	static const int32					MODULE_COMMON_START_ADDR		= 32501;
	static const int32					MODULE_COMMON_END_ADDR			= 32767;

	//在user中开辟一片空间用于FPGA配置100,FPGA配置是针对单轴的。
	static const int32					MODULE_FPGA_START_ADDR			= 28672;
	static const int32					MODULE_FPGA_END_ADDR			= 28771;

	//在user中开辟一片空间用于LOG 200，针对单轴配置，前100个没怎么用，先预留作为辅助功能的总体参数，后100个作为log的参数
	//static const int32					MODULE_AUX_START_ADDR			= 28772;
	//static const int32					MODULE_AUX_END_ADDR				= 28971;

	//定义各个大模块中小模块的增量值
	static const int32					MODULE_CUR_STEP					= 100;
	static const int32					MODULE_SPD_STEP					= 100;
	static const int32					MODULE_POS_STEP					= 100;
	static const int32					MODULE_FPGA_STEP				= 100;
	static const int32					MODULE_AUX_STEP					= 100;
	static const int32					MODULE_OTHER_STEP				= 100;
	static const int32					MODULE_COMMOM_STEP				= 100;

	//另一个轴在铁电中的偏移
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


	//在user中开辟一片空间用于FPGA配置100,FPGA配置是针对单轴的。
	static const int32					MODULE_AXIS_FPGA_START_ADDR		= (MODULE_AXIS_OFFSET + MODULE_FPGA_START_ADDR);
	static const int32					MODULE_AXIS_FPGA_END_ADDR		= (MODULE_AXIS_OFFSET + MODULE_FPGA_END_ADDR);
	
	//在user中开辟一片空间用于 aux 共200,LOG，100配置是针对单轴的。
	//static const int32					MODULE_AXIS_AUX_START_ADDR		= (MODULE_AXIS_OFFSET + MODULE_AUX_START_ADDR);
	//static const int32					MODULE_AXIS_AUX_END_ADDR		= (MODULE_AXIS_OFFSET + MODULE_AUX_END_ADDR);

	list<VARST>* PrmStListAllAxis;

	int16 FindPrmLevelNum(int16 sAxisNum);
	int16 SplitPrmLevel(int16 level, CBuildVarRelation* var, int16 sAxisNum);

	//用于存储prmtree，axis是存取其它轴的
	list<VARST>* PrmStLevelList;
	list<VARST>** PrmStLevelListAxis;

	//存储参数属性的分层结构
	list<PRMPRTY>* PrmStLevelListPrty;    //建立辅助表格使用

	vector<wstring> ScanPrmFuncWord;

	//存储功能参数模块
	list<PRMPRTY>* PrmFuncList;			//建立功能模块表格使用

	int16 GetPrmFuncList(int16 level);

	int16 PrintPrmMacroDefine(wstring& fileName);

};
extern CBuildPrmRelation* g_buildPrmRelation;
#endif