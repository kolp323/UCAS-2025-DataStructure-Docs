#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList.h"

int main()
{
SLinkedList s;
int head1,head2;

InitList(s);
head1=CreateList(s,3); //ÊäÈë£º300 400 500
head2=CreateList(s,4); //ÊäÈë£º400 600 700 800
MergeAB(s, head1,s, head2); //Êä³ö£º800 700 600 300 500
Print(s,head1);

return 0;
}
