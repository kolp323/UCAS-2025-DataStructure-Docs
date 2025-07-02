#include <stdlib.h>
#include "stack.h"


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

void PrintMaze(){
int i,j;
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++)
        printf("%c",maze[i][j]);
        printf("\n");
    }
return;
}

//在迷宫的当前位置留下走过标记(*)
void FootPrint(PosType CurPos) {
maze[CurPos.r][CurPos.c]='-';
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

// 若迷宫maze中存在从入口start到出口end的通道，则求得一条存放在栈S中
Status MazePath(PosType start1, PosType end1, SqStack *s) {
PosType curpos; int curstep; ElemType e;
curpos.r = start1.r;curpos.c = start1.c; // 设定"当前位置"为"入口位置"
curstep = 1; // 探索第一步
do {
    if (Pass(curpos)) { // 当前位置可通过
        FootPrint(curpos); // 留下足迹
        e.ord = curstep; e.seat.r=curpos.r;e.seat.c=curpos.c; e.di=1;//从东开始
        Push(s,e); // 将当前通道块加入路径
        if (curpos.r == end1.r && curpos.c==end1.c)
            return (OK); // 到达出口
        //准备探索下一通道块
        //设置当前通道块为当前通道块的东邻
        curpos = NextPos(curpos, 1);
        curstep++;
    }
    else { // 当前位置不能通过
        if (!IsStackEmpty(s)) {
            Pop(s,&e);
            while (e.di==4 && !IsStackEmpty(s)) {
            // 留下不能通过的标记，并退回一步
            MarkPrint(e.seat); Pop(s,&e);
            } // while
            if (e.di<4) {
                    e.di++; Push(s, e); // 换下一个方向探索
                    // 当前位置设为新方向的相邻块
                    curpos = NextPos(e.seat, e.di);
            } // if
        } // if
    } // else
} while (!IsStackEmpty(s));
return ERROR;
}

int main()
{
SqStack s; InitStack(&s);
PosType start1,end1;
start1.r=1;start1.c=1;
//end1.r=8;end1.c=8;
end1.r=1;end1.c=8;
PrintMaze();
MazePath(start1,end1,&s);
PrintStack(&s);
PrintMaze();
system("pause");
return 0;
}
