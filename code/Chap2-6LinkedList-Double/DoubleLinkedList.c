#include "DoubleLinkedList.h"

DoubleLinkedList *CreateDoubleLinkedList(int n){
DoubleLinkedList *head,*p,*s; int i;
p=head=(DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
for(i=1;i<=n;i++){
    s=(DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
    scanf("%d",&s->data);
    s->prior=p;
    p->next=s;
    p=s;
}
p->next= head;head->prior = p;
return head;
}

int GetLen(DoubleLinkedList *head){
int i=0;DoubleLinkedList *p;
p=head->next;
while(p!=head){i++;p=p->next;}
return i;
}

int GetElem(DoubleLinkedList *head,int i,ElemType *e){
int j;DoubleLinkedList *p;
if(i<1) return 0;
p=head->next;j=1;
while(p!=head && j<i){
    p=p->next;j++;}
if(p==head) return 0;
*e=p->data;
return 1;
}

DoubleLinkedList *Locate(DoubleLinkedList *head,ElemType x){
DoubleLinkedList *p;
p=head->next;
while(p!=head && p->data !=x)
    p=p->next;
if(p==head) return NULL;
else return p;
}

DoubleLinkedList *GetElemP(DoubleLinkedList *head,int i){
DoubleLinkedList *p;int j;
if(i<1) return 0;
p=head->next;j=1;
while(p!=head && j<i){
    p=p->next;j++;}
if(p==head && j<i) return NULL;
return p;
}

int InsertElem(DoubleLinkedList *head,int i,ElemType e){
DoubleLinkedList *p,*q;int j;
if(i<1) return 0;// i的合法值为1≤i≤表长+1
p=head;j=0;
while(p->next!=head && j<i-1){
    //在L中确定第i-1个元素的位置指针p
    p=p->next;j++;
    }
if(p->next!=head || (p->next == head && j==i-1)){
    q=(DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
    q->data=e;
    q->next=p->next;
    q->prior=p;
    p->next->prior=q;
    p->next=q;
    return 1;
    }
else return 0;
}

int DeleteNode(DoubleLinkedList *head,int i,ElemType *e){
DoubleLinkedList *p;
if(i<1) return 0;
p=GetElemP(head,i); //在head中确定第i个结点的位置指针p
if(!p) return 0;    //第i个结点不存在
*e=p->data;
p->prior->next=p->next;
p->next->prior=p->prior;
free(p);
return 1;
}

void PrintList(DoubleLinkedList *head){
DoubleLinkedList *p;
p=head->next;
while(p!=head){
    printf("%4d",p->data);p=p->next;}
printf("\n");
p=head->prior;
while(p!=head){
    printf("%4d",p->data);p=p->prior;}
printf("\n");
}
