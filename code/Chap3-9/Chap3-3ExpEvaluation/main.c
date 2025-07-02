#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define OPSETSIZE 7
char OPSET[OPSETSIZE]={'+' , '-' , '*' , '/' ,'(' , ')' , '#'};
unsigned char Prior[OPSETSIZE][OPSETSIZE] = {
 {'>','>','<','<','<','>','>'},
 {'>','>','<','<','<','>','>'},
 {'>','>','>','>','<','>','>'},
 {'>','>','>','>','<','>','>'},
 {'<','<','<','<','<','=',' '},
 {'>','>','>','>',' ','>','>'},
{'<','<','<','<','<',' ','='} };

//测试Test是否是运算符
Status In(char Test, char* TestOp)
{
int i;
for (i=0; i< OPSETSIZE; i++) {
    if (Test == TestOp[i])
        return OK;}
 return ERROR;
}

int ReturnOpOrd(char op, char* TestOp) {
int i;
for(i=0; i< OPSETSIZE; i++) {
    if (op == TestOp[i])
            return i; }
return 0;
}

//返回两算符之间的优先关系
void Precede(char Aop, char Bop,char *result){
int i,j;
i=ReturnOpOrd(Aop,OPSET);
j=ReturnOpOrd(Bop,OPSET);
*result=Prior[i][j];
return;
}

//执行四则运算：a theta b
float Operate(float a, unsigned char theta, float b) {
switch(theta) {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': return a/b;
    default : return 0; }
}

float ExpEvaluation(char *MyExp){
ElemType tmp;
SqStack OptrStack,OpndStack;//OptrStack:运算符栈，存字符元素；OpndStack:运算数栈，存浮点数
InitStack(&OptrStack); tmp.op='#'; Push(&OptrStack,tmp);
InitStack(&OpndStack);

char tmpStr[20]; strcpy(tmpStr,"\0");
char dr[2];

char *c; c=MyExp;
char x,y;
char theta;float a,b;

GetTop(&OptrStack,&tmp);x=tmp.op;
while( *c !='#' || x !='#'){
        if(!In(*c,OPSET)) {// *c不是运算符则进运算数栈
            dr[0]=*c; dr[1]='\0'; strcat(tmpStr,dr); c++;
            if(In(*c,OPSET)){
                tmp.x=(float)atof(tmpStr);
                Push(&OpndStack,tmp); strcpy(tmpStr,"\0"); }
        }
        else {
            Precede(tmp.op,*c,&y);
            switch(y){
                // 根据它与算符栈 顶的优先关系，做相应的动作
                case '<': //栈顶元素优先级低，则将读到的算符进栈
                    tmp.op= *c; Push(&OptrStack, tmp); c++; break;
                case '=': // 脱括号并接收下一字符
                    Pop(&OptrStack, &tmp); c++; break;
                case '>': // 栈顶算符出栈并将运算结果入操作数栈
                    Pop(&OptrStack, &tmp);theta=tmp.op;
                    Pop(&OpndStack, &tmp);b=tmp.x;
                    Pop(&OpndStack, &tmp);a=tmp.x;
                    tmp.x=Operate(a, theta, b);
                    Push(&OpndStack,tmp); break;
                case ' ':
                    printf("Input Error\n");
                    return 0;
            }
        }
       GetTop(&OptrStack,&tmp);x=tmp.op;
}
GetTop(&OpndStack,&tmp);
return tmp.x;
}


int main()
{
float result;
char *str; str=(char *)malloc(20*sizeof(char));
scanf("%s",str); // 以#结束，不能输入中文(包括中文括号)
result=ExpEvaluation(str);
printf("Result is %f \n",result);
system("Pause");
return 0;
}
