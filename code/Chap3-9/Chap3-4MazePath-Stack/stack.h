#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <malloc.h>
#include <stdio.h>

#define INITSIZE 100
#define INCREMENTSIZE 10  //栈空间分配增量
#define OK 1
#define ERROR 0
typedef int Status;

typedef struct{ //迷宫的坐标
    int r,c; //r 表示行，c表示列
}PosType;

typedef struct{  //表示路径中的一通道块
    int ord;     //表示该通道块在路径上的序号
    PosType seat;//通道块在迷宫中的坐标位置
    int di;     //从此通道块走向下一个通道块的方向
} ElemType;

typedef struct {
    int top; //栈顶
    ElemType *base;
    int stacksize;
}SqStack; // 动态顺序栈

Status InitStack(SqStack *s);
int GetLen(SqStack *s);
Status GetTop(SqStack *s,ElemType *e);
Status Push(SqStack *s,ElemType e);
Status Pop(SqStack *s,ElemType *e);
int IsStackEmpty(SqStack *s);
void PrintStack(SqStack *s);

#endif // STACK_H_INCLUDED
