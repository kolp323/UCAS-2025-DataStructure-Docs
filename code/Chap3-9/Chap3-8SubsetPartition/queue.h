#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
}QNode;

typedef struct {
    QNode *front;
    QNode *rear;
}LinkedQueue;

Status InitQueue(LinkedQueue *lq);
int GetLen(LinkedQueue *lq);
int IsQueueEmpty(LinkedQueue *lq);
Status GetFront(LinkedQueue *lq,ElemType *e);
Status Enqueue(LinkedQueue *lq,ElemType e);
Status Dequeue(LinkedQueue *lq,ElemType *e);
void PrintQueue(LinkedQueue *lq);
