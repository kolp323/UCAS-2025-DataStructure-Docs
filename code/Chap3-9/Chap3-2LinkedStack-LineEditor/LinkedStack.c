#include "LinkedStack.h"

LinkedStack *InitStack(void){ //创建一个带头结点的空栈
LinkedStack *s;
s=(LinkedStack *)malloc(sizeof(LinkedStack));
s->next=NULL;
return s;
}

int GetLen(LinkedStack *s){
int i=0; LinkedStack *p; p=s->next;
while(p){
    i++;p =p->next;
    }
return i;
}

Status GetTop(LinkedStack *s,ElemType *e){
if(s->next==NULL) return ERROR;
*e=s->next->data;
return OK;
}

Status Push(LinkedStack *s,ElemType e){
LinkedStack *p;
p=(LinkedStack *)malloc(sizeof(LinkedStack));
if(!p) return ERROR;
p->data = e;
p->next=s->next; //新结点插入到头结点之后
s->next=p;
return OK;
}

Status Pop(LinkedStack *s,ElemType *e){
LinkedStack *p;
if(!s->next) return ERROR;
p=s->next;
*e=p->data;
s->next=p->next;
free(p);
return OK;
}

int IsStackEmpty(LinkedStack *s){
if(!s->next) return 1;
else return 0;
}

void PrintStack(LinkedStack *s){
LinkedStack *t,*p;
ElemType e;
int i,j;i=GetLen(s);j=1;
t=InitStack();
while(j<=i){
    Pop(s,&e);Push(t,e);j++;}
p=t->next;
while(p!=NULL) {
    printf("%c",p->data); //与ElemType相关
    p=p->next;
    }
printf("\n");
}

void ClearStack(LinkedStack *s){
LinkedStack *p,*q;
    if(!s->next) return;
    q=s->next;
    while(q){
        p=q;q=q->next;free(p);}
    s->next=NULL;
    return;
}
