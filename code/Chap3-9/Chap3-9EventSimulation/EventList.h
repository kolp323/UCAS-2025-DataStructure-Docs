#ifndef EVENTLIST_H_INCLUDED
#define EVENTLIST_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include "Common.h"

typedef struct {
int OccurTime;//�¼�����ʱ��
int NType; //0��ʾ�����¼���1-4��ʾ��4��ҵ�񴰿ڵ��뿪�¼�
} Event,ElemType;

typedef  struct  LNode {
 	ElemType  data;
	struct   LNode  *next;
} LNode, LinkList;

typedef LinkList EventList;

LinkList *InitList();
int IsListEmpty(LinkList *L);
Status ListInsert_L(LinkList *L, int i, ElemType e);
Status ListDelete_L(LinkList *L, int i, ElemType *e);
Status GetElem_L(LinkList *L,int i, ElemType *e);
void ListPrint(LinkList *L);


#endif // EVENTLIST_H_INCLUDED
