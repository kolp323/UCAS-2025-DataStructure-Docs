#include "EventList.h"

LinkList *InitList(){
//建立带表头结点的单链表L
LinkList *L;
L = (LinkList *)malloc(sizeof(LNode));
if(!L) return NULL;
L->next = NULL;
return L;
}

int IsListEmpty(LinkList *L){
//空，返回 1
    if(!L->next) return 1;
    else return 0;
}

Status ListInsert_L(LinkList *L, int i, ElemType e) {
//在带头结点的单链表L的第i个元素之前插入元素e
LinkList *p, *s;
p = L; int j = 0;
while (p && j < i-1) {// 寻找第i-1个结点
	p = p->next; ++j; }
// i小于1(导致j>i-1成立)或者大于表长(导致p为NULL)
if (!p || j > i-1) return ERROR;
s = (LinkList *)malloc(sizeof(LNode)); // 生成新结点
s->data = e; s->next = p->next; // 插入L中
p->next = s;
return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList *L, int i, ElemType *e) {
//在带头结点的单链表L中删除第i个元素，并由e返回其值
LinkList *p,*q;
p = L; int j = 0;
while (p->next && j < i-1) {
	// 寻找第i个结点，并令p指向其前趋
	p = p->next; ++j;
	}
// i小于1(导致j>i-1成立)或者大于表长(导致p?next为NULL)
if (!(p->next) || j > i-1) return ERROR;
q = p->next; p->next = q->next; // 删除并释放结点
*e = q->data; free(q); return OK;
} // ListDelete_L


Status GetElem_L(LinkList *L,int i, ElemType *e) {
// L为带头结点的单链表的头指针
// 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
// 初始化，p指向第一个结点，j为计数器
LinkList *p;
 p = L->next; int j = 1;
while (p && j<i) {
      //顺指针向后查找，直到p指向第i个元素或p为空
      p = p->next; ++j; }
if ( !p || j>i ) return ERROR; // 第i个元素不存在
*e = p->data; // 取第i个元素
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



