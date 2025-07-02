#include <stdio.h>
#include "DoubleLinkedList.h"

int main()
{
DoubleLinkedList *p;
ElemType e;
p=CreateDoubleLinkedList(3);//200 300 600
//InsertElem(p,1,400);// 400 200 300 600
DeleteNode(p,2,&e); printf("%4d are deleted\n",e);
PrintList(p);
//插入：输出：400 200 300 600 600 300 200 400
//删除，输出：300被删 200 600 600 200

return 0;
}

