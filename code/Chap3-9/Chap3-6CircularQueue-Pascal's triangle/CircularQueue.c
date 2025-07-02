#include "CircularQueue.h"

Status InitQueue(CircularQueue *cq){
cq->base=(ElemType *)malloc(MAXQUEUESIZE*sizeof(ElemType));
if(!cq->base) return ERROR;
cq->front=cq->rear=0;
return OK;
}

int GetLen(CircularQueue *cq){
return ((cq->rear - cq->front + MAXQUEUESIZE)%MAXQUEUESIZE);
}

int IsQueueEmpty(CircularQueue *cq){
if (cq->front == cq->rear) return 1;
else return 0;
}

Status GetFront(CircularQueue *cq,ElemType *e){
if(cq->front == cq->rear) return ERROR;
*e=cq->base[cq->front];
return OK;
 }

Status Enqueue(CircularQueue *cq,ElemType e){
if((cq->rear+1)%MAXQUEUESIZE == cq->front) return ERROR;
cq->base[cq->rear]=e;
cq->rear=(cq->rear+1)%MAXQUEUESIZE;
return OK;
}

Status Dequeue(CircularQueue *cq,ElemType *e){
if(cq->front == cq->rear) return ERROR;
*e=cq->base[cq->front];
cq->front=(cq->front +1)%MAXQUEUESIZE;
return OK;
}

void PrintQueue(CircularQueue *cq){
int i; i=cq->front;
while(i!= cq->rear){
    printf("%4d",cq->base[i]);
    i=(i+1)% MAXQUEUESIZE;
    }
}
