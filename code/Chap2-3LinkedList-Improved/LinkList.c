#include "LinkList.h"

Link *MakeNode(ElemType e){
Link *p;
// 分配由 p 指向的值为e的结点，并返回OK；
// 若分配失败，则返回 ERROR
p=(Link *)malloc(sizeof(struct LNode));
if(!p) return NULL;
p->data=e;
p->next=NULL;
return p;
}

void   FreeNode(Link *p) {
free(p);
}

LinkList *InitList(){
LinkList *L;
Link *p;
	L=(LinkList *)malloc(sizeof(LinkList));
	if (!L) return NULL;
	L->len=0;
	p=(Link *)malloc(sizeof(struct LNode));
	if(!p) return NULL;
	p->next=NULL;
	L->head=L->tail=p;
	return L;
}

Link *LocatePos(LinkList *L, int i){ //使得p指向L的第i个结点，并返回p
Link *cur; int j=1;
cur=L->head;
while(cur && j<=i) { //寻找第i个结点
 cur=cur->next; j++;
}
if (!cur) return NULL;
return cur;
}

Status InsAfter(LinkList *L,Link *h, Link *s){ //将s所指结点插入在L的p所指结点之后
if (!L->head)  return ERROR;
L->len++;
if (L->tail==h)L->tail=s;
s->next=h->next;
h->next=s;
return OK;
}

Status ListInsert_L(LinkList *L, int i, ElemType e){
Link *h,*s;
h=LocatePos(L,i-1);
if(!h) return ERROR; // i值不合法
s=MakeNode(e);
if (!s) return ERROR; // 结点存储分配失败
// 对于从第i结点开始的链表，第i-1结点是它的头结点，将s插入在h之后
if (!InsAfter(L, h, s)) return OK;
return ERROR;
}

Status GetElem_L(LinkList *L,int i, ElemType *e) {
// L为改进的单链表的指针，当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
// 初始化，p指向第一个头结点，j为计数器
struct LNode *p;  p = L->head->next;
int j = 1;
while (p && j<i) {//顺指针向后查找，直到p指向第i个元素或p为空
      p = p->next; ++j;
      }
if ( !p || j>i ) return ERROR; // 第i个元素不存在
*e = p->data; // 取第i个元素
return OK;
} // GetElem_L
