#include <stdlib.h>
#include "stack.h"


//�Թ���ǽ��X��û���߹���ͨ���飺�ո�
//�߹���ǣ�*���߲�ͨ��!
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

//���Թ��ĵ�ǰλ�������߹����(*)
void FootPrint(PosType CurPos) {
maze[CurPos.r][CurPos.c]='-';
}

//���Թ��ĵ�ǰλ�������߲�ͨ���(!)
void MarkPrint(PosType CurPos) {
maze[CurPos.r][CurPos.c]='!';
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

// ���Թ�maze�д��ڴ����start������end��ͨ���������һ�������ջS��
Status MazePath(PosType start1, PosType end1, SqStack *s) {
PosType curpos; int curstep; ElemType e;
curpos.r = start1.r;curpos.c = start1.c; // �趨"��ǰλ��"Ϊ"���λ��"
curstep = 1; // ̽����һ��
do {
    if (Pass(curpos)) { // ��ǰλ�ÿ�ͨ��
        FootPrint(curpos); // �����㼣
        e.ord = curstep; e.seat.r=curpos.r;e.seat.c=curpos.c; e.di=1;//�Ӷ���ʼ
        Push(s,e); // ����ǰͨ�������·��
        if (curpos.r == end1.r && curpos.c==end1.c)
            return (OK); // �������
        //׼��̽����һͨ����
        //���õ�ǰͨ����Ϊ��ǰͨ����Ķ���
        curpos = NextPos(curpos, 1);
        curstep++;
    }
    else { // ��ǰλ�ò���ͨ��
        if (!IsStackEmpty(s)) {
            Pop(s,&e);
            while (e.di==4 && !IsStackEmpty(s)) {
            // ���²���ͨ���ı�ǣ����˻�һ��
            MarkPrint(e.seat); Pop(s,&e);
            } // while
            if (e.di<4) {
                    e.di++; Push(s, e); // ����һ������̽��
                    // ��ǰλ����Ϊ�·�������ڿ�
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
