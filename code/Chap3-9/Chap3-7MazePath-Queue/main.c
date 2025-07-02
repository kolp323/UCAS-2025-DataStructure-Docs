#include "queue.h"

//迷宫的墙：X；没有走过的通道块：空格；
//走过标记：*；路径：+
char maze[10][10]={
{'X','X','X','X','X','X','X','X','X','X'},
{'X',' ',' ','X',' ',' ',' ','X',' ','X'},
{'X',' ',' ','X',' ',' ',' ','X',' ','X'},
{'X',' ',' ',' ',' ','X','X',' ',' ','X'},//可达
//{'X',' ',' ',' ','X','X','X',' ',' ','X'},//不可达
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

//在迷宫的当前位置记录路径(+)
void PathMark(PosType CurPos) {
maze[CurPos.r][CurPos.c]='+';
}

//在迷宫的当前位置留下走过标记(*)
void FootPrint(PosType CurPos) {
maze[CurPos.r][CurPos.c]='*';
}

// 判定迷宫的当前位置是否可通过(即未曾走到过的通道块)
Status Pass(PosType CurPos) {
if (maze[CurPos.r][CurPos.c]==' ')
	return OK; // 如果当前位置是空格，则可以通过
else return ERROR;//可能是墙，可能已经走过：包括当前的路径和被标记为走不通的通道块
}

//返回当前位置的Dir方向所指示的位置
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
        tmp = trajectories[i].former; //回溯到前一步
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
//若修改迷宫(3,5)成X,则1，5不可达
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
                    tmpBlock.former=qHead.seat; //记录从哪里走过来的
                    tmpBlock.di=dj;
                    Enqueue(&workingQ,tmpBlock);
                    FootPrint(npos);
                    }

            }
}
printf("No way to destination (%d,%d)\n",end1.r,end1.c);
return 1;
}

