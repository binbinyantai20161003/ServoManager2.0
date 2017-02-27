//////////////////////////////////////////////////////////////////////////////////////////
//	summary				:	xml process													//
//	file				:	xml.h														//
//	Description			:	use for read and write xml file								//
//	lib					:	none														//
//																						//
//======================================================================================//
//		programmer:		|	date:		|	Corporation:	|		copyright(C):		//
//--------------------------------------------------------------------------------------//
//		wang.bin(1420)  |	2016/1/20	|	googoltech		|		2016 - 2019			//
//--------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef __GTSD_XML__
#define	__GTSD_XML__	

#include "tinystr.h"
#include "tinyxml.h"

class GTSD_XML
{
public:
	GTSD_XML();
	~GTSD_XML(void);

	//�洢��״xml�Ľڵ�
	vector<vector<TiXmlElement*>*>* VVectorTreeElement;
	vector<TiXmlElement*>* VecTreeElement;

	//����ģ�壬���ҵ������
	TiXmlElement* loadTemplate(wstring& filePath, TiXmlDocument* myDoc);
	void findTemplateChild(TiXmlElement* parentnode);
	TiXmlElement* templateEle;
	//����fpag����xml��������ϲ�������fram����
	void loadFpgaConfig(wstring& filePath,list<VARST>* fpgaList);
	void findFpgaChild(TiXmlElement* parentnode, list<VARST>* fpgaList);

	//����var �� prm �����ļ���Ϊ�߼�����ʹ�á�
	void writeColumn(TiXmlElement* elet, string st);
	void writeblock(TiXmlElement* elet, string st);
	void saveTree(wstring& filepathT, wstring& filepath, list<VARST>* vlist, int16 treelevel);
	TiXmlElement* createElement(TiXmlElement* parentelement, string elename, list<VARST>::iterator it);

	//���ɻ�ͼ����ѡ����ļ����������Ӧһ���ļ�
	void savePlotRamTree(wstring& filepathT, wstring& filepath, list<VARST>* vlist, list<VARST>** vlistaxis, int16 treelevel, int16 DspAxisNum, int16 devAxisNum);

	//����fram��Ҫ�Ĳ����ļ��������Ӧһ���ļ�
	void saveFramPrmTree(wstring& filepathT, wstring& filepath, list<VARST>* vlist, list<VARST>** vlistaxis, int16 treelevel, int16 DspAxisNum, int16 devAxisNum);
	TiXmlElement* createFramPrmElement(TiXmlElement* parentelement, string elename, list<VARST>::iterator it);

	//�����������
	void savePrtyTree(wstring& filepathT, wstring& filepath, list<PRMPRTY>* vlist, int16 treelevel);
	TiXmlElement* createPrtyElement(TiXmlElement* parentelement, string elename, list<PRMPRTY>::iterator it);

	//�������ܱ��
	void saveFuncPrty(wstring& filepathT, wstring& filepath, list<PRMPRTY>* vlist);
	TiXmlElement* createFuncPrtyElement(TiXmlElement* parentelement, string elename, list<PRMPRTY>::iterator it);

	//���ع��ܱ��
	void loadPrtyTree(wstring& filePath, Cprty_tree_node** node);
	void findPrtyTreeChild(TiXmlElement* parentnode, int16 levelNum, Cprty_tree_node** tree_node=NULL);

	//��ȡ�������
	void loadPrmTree(wstring& filePath,Cprm_tree_node** node);
	void findPrmTreeChild(TiXmlElement* parentnode, int16 levelNum, Cprm_tree_node** tree_node = NULL);

	void saveFramPrmTreeAll(wstring& filepathT, wstring& filepath, list<PRM_FILE>* vlist, Cprm_tree_node** tree_node, int16 axisNum);
	void WritePrmChild(Cprm_tree_node* node, TiXmlElement* parent);
	TiXmlElement* createFramPrmAllElement(TiXmlElement* parentelement, string elename, PRM_FILE& it);
};

extern GTSD_XML* g_xml;
#endif