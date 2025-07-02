#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define INITSIZE 100
#define INCREMENTSIZE 10  //ջ�ռ��������
#define OK 1
#define ERROR 0

typedef int Status;

//1. ����ת��
//typedef int ElemType;
//2. ����ƥ��
typedef char ElemType;

typedef struct {
    int top; //ջ��
    ElemType *base;
    int stacksize;
}SqStack; // ��̬˳��ջ

Status InitStack(SqStack *s);
int GetLen(SqStack *s);
Status GetTop(SqStack *s,ElemType *e);
Status Push(SqStack *s,ElemType e);
Status Pop(SqStack *s,ElemType *e);
int IsStackEmpty(SqStack *s);
Status StackTraverse(SqStack *s, void visit(ElemType *e));
void PrintStack(SqStack *s);

#endif // SQSTACK_H_INCLUDED
