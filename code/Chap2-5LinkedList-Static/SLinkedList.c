#include "SLinkedList.h"

//1. ��̬����ĳ�ʼ�����ڴ洢�����н�����������
void InitList(SLinkedList space){
    int i;
    for(i=0;i<MAXSIZE-1;i++)
        space[i].cur=i+1;
    space[MAXSIZE-1].cur=0;
}

int AllocNode(SLinkedList space){
int i;
i=space[0].cur;
if(i==0) return 0;
space[0].cur=space[i].cur;
return i;
}

void FreeNode(SLinkedList space,int i){
space[i].cur=space[0].cur;
space[0].cur=i;
}
//2. ����һ������n�����ľ�̬�������ر�ͷ�ڴ洢�����λ��
int CreateList(SLinkedList space,int n){
int head,k,s,i;
k=AllocNode(space);
head=k;
for(i=1;i<=n;i++){
    s=AllocNode(space);
    scanf("%d",&space[s].data);
    space[k].cur=s;
    k=s;
    }
space[k].cur=0;
return head;
}

//3. ����headΪ��ͷ�ľ�̬�����У��ڵ�i�����֮ǰ����һ��ֵΪx���½��
int Insert(SLinkedList space,int head,int i,ElemType x){
int j,k,m;
if(i<1) return 0;
k=head;j=0;
while (k!=0 && j<i-1){
    j++;k=space[k].cur;}
    if(k==0) return 0;
    m=AllocNode(space);
    if (m!=0){
        space[m].data=x;
        space[m].cur=space[k].cur;
        space[k].cur=m;
        return 1;
    }
    else return 0;
}

//4. ����headΪ��ͷ�ľ�̬�����У�ɾ����i�����
int Delete(SLinkedList space,int head,int i, ElemType *e){
int j,k,m;
if(i<1) return 0;
k=head;j=0;
while (k!=0 && j <i-1){//���ҵ�i-1�����
       j++;k=space[k].cur;}
if(k==0) return 0;
m=space[k].cur;
space[k].cur=space[m].cur;
*e=space[m].data;
FreeNode(space,m);
return 1;
}

//5. ����headΪ��ͷ�ľ�̬�����У�ȷ����һ��ֵΪx�Ľ���λ��
int Locate(SLinkedList space, int head,ElemType x){
int k;
k=space[head].cur;
while(k!=0 && space[k].data!=x)
    k=space[k].cur;
return k;
}

void Print(SLinkedList space,int head){
    int i;i=space[head].cur;
    while(i!=0){
        printf("%4d",space[i].data);
        i=space[i].cur;
    }
    printf("\n");
}

void MergeAB(SLinkedList A, int ha,SLinkedList B, int hb){
int i,j,k,m;
ElemType x;
j=B[hb].cur;
while(j!=0){
    x=B[j].data;
    i=Locate(A,ha,x);
    if(i==0)Insert(A,ha,1,x);
    else {
        m=0;k=ha;
        while(k!=i){
            m++;k=A[k].cur;}
            Delete(A,ha,m,&x);
        }
    j=B[j].cur;
   }
}
