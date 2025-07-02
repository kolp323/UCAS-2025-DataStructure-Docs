#include <stdlib.h>
#include <time.h>
#include "EventList.h"
#include "ClientQueue.h"

#define CLOSETIME 100
EventList *ev;
Event en;
LinkedQueue q[5]; //4���ͻ�����
int TotalTime,ClientNum;

void OrderInsert(EventList *ev,Event en){
ElemType e; int i=1;
while(i){
    if(GetElem_L(ev,i,&e)==ERROR)
        break;
    if(en.OccurTime < e.OccurTime)
        break;
    i++;
}
ListInsert_L(ev,i,en);
ListPrint(ev);
}

void OpenForDay(){int i;
TotalTime=0;ClientNum=0;
ev=InitList();
en.NType=0;en.OccurTime=0;
OrderInsert(ev,en);
for(i=1;i<=4;i++)
    InitQueue(&q[i]);
}
//����ͻ������¼�:en.NType = 0
void ClientArrived(){
//������һ�ͻ������¼�
Event nClient; int nArrivalTime,intertime,i;
ClientNum++;
intertime=rand()% 10;/*����10���ڵ��������*/
nArrivalTime=en.OccurTime+intertime; //��һ���ͻ��ĵ���ʱ��
if(nArrivalTime < CLOSETIME){
    //������δ���ţ������¼��б�
    nClient.OccurTime = nArrivalTime;
    nClient.NType=0;
    OrderInsert(ev,nClient);
}
//����ǰ�¼��������¼�������̶���
QElemType qe;int durtime;
int minno,minlen; //����̶���
Event lClient;
minlen=GetLen(&q[1]);minno=1;
for(i=2;i<=4;i++) {
    if(minlen>GetLen(&q[i])) {minlen=GetLen(&q[i]);minno=i;}
}
durtime=rand()% 300;/*����300���ڵ��������*/
qe.ArrivalTime=en.OccurTime,
qe.Duration=durtime;
Enqueue(&q[minno],qe);
if(GetLen(&q[minno])==1) {//���ڶ�ͷ�����ɿͻ��뿪�¼�
   lClient.NType=minno;lClient.OccurTime=en.OccurTime+durtime;
   OrderInsert(ev,lClient);
   }
}

//����ͻ��뿪�¼�:en.NType > 0
int DNo=0;
void ClientDeparture(){
QElemType lc,nlc;
Event ne;
int i=en.NType;
Dequeue(&q[i],&lc);//ɾ����Ӧ����ͷ
DNo++;
printf("-%d--��%d����-����ʱ��%d-����ʱ��%d-�뿪ʱ��%d\n",DNo,i,lc.ArrivalTime,lc.Duration,en.OccurTime);
// �ۼƿͻ�����ʱ��
TotalTime += en.OccurTime - lc.ArrivalTime;
if(!IsQueueEmpty(&q[i])) {//Ϊ��ǰ���еĶ�ͷ�ͻ�������һ�����뿪�¼�
    GetFront(&q[i],&nlc);
    ne.OccurTime=en.OccurTime+nlc.Duration;
    ne.NType=i;
    OrderInsert(ev,ne);
    }
}

int main()
{
OpenForDay();
srand((unsigned)time(NULL)); //�����������
while(!IsListEmpty(ev)) {
    ListDelete_L(ev,1,&en);
    //printf("Processing Event:%d,%d\n",en.NType,en.OccurTime);
    if(en.NType ==0)
        ClientArrived();// ����ͻ������¼�
    else ClientDeparture();// ����ͻ��뿪�¼�
 }
// ���㲢���ƽ������ʱ��
printf("Total time is %d, Client number is %d\n, The average time is %f\n",
       TotalTime, ClientNum,(float)TotalTime/ClientNum);
system("pause");
return 0;
}
