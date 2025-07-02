#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
typedef int Status;
typedef struct{ //�Թ�������
    int r,c; //r ��ʾ�У�c��ʾ��
}PosType;

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

//���Թ��ĵ�ǰλ�������߹����(*)
void FootPrint(PosType CurPos) {
maze[CurPos.r][CurPos.c]='*';
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

Status SeekPath(PosType curPos,PosType endPoint) {
//���Թ��������curPos��λ��Ѱ��ͨ���յ�end1��·��
//���ҵ��򷵻�OK�����򷵻�ERROR
int i;
PosType pos;
if ((curPos.r==endPoint.r)&&(curPos.c==endPoint.c))
    return  OK;
for(i=0; i<4; i++)  {
    pos = NextPos(curPos, i+1);
    if (Pass(pos)){
       FootPrint(pos); // �����㼣
       if(SeekPath(pos,endPoint)){
            printf("(%d %d)", pos.r, pos.c);
            mazePrint[pos.r][pos.c]='+'; //��¼·��
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
