#include "queue.h"

int conflictMatrix[9][9]={
{0,1,0,0,0,1,0,0,0},
{1,0,0,0,1,1,0,1,1},
{0,0,0,0,0,1,1,0,0},
{0,0,0,0,1,0,0,0,1},
{0,1,0,1,0,0,1,0,1},
{1,1,1,0,0,0,1,0,0},
{0,0,1,0,1,1,0,0,0},
{0,1,0,0,0,0,0,0,0},
{0,1,0,1,1,0,0,0,0},
};


int main()
{
int i,j,head,curno,result[9],clash[9];

LinkedQueue sq; InitQueue(&sq);
for(i=0;i<9;i++) Enqueue(&sq,i);
Dequeue(&sq,&head);result[head]=curno=1;
for(i=0;i<9;i++) clash[i]=conflictMatrix[head][i];
while(!IsQueueEmpty(&sq)){
    Dequeue(&sq,&head);
    if (clash[head]==0){
        result[head]=curno;
        for(i=0;i<9;i++) clash[i]=clash[i]+conflictMatrix[head][i];
        }
    else Enqueue(&sq,head);
    if( GetFront(&sq,&j) && j<=head) { //����һ��
        Dequeue(&sq,&head); result[head]= ++curno;
        for(i=0;i<9;i++) clash[i]=conflictMatrix[head][i];
        }
}
for(i=0;i<9;i++)
    printf("%d �ֵ� %d ��\n",i,result[i]);
for(i=1;i<=curno;i++){
    printf("%d �������",i);
    for(j=0;j<9;j++)
     if(result[j] == i) printf("%d ",j);
    printf("\n");
    }
system("pause");
return 0;
}
