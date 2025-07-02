#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

int main()
{ int i;
SqList L,M,N;

InitList_Sq (&L); ListInsert_Sq(&L, 1, 99); ListInsert_Sq(&L, 2, 100);
i=LocateElem_Sq(&L,7, compare);
printf("%d\n",i);
i=LocateElem_Sq(&L, 100, compare);
printf("%d\n",i);

InitList_Sq (&M);ListInsert_Sq(&M, 1, 3); ListInsert_Sq(&M, 2, 6);
MergeList_Sq(&L,&M,&N);
i=LocateElem_Sq(&N,7, compare);
printf("%d\n",i);
i=LocateElem_Sq(&N,6, compare);
printf("%d\n",i);
i=LocateElem_Sq(&N,100, compare);
printf("%d\n",i);

printf("Hello world!\n");
return 0;
}
