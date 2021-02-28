#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <iostream>
using namespace std;

//��̬˳����ʼ��
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

//��̬˳����ʼ��
bool InitStaticSqlist(StaticSqlist& L)
{
	L.length = 0;
	return true;
}


//˳���Ĳ���
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

//˳���ɾ��
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

//��ֵ����
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



//����

//������
//��ʼ����������ͷ���
bool InitLinkList_h(LinkList& L)	
{
	L = (LNode*)malloc(sizeof(LNode));	//����ͷ���
	if (L == NULL)
	{
		return false;
	}
	L->next = NULL;//ͷ���֮����ʱ�޽ڵ�
	return true;
}

//��ʼ������������ͷ���
bool InitLinkList(LinkList& L)
{
	L = NULL;//��ֹ������
	return true;
}

//�����и������ص����⣬�����˺þã�������������ʼ��һ��������߽ڵ�֮��Ҫ��������һλ��ֵΪnull������L->next = null����ֹ�����ݳ�������  �������쳣: ��ȡ����Ȩ�޳�ͻ�� r �� 0xCDCDCDCD��
//β�巨����������
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

//ͷ�巨����������
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

//����Ų��ҽڵ�ֵ
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

//��ֵ���ҽڵ�
LNode* GetElemByValue(LinkList L, Elemtype e)
{
	LNode* r = L->next;
	while (r && r->data != e)
	{
		r = r->next;
	}
	return r;
}

//����ڵ�
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

//ɾ���ڵ�
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
