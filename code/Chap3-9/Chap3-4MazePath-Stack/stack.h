#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <malloc.h>
#include <stdio.h>

#define INITSIZE 100
#define INCREMENTSIZE 10  //ջ�ռ��������
#define OK 1
#define ERROR 0
typedef int Status;

typedef struct{ //�Թ�������
    int r,c; //r ��ʾ�У�c��ʾ��
}PosType;

typedef struct{  //��ʾ·���е�һͨ����
    int ord;     //��ʾ��ͨ������·���ϵ����
    PosType seat;//ͨ�������Թ��е�����λ��
    int di;     //�Ӵ�ͨ����������һ��ͨ����ķ���
} ElemType;

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
void PrintStack(SqStack *s);

#endif // STACK_H_INCLUDED
