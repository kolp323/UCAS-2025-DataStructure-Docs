#include "queue.h"

//�Թ���ǽ��X��û���߹���ͨ���飺�ո�
//�߹���ǣ�*��·����+
char maze[10][10]={
{'X','X','X','X','X','X','X','X','X','X'},
{'X',' ',' ','X',' ',' ',' ','X',' ','X'},
{'X',' ',' ','X',' ',' ',' ','X',' ','X'},
{'X',' ',' ',' ',' ','X','X',' ',' ','X'},//�ɴ�
//{'X',' ',' ',' ','X','X','X',' ',' ','X'},//���ɴ�
{'X',' ','X','X','X',' ',' ',' ','X','X'},
{'X',' ',' ',' ','X',' ',' ',' ','X','X'},
{'X',' ','X',' ',' ',' ','X',' ',' ','X'},
{'X','X','X','X','X',' ','X','X',' ','X'},
{'X',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X','X','X','X','X','X','X','X','X','X'},
};

void PrintMaze(){
int i,j;
for(i=0;i<10;i++) {
    for(j=0;j<10;j++)
    printf("%c",maze[i][j]);
    printf("\n");
}
printf("\n");
return;
}

//���Թ��ĵ�ǰλ�ü�¼·��(+)
void PathMark(PosType CurPos) {
maze[CurPos.r][CurPos.c]='+';
}

//���Թ��ĵ�ǰλ�������߹����(*)
void FootPrint(PosType CurPos) {
maze[CurPos.r][CurPos.c]='*';
}

// �ж��Թ��ĵ�ǰλ���Ƿ��ͨ��(��δ���ߵ�����ͨ����)
Status Pass(PosType CurPos) {
if (maze[CurPos.r][CurPos.c]==' ')
	return OK; // �����ǰλ���ǿո������ͨ��
else return ERROR;//������ǽ�������Ѿ��߹���������ǰ��·���ͱ����Ϊ�߲�ͨ��ͨ����
}

//���ص�ǰλ�õ�Dir������ָʾ��λ��
PosType NextPos(PosType CurPos, int Dir) {
PosType ReturnPos;
	switch (Dir) {
	case 1: ReturnPos.r=CurPos.r; ReturnPos.c=CurPos.c+1; break;
	case 2: ReturnPos.r=CurPos.r+1;ReturnPos.c=CurPos.c; break;
	case 3: ReturnPos.r=CurPos.r; ReturnPos.c=CurPos.c-1; break;
	case 4: ReturnPos.r=CurPos.r-1;ReturnPos.c=CurPos.c; break;
    }
return ReturnPos;
}

ElemType trajectories[1000]; int traP=0;
void PrintTrajectory(ElemType endp){
int i; PosType tmp;

PathMark(endp.seat);
tmp=endp.former;
for(i=traP-1;i>=0;i--){
    if(trajectories[i].seat.r==tmp.r && trajectories[i].seat.c==tmp.c){
        PathMark(trajectories[i].seat);
        tmp = trajectories[i].former; //���ݵ�ǰһ��
        }
}
PrintMaze();
return;
}

int main()
{
LinkedQueue workingQ;
ElemType tmpBlock,qHead;
PosType start1,end1,npos;int dj;

PrintMaze();
start1.r=1;start1.c=1; end1.r=1;end1.c=5;
//���޸��Թ�(3,5)��X,��1��5���ɴ�
//start1.r=1;start1.c=1; end1.r=8;end1.c=1;
//start1.r=1;start1.c=1; end1.r=1;end1.c=8;
tmpBlock.seat=start1; tmpBlock.former=start1;tmpBlock.di=1;
InitQueue(&workingQ); Enqueue(&workingQ,tmpBlock);
while(!IsQueueEmpty(&workingQ)){
        Dequeue(&workingQ, &qHead);
        if(qHead.seat.c == end1.c && qHead.seat.r == end1.r)
            {PrintTrajectory(qHead);return 0;}
        else { trajectories[traP]=qHead;
               traP++;
               }
        for(dj=1;dj<=4;dj++){
            npos=NextPos(qHead.seat, dj);
            if(Pass(npos)) {
                    tmpBlock.seat=npos;
                    tmpBlock.former=qHead.seat; //��¼�������߹�����
                    tmpBlock.di=dj;
                    Enqueue(&workingQ,tmpBlock);
                    FootPrint(npos);
                    }

            }
}
printf("No way to destination (%d,%d)\n",end1.r,end1.c);
return 1;
}

