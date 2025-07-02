#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"


void Conversion(int n,int d){ //将十进制整数n转换为d进制数
ElemType e;
SqStack s; if(!InitStack(&s)) return;
while(n!=0) { //将余数逐一进栈
    Push(&s,n%d);
    n=n/d;}
while(!IsStackEmpty(&s)) {
    Pop(&s,&e);
    printf("%d",e);
}
printf("\n");
}

void visit(ElemType *e){
    printf("Elem is %c \n",*e);
    return;
}

Status MatchingBrackets(char *exps){
int i=0;
Status state=OK;
ElemType e; SqStack s; InitStack(&s);
while(state && exps[i]!='\0' ){
    switch(exps[i]){
        case '(':
        case '[':
        case '{':Push(&s,exps[i]);
            StackTraverse(&s, visit);printf("\n");
            break;
        case ')':
        case ']':
        case '}':if(!GetTop(&s,&e)) {state=ERROR; break;};
            if((e=='(' && exps[i]==')') ||  (e=='[' && exps[i]==']')
                ||  (e=='{' && exps[i]=='}'))
            Pop(&s,&e);
            else state=ERROR;
            StackTraverse(&s, visit);printf("\n");
            break;
    }
i++;
}
if(IsStackEmpty(&s) && state) {
    printf("Match Successfully\n"); return OK;}
else {
    printf("Fail to Match\n");return ERROR;}
}

int main()
{
//1. 数制转换
//Conversion(100,2); // 输出： 110 0100
//Conversion(1348,8); // 输出： 2504
//2. 括号匹配
//char exps[] = {'(','=','[',']','\0'};
char exps[] = {'[','(','[',']','[',']',')',']','\0'};
MatchingBrackets(exps);

return 0;
}


