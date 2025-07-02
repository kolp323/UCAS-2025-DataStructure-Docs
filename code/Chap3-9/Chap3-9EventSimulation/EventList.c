#include "EventList.h"

LinkList *InitList(){
//��������ͷ���ĵ�����L
LinkList *L;
L = (LinkList *)malloc(sizeof(LNode));
if(!L) return NULL;
L->next = NULL;
return L;
}

int IsListEmpty(LinkList *L){
//�գ����� 1
    if(!L->next) return 1;
    else return 0;
}

Status ListInsert_L(LinkList *L, int i, ElemType e) {
//�ڴ�ͷ���ĵ�����L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
LinkList *p, *s;
p = L; int j = 0;
while (p && j < i-1) {// Ѱ�ҵ�i-1�����
	p = p->next; ++j; }
// iС��1(����j>i-1����)���ߴ��ڱ�(����pΪNULL)
if (!p || j > i-1) return ERROR;
s = (LinkList *)malloc(sizeof(LNode)); // �����½��
s->data = e; s->next = p->next; // ����L��
p->next = s;
return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList *L, int i, ElemType *e) {
//�ڴ�ͷ���ĵ�����L��ɾ����i��Ԫ�أ�����e������ֵ
LinkList *p,*q;
p = L; int j = 0;
while (p->next && j < i-1) {
	// Ѱ�ҵ�i����㣬����pָ����ǰ��
	p = p->next; ++j;
	}
// iС��1(����j>i-1����)���ߴ��ڱ�(����p?nextΪNULL)
if (!(p->next) || j > i-1) return ERROR;
q = p->next; p->next = q->next; // ɾ�����ͷŽ��
*e = q->data; free(q); return OK;
} // ListDelete_L


Status GetElem_L(LinkList *L,int i, ElemType *e) {
// LΪ��ͷ���ĵ������ͷָ��
// ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
// ��ʼ����pָ���һ����㣬jΪ������
LinkList *p;
 p = L->next; int j = 1;
while (p && j<i) {
      //˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
      p = p->next; ++j; }
if ( !p || j>i ) return ERROR; // ��i��Ԫ�ز�����
*e = p->data; // ȡ��i��Ԫ��
return OK;
} // GetElem_L

void ListPrint(LinkList *L){
/*
LinkList *p;p=L->next;
printf("Print Event List\n");
while(p){
    printf("%d,%d\n",p->data.OccurTime,p->data.NType);
    p=p->next;
 }
*/
}



