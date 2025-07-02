#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

#include <stdio.h>
#include <malloc.h>

#define INITSIZE 100
#define INCREMENTSIZE 10  //栈空间分配增量
#define OK 1
#define ERROR 0
typedef int Status;
typedef char ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
}LinkedStack;

LinkedStack *InitStack(void);
int GetLen(LinkedStack *s);
Status GetTop(LinkedStack *s,ElemType *e);
Status Push(LinkedStack *s,ElemType e);
Status Pop(LinkedStack *s,ElemType *e);
int IsStackEmpty(LinkedStack *s);
void PrintStack(LinkedStack *s);
void ClearStack(LinkedStack *s);

#endif // LINKEDSTACK_H_INCLUDED
