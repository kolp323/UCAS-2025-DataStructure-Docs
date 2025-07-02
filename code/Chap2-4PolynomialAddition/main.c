#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef struct node{
    int c;//����ʽ��ϵ��
    int e;//����ʽ��ָ��
    struct node *next;
}Polynomial;

Polynomial *Create(int m){
Polynomial *head,*p,*q; int i;
p=head=(Polynomial*) malloc(sizeof(Polynomial)); //ͷ���
for(i=1;i<=m;i++){
    q=(Polynomial *)malloc(sizeof(Polynomial));
    scanf("%d %d",&q->c,&q->e);
    p->next = q;
    p=q;
}
p->next=NULL;
return head;
}

Status Compare(int a,int b){
    if(a>b) return 1;
    if(a<b) return -1;
    return 0;
}

void Plus(Polynomial *pa,Polynomial *pb){
Polynomial*h,*p1,*p2,*q;
h=pa;
p1=pa->next;p2=pb->next;
while(p1!=NULL && p2!=NULL)
    switch( Compare(p1->e, p2->e)){
    case 1: {//p1��ָ���󣬽�p2�Ľ�����ӵ�h
        h->next=p2;h=p2;p2=p2->next;
        break; }
    case -1:{
        h->next=p1; h=p1; p1=p1->next;
        break;}
    case 0: {
        if(p1->c + p2->c !=0) {
            p1->c =p1->c +p2->c;
            h->next=p1;h=p1;p1=p1->next;
            q=p2;
            p2=p2->next;
            free(q);
        }else {
        q=p1;p1=p1->next;free(q);
        q=p2;p2=p2->next;free(q);
        }
        }
    }
if(p1!=NULL)h->next =p1;
else h->next= p2;
free(pb);
}

void PrintOnConsole(Polynomial *head){
Polynomial *p=head->next;
printf("�����\n");
while(p!=NULL) {
    printf(" ϵ����%d, ָ����%d\n",p->c,p->e);
    p=p->next;
    }
}

int main()
{Polynomial *pa,*pb;
pa=Create(3); //���룺10 1 4 50 2 100
PrintOnConsole(pa);
pb=Create(3); //���룺2 1 1 51 -2 100
PrintOnConsole(pb);
Plus(pa,pb);
PrintOnConsole(pa);//�����12 1 4 50 1 51

return 0;
}


