#include "CircularQueue.h"

int main()
{
CircularQueue q; ElemType e;
int r,total_row, cur_row_i_1=0, cur_row_i=0,next_row_i,c;

total_row=10;
InitQueue(&q);
Enqueue(&q,1);
Enqueue(&q,1);
for(r=1;r<total_row;r++){
    Enqueue(&q,0);
    for(c=1;c<=r+2;c++){
        Dequeue(&q,&e);
        cur_row_i = e;
        if (e) printf("%d ",cur_row_i);
        next_row_i = cur_row_i + cur_row_i_1;
        Enqueue(&q,next_row_i);
        cur_row_i_1=cur_row_i;
        }
    printf("\n");
}
while(!IsQueueEmpty(&q)) {
    Dequeue(&q,&e);
    printf("%d#",e);
}
printf("\n");

return 0;
}
