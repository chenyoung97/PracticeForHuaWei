typedef int Elemtype;

#define MaxSize 50
#define InitSize 10


//�ṹ��

//��̬�������Ա�
typedef struct {
	Elemtype data[MaxSize];
	int length;
}StaticSqlist;

//��̬�������Ա�
typedef struct {
	Elemtype* data;
	int Max, length;
}DynamicSqlist;

//������
typedef struct LNode {
	Elemtype data;
	struct LNode* next;
}LNode, * LinkList;

//˫����
typedef struct DNode {
	Elemtype data;
	struct DNode* prior, * next;
}DNode,*DLinkList;



//��������

//˳���
//��̬˳����ʼ��
bool InitStaticSqlist(StaticSqlist& L);

//��̬˳����ʼ��
bool InitDynamicSqlist(DynamicSqlist& L);

//�б����
bool ListInsert(DynamicSqlist& L, int i, Elemtype e);

//˳���ɾ��
bool ListDelete(DynamicSqlist& L, int i, Elemtype& e);

//��ֵ����
int LocationElem(DynamicSqlist L, Elemtype e);
