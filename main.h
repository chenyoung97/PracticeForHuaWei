typedef int Elemtype;

#define MaxSize 50
#define InitSize 10


//结构体

//静态分配线性表
typedef struct {
	Elemtype data[MaxSize];
	int length;
}StaticSqlist;

//动态分配线性表
typedef struct {
	Elemtype* data;
	int Max, length;
}DynamicSqlist;

//单链表
typedef struct LNode {
	Elemtype data;
	struct LNode* next;
}LNode, * LinkList;

//双链表
typedef struct DNode {
	Elemtype data;
	struct DNode* prior, * next;
}DNode,*DLinkList;



//操作函数

//顺序表
//静态顺序表初始化
bool InitStaticSqlist(StaticSqlist& L);

//动态顺序表初始化
bool InitDynamicSqlist(DynamicSqlist& L);

//列表插入
bool ListInsert(DynamicSqlist& L, int i, Elemtype e);

//顺序表删除
bool ListDelete(DynamicSqlist& L, int i, Elemtype& e);

//按值查找
int LocationElem(DynamicSqlist L, Elemtype e);
