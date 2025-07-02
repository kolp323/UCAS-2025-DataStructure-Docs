#include "ClientQueue.h"

//�����еĳ�ʼ��������һ���ն���
Status InitQueue(LinkedQueue *lq){
lq->front=lq->rear=(QNode *)malloc(sizeof(QNode));
if(!lq->front) return ERROR;
lq->front->next=NULL;
return OK;
}

int GetLen(LinkedQueue *lq){
int i;QNode *p;
p=lq->front->next;
i=0;
while(p){
    i++;p=p->next;
    }
return i;
}

int IsQueueEmpty(LinkedQueue *lq){//�գ����� 1
if(lq->front == lq->rear)return 1;
else return 0;
}

Status GetFront(LinkedQueue *lq,QElemType *e){
if(lq->front == lq->rear) return ERROR;
*e=lq->front->next->data;
return OK;
}
//��ӣ�����Ԫ��eΪ���е��µĶ�βԪ��
Status Enqueue(LinkedQueue *lq,QElemType e){
QNode *p;
p=(QNode *)malloc(sizeof(QNode));
if(!p) return ERROR;
p->data =e; p->next=NULL;
lq->rear->next=p; //�޸�βָ��
lq->rear=p;
return OK;
}

//���ӣ������в��գ���ɾ�����еĶ�ͷԪ�أ�
//��e������ֵ��������OK�����򷵻�ERROR
Status Dequeue(LinkedQueue *lq,QElemType *e){
QNode *p;
if (lq->front == lq->rear) return ERROR; //�ն��еĻ��������
p = lq->front->next; //�޸�ͷָ��
*e = p->data;
lq->front->next =p->next;
if(lq->rear==p) lq->rear=lq->front;//�޸�βָ��
free(p);
return OK;
}

void PrintQueue(LinkedQueue *lq){
QNode *p;
p=lq->front->next;
while(p!=NULL){
    printf("%d %d",p->data.ArrivalTime,p->data.Duration);
    //cout << p->data.ArrivalTime << " " << p->data.Duration;
    p=p->next;
    }
printf("\n");
}
