#include "LinkList.h"

Link *MakeNode(ElemType e){
Link *p;
// ������ p ָ���ֵΪe�Ľ�㣬������OK��
// ������ʧ�ܣ��򷵻� ERROR
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

Link *LocatePos(LinkList *L, int i){ //ʹ��pָ��L�ĵ�i����㣬������p
Link *cur; int j=1;
cur=L->head;
while(cur && j<=i) { //Ѱ�ҵ�i�����
 cur=cur->next; j++;
}
if (!cur) return NULL;
return cur;
}

Status InsAfter(LinkList *L,Link *h, Link *s){ //��s��ָ��������L��p��ָ���֮��
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
if(!h) return ERROR; // iֵ���Ϸ�
s=MakeNode(e);
if (!s) return ERROR; // ���洢����ʧ��
// ���ڴӵ�i��㿪ʼ��������i-1���������ͷ��㣬��s������h֮��
if (!InsAfter(L, h, s)) return OK;
return ERROR;
}

Status GetElem_L(LinkList *L,int i, ElemType *e) {
// LΪ�Ľ��ĵ������ָ�룬����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
// ��ʼ����pָ���һ��ͷ��㣬jΪ������
struct LNode *p;  p = L->head->next;
int j = 1;
while (p && j<i) {//˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
      p = p->next; ++j;
      }
if ( !p || j>i ) return ERROR; // ��i��Ԫ�ز�����
*e = p->data; // ȡ��i��Ԫ��
return OK;
} // GetElem_L
