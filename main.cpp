#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <iostream>
using namespace std;

//动态顺序表初始化
bool InitDynamicSqlist(DynamicSqlist &L)
{
	L.data = (Elemtype*)malloc(sizeof(Elemtype) * InitSize);
	if (L.data == NULL)
	{
		return false;
	}
	L.length = 0;
	L.Max = InitSize;
	return true;
}

//静态顺序表初始化
bool InitStaticSqlist(StaticSqlist& L)
{
	L.length = 0;
	return true;
}


//顺序表的插入
bool ListInsert(DynamicSqlist &L,int i, Elemtype e)
{
	if (i<1 || i>L.length + 1)
	{
		return false;
	}
	for (int n = L.length;n >= i;n--)
	{
		L.data[n] = L.data[n-1];
	}
	L.data[i - 1] = e;
	L.length += 1;
	return true;
}

//顺序表删除
bool ListDelete(DynamicSqlist& L, int i, Elemtype& e)
{
	if (L.length < 1)
	{
		return false;
	}
	e = L.data[i - 1];
	for (i;i < L.length;i++)
	{
		L.data[i - 1] = L.data[i];
	}
	L.length -= 1;
	return true;
}

//按值查找
int LocationElem(DynamicSqlist L, Elemtype e)
{
	for (int i = 0;i < L.length;i++)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}
	return -1;
}



//链表

//单链表
//初始化单链表，带头结点
bool InitLinkList_h(LinkList& L)	
{
	L = (LNode*)malloc(sizeof(LNode));	//分配头结点
	if (L == NULL)
	{
		return false;
	}
	L->next = NULL;//头结点之后暂时无节点
	return true;
}

//初始化单链表，不带头结点
bool InitLinkList(LinkList& L)
{
	L = NULL;//防止脏数据
	return true;
}

//这里有个很严重的问题，耽误了好久！！！！！当初始化一个链表或者节点之后，要将她的下一位赋值为null，例如L->next = null；防止脏数据出现形如  引发了异常: 读取访问权限冲突。 r 是 0xCDCDCDCD。
//尾插法建立单链表、
LinkList List_TailInsert(LinkList &L)
{
	LNode* r = L, * s;
	int i = 10;
	Elemtype x;
	while (i != 0)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = i;
		r->next = s;
		r = s;
		i++;
	}
	r->next = NULL;
	return L;
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList& L)
{
	LNode* s;
	Elemtype x;
	cin >> x;
	while (x != 999)
	{	
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}

//按序号查找节点值
LNode *GetElemBySequence(LinkList L, int i)
{
	int j = 1;
	LNode* r = L->next;
	if (i == 1)
	{
		return L;
	}
	else if (i < 1)
	{
		return NULL;
	}
	while (r && j < i)
	{
		r = r->next;
		j++;
	}
	return r;
}

//按值查找节点
LNode* GetElemByValue(LinkList L, Elemtype e)
{
	LNode* r = L->next;
	while (r && r->data != e)
	{
		r = r->next;
	}
	return r;
}

//插入节点
bool LinkListInsert(LinkList& L, int i, Elemtype e)
{	
	LNode* r, * s;
	s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	if (i < 0)
	{
		return false;
	}
	r = GetElemBySequence(L,i-1);
	s->next = r->next;
	r->next = s;
	return true;
}

//删除节点
bool LinkListDelete(LinkList& L, int i, Elemtype e)
{
	if (i < 0)
	{
		return false;
	}
	LNode* r;
	r = GetElemBySequence(L, i - 1);


}





int main()
{
	LinkList L;
	InitLinkList_h(L);
	LNode* r, * s, * out,*out1;
	int i = 10;

	s = L;
	while (i != 0)
	{	
		r = (LNode*)malloc(sizeof(LNode));
		r->data = i;
		s->next = r;
		s = r;
		i--;
	}
	s->next = NULL;


	cout << endl;
	LinkListInsert(L, 3, 3);
	out = L->next;
	while (out)
	{

		cout << out->data << ' ';
		out = out->next;
	}

	//out1 = GetElemByValue(L, 3);
	//cout << out1->data;
	return 1;
}
