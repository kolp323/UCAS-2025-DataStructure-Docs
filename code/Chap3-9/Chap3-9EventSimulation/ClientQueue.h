#ifndef CLIENTQUEUE_H_INCLUDED
#define CLIENTQUEUE_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include "Common.h"

typedef struct{
    int ArrivalTime;
    int Duration;
}QElemType;

typedef struct Node {
    QElemType data;
    struct Node *next;
}QNode;

typedef struct {
    QNode *front;
    QNode *rear;
}LinkedQueue;

Status InitQueue(LinkedQueue *lq);
int GetLen(LinkedQueue *lq);
int IsQueueEmpty(LinkedQueue *lq);
Status GetFront(LinkedQueue *lq,QElemType *e);
Status Enqueue(LinkedQueue *lq,QElemType e);
Status Dequeue(LinkedQueue *lq,QElemType *e);
void PrintQueue(LinkedQueue *lq);


#endif // CLIENTQUEUE_H_INCLUDED
