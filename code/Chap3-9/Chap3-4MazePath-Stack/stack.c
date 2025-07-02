#include "stack.h"

Status InitStack(SqStack *s){
s->base=(ElemType *)malloc(INITSIZE * sizeof(ElemType));
if (!s) return ERROR;
s->top=0;
s->stacksize=INITSIZE;
return OK;
}

int GetLen(SqStack *s){
return (s->top);
}

Status GetTop(SqStack *s,ElemType *e) { //ֻ����ȡ
if(s->top==0) return ERROR;
*e=s->base[s->top-1];
return OK;
}

Status Push(SqStack *s,ElemType e){
if(s->top >= s->stacksize) { //��ջ������������INCREMENTSIZE���洢��Ԫ
    s->base=(ElemType *)realloc(s->base,(s->stacksize+INCREMENTSIZE)*sizeof(ElemType));
    if(!s->base) return ERROR;
    s->stacksize+=INCREMENTSIZE;
}
s->base[s->top++]=e;
return OK;
}

Status Pop(SqStack *s,ElemType *e){
if(s->top==0) return ERROR;
*e=s->base[--s->top];
return OK;
}

int IsStackEmpty(SqStack *s){
    if(s->top == 0) return 1;
    else return 0;
}

//��ջ����ջ����һ��ӡԪ��,flagΪ1����ӡ�ַ��������ӡ������
void PrintStack(SqStack *s){
int i;
for(i=s->top-1;i>=0;i--){
    printf("%d(%d,%d) %d\n",s->base[i].ord,
           s->base[i].seat.r,s->base[i].seat.c,s->base[i].di);
}
}
