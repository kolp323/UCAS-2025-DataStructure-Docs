#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

int main()
{
LinkedStack *s; s=InitStack();
ElemType c;
char ch;
ch=getchar();
while(ch!=EOF) {
    while(ch!=EOF && ch !='\n'){
        switch(ch){
        case '#':if(!Pop(s,&c)) return 1; break;
        case '@':ClearStack(s);break;
        default: if(!Push(s,ch)) return 1; break;}
    ch=getchar();
    }
PrintStack(s);
if(ch!=EOF) ch=getchar();
}

return 0;
}

