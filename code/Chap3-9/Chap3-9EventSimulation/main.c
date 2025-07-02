#include <stdlib.h>
#include <time.h>
#include "EventList.h"
#include "ClientQueue.h"

#define CLOSETIME 100
EventList *ev;
Event en;
LinkedQueue q[5]; //4个客户队列
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
//处理客户到达事件:en.NType = 0
void ClientArrived(){
//生成下一客户到达事件
Event nClient; int nArrivalTime,intertime,i;
ClientNum++;
intertime=rand()% 10;/*产生10以内的随机整数*/
nArrivalTime=en.OccurTime+intertime; //下一个客户的到达时刻
if(nArrivalTime < CLOSETIME){
    //银行尚未关门，插入事件列表
    nClient.OccurTime = nArrivalTime;
    nClient.NType=0;
    OrderInsert(ev,nClient);
}
//处理当前事件，将该事件放入最短队列
QElemType qe;int durtime;
int minno,minlen; //求最短队列
Event lClient;
minlen=GetLen(&q[1]);minno=1;
for(i=2;i<=4;i++) {
    if(minlen>GetLen(&q[i])) {minlen=GetLen(&q[i]);minno=i;}
}
durtime=rand()% 300;/*产生300以内的随机整数*/
qe.ArrivalTime=en.OccurTime,
qe.Duration=durtime;
Enqueue(&q[minno],qe);
if(GetLen(&q[minno])==1) {//若在队头，生成客户离开事件
   lClient.NType=minno;lClient.OccurTime=en.OccurTime+durtime;
   OrderInsert(ev,lClient);
   }
}

//处理客户离开事件:en.NType > 0
int DNo=0;
void ClientDeparture(){
QElemType lc,nlc;
Event ne;
int i=en.NType;
Dequeue(&q[i],&lc);//删除相应队列头
DNo++;
printf("-%d--第%d窗口-到达时间%d-办事时间%d-离开时间%d\n",DNo,i,lc.ArrivalTime,lc.Duration,en.OccurTime);
// 累计客户逗留时间
TotalTime += en.OccurTime - lc.ArrivalTime;
if(!IsQueueEmpty(&q[i])) {//为当前队列的队头客户生成下一个的离开事件
    GetFront(&q[i],&nlc);
    ne.OccurTime=en.OccurTime+nlc.Duration;
    ne.NType=i;
    OrderInsert(ev,ne);
    }
}

int main()
{
OpenForDay();
srand((unsigned)time(NULL)); //播随机数种子
while(!IsListEmpty(ev)) {
    ListDelete_L(ev,1,&en);
    //printf("Processing Event:%d,%d\n",en.NType,en.OccurTime);
    if(en.NType ==0)
        ClientArrived();// 处理客户到达事件
    else ClientDeparture();// 处理客户离开事件
 }
// 计算并输出平均逗留时间
printf("Total time is %d, Client number is %d\n, The average time is %f\n",
       TotalTime, ClientNum,(float)TotalTime/ClientNum);
system("pause");
return 0;
}
