#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
typedef int Status;
typedef struct{ //迷宫的坐标
    int r,c; //r 表示行，c表示列
}PosType;

//迷宫的墙：X；没有走过的通道块：空格；
//走过标记：*；走不通：!
char maze[10][10]={
{'X','X','X','X','X','X','X','X','X','X'},
{'X',' ',' ','X',' ',' ',' ','X',' ','X'},
{'X',' ',' ','X',' ',' ',' ','X',' ','X'},
{'X',' ',' ',' ',' ','X','X',' ',' ','X'},
{'X',' ','X','X','X',' ',' ',' ','X','X'},
{'X',' ',' ',' ','X',' ',' ',' ','X','X'},
{'X',' ','X',' ',' ',' ','X',' ',' ','X'},
{'X','X','X','X','X',' ','X','X',' ','X'},
{'X',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X','X','X','X','X','X','X','X','X','X'},
};
char mazePrint[10][10];

void PrintMaze(char m[10][10]){
int i,j;
printf("\n");
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++)
        printf("%c",m[i][j]);
        printf("\n");
    }
printf("\n");
return;
}

//在迷宫的当前位置留下走过标记(*)
void FootPrint(PosType CurPos) {
maze[CurPos.r][CurPos.c]='*';
}

//在迷宫的当前位置留下走不通标记(!)
void MarkPrint(PosType CurPos) {
maze[CurPos.r][CurPos.c]='!';
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

Status SeekPath(PosType curPos,PosType endPoint) {
//从迷宫中坐标点curPos的位置寻找通向终点end1的路径
//若找到则返回OK，否则返回ERROR
int i;
PosType pos;
if ((curPos.r==endPoint.r)&&(curPos.c==endPoint.c))
    return  OK;
for(i=0; i<4; i++)  {
    pos = NextPos(curPos, i+1);
    if (Pass(pos)){
       FootPrint(pos); // 留下足迹
       if(SeekPath(pos,endPoint)){
            printf("(%d %d)", pos.r, pos.c);
            mazePrint[pos.r][pos.c]='+'; //记录路径
            return OK;
            }
        }
} //for
return ERROR;
}

int main()
{
PrintMaze(maze);
memcpy(mazePrint,maze,10*10*sizeof(char));
PosType start1,end1;
start1.r=1;start1.c=1;
//end1.r=8;end1.c=1;
end1.r=1;end1.c=8;
SeekPath(start1, end1);
mazePrint[start1.r][start1.c]='+';
PrintMaze(mazePrint);
return 0;
}
