#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int main()
{
LinkList *L,*M,*N; L=NULL;
ElemType e; int i;

L=CreateList_L(5); // 6 5 4 3 2
printf("Create a list whose first element is %d \n",L->next->data);

ListInsert_L(L, 1, 100);
GetElem_L(L,1,&e);
printf("GetElem: %d \n",e);// 100

GetElem_L(L,2,&e);
printf("GetElem: %d \n",e);// 6

ListDelete_L(L, 1, &e);
printf("DelElem: %d \n",e);// 100

M=CreateList_L(3);  //4 3 2
N=MergeList_L(L,M); //6 5 4 4 3 3 2 2
for(i=1;i<8;i++){
    GetElem_L(N,i,&e);
    printf("Get element %d from N: %d \n",i,e);
    }
printf("Hello world!\n");
return 0;
}
