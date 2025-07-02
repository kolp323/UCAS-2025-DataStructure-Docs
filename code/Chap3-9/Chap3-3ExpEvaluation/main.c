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

//����Test�Ƿ��������
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

//���������֮������ȹ�ϵ
void Precede(char Aop, char Bop,char *result){
int i,j;
i=ReturnOpOrd(Aop,OPSET);
j=ReturnOpOrd(Bop,OPSET);
*result=Prior[i][j];
return;
}

//ִ���������㣺a theta b
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
SqStack OptrStack,OpndStack;//OptrStack:�����ջ�����ַ�Ԫ�أ�OpndStack:������ջ���渡����
InitStack(&OptrStack); tmp.op='#'; Push(&OptrStack,tmp);
InitStack(&OpndStack);

char tmpStr[20]; strcpy(tmpStr,"\0");
char dr[2];

char *c; c=MyExp;
char x,y;
char theta;float a,b;

GetTop(&OptrStack,&tmp);x=tmp.op;
while( *c !='#' || x !='#'){
        if(!In(*c,OPSET)) {// *c������������������ջ
            dr[0]=*c; dr[1]='\0'; strcat(tmpStr,dr); c++;
            if(In(*c,OPSET)){
                tmp.x=(float)atof(tmpStr);
                Push(&OpndStack,tmp); strcpy(tmpStr,"\0"); }
        }
        else {
            Precede(tmp.op,*c,&y);
            switch(y){
                // �����������ջ �������ȹ�ϵ������Ӧ�Ķ���
                case '<': //ջ��Ԫ�����ȼ��ͣ��򽫶����������ջ
                    tmp.op= *c; Push(&OptrStack, tmp); c++; break;
                case '=': // �����Ų�������һ�ַ�
                    Pop(&OptrStack, &tmp); c++; break;
                case '>': // ջ�������ջ�����������������ջ
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
scanf("%s",str); // ��#������������������(������������)
result=ExpEvaluation(str);
printf("Result is %f \n",result);
system("Pause");
return 0;
}
