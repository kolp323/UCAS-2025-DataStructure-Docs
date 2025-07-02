#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int main()
{LinkList *L;ElemType e;
Link *cur;
L=InitList();
if (ListInsert_L(L,1,3)==ERROR) {
	printf("error\n"); return 0;
    }
GetElem_L(L,1, &e);
printf("GetElem: %d \n",e); // GetElem:3
ListInsert_L(L,1,4);
ListInsert_L(L,1,5);
GetElem_L(L,2, &e);
printf("GetElem: %d \n",e); // GetElem:4

cur=LocatePos(L, 2);
printf("GetElem in cur: %d \n",cur->data); //GetElem in cur:4

printf("Hello world!\n");
return 0;
}
