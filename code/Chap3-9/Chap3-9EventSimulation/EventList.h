#ifndef EVENTLIST_H_INCLUDED
#define EVENTLIST_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include "Common.h"

typedef struct {
int OccurTime;//事件发生时间
int NType; //0表示到达事件，1-4表示从4个业务窗口的离开事件
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
