#include "SqStack.h"

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

Status GetTop(SqStack *s,ElemType *e) { //只看不取
if(s->top==0) return ERROR;
*e=s->base[s->top-1];
return OK;
}

Status Push(SqStack *s,ElemType e){
if(s->top >= s->stacksize) { //若栈已满，则增加INCREMENTSIZE个存储单元
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

Status StackTraverse(SqStack *s, void visit(ElemType *e))
{ //从栈顶到栈底逐一打印元素
int i;
if(s->top==0) return ERROR;
for(i=s->top-1;i>=0;i--)
    visit(&s->base[i]);
return OK;
}

#define TYPE_OF(x) _Generic((x), int: "int", float: "float", char: "char", default: "other")
void PrintStack(SqStack *s){ //从栈顶到栈底逐一打印元素
int i;
for(i=s->top-1;i>=0;i--){
    if (strcmp(TYPE_OF(s->base[i]),"int")==0)
        printf("%d",s->base[i]);
    if (strcmp(TYPE_OF(s->base[i]),"char")==0)
        printf("%c",s->base[i]);
    }
printf("\n");
}

