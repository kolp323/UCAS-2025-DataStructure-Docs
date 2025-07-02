#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
typedef int Status;

typedef struct{ //迷宫的坐标
    int r,c; //r 表示行，c表示列
}PosType;
typedef struct{  //表示路径中的一通道块
    PosType seat;//通道块在迷宫中的坐标位置
    PosType former; //从哪个块走过来的
    int di;     //从此通道块走向下一个通道块的方向
} ElemType;

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


#endif // QUEUE_H_INCLUDED
