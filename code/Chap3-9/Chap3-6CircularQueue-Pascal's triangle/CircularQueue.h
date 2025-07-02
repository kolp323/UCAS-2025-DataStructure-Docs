#ifndef CIRCULARQUEUE_H_INCLUDED
#define CIRCULARQUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define MAXQUEUESIZE 100
typedef int Status;
typedef int ElemType;
typedef struct {
ElemType *base;
int front;
int rear;
} CircularQueue;

Status InitQueue(CircularQueue *cq);
int GetLen(CircularQueue *cq);
int IsQueueEmpty(CircularQueue *cq);
Status GetFront(CircularQueue *cq,ElemType *e);
Status Enqueue(CircularQueue *cq,ElemType e);
Status Dequeue(CircularQueue *cq,ElemType *e);
void PrintQueue(CircularQueue *cq);

#endif // CIRCULARQUEUE_H_INCLUDED
