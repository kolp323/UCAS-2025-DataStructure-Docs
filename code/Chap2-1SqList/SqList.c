#include "SqList.h"
Status InitList_Sq ( SqList *L ){
//构造一个空的、容量为LIST_INIT_SIZE的线性表L
L->elem = (ElemType *)malloc(LIST_INIT_SIZE *sizeof( ElemType ) ) ;

if (!L->elem ) return OVERFLOW;	//存储分配失败
L->length= 0; 			   		//空表长度为0
L->listsize = LIST_INIT_SIZE; 	//初始存储容量
return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList *L, int i, ElemType e) {
ElemType *p;
// 操作执行条件检查
if(i<1 || i>L->length+1) return ERROR; //i值不合法
if(L->length>= L->listsize){
	// 当前存储空间已满，增加容量
	 ElemType *newbase =
	    (ElemType *) realloc(L->elem, (L->listsize+LISTINCREMENT)*sizeof(ElemType));
	if (!newbase) return ERROR; // 存储分配失败
	L->elem = newbase; //新的基地址
	L->listsize += LISTINCREMENT; //新的存储容量
	}

ElemType *q= &(L->elem[i-1]); //q为插入位置
//插入位置及之后的元素右移
for(p=&(L->elem[L->length-1]);p>=q;--p)
	 *(p+1) =*p;
*q =e;			//插入e
++L->length;	//表长增1
return OK;
}//ListInsert_Sq

Status ListDelete_Sq(SqList *L, int i, ElemType *e) {
 ElemType *p, *q;
 if ((i<1) || (i>L->length)) return ERROR;  // i值不合法
 p = &(L->elem[i-1]); 		// p为被删除元素的位置
 *e = *p;                   // 被删除元素的值赋给e
 q = L->elem+ L->length-1;  // q为表尾元素的位置
 for (++p; p<=q; ++p)
	*(p-1) = *p;  			// 被删除元素之后的元素左移
  --L->length;             // 表长减1
  return OK;
} // ListDelete_Sq


Status compare(ElemType a, ElemType b)
{
  if (a<b) return LESS;
  if (a>b) return GREATER;
  return 0;
}

// L中查找第1个值与e满足compare()的元素的位置
int LocateElem_Sq(SqList *L, ElemType e, Status (*compare)(ElemType, ElemType)) {
int i; ElemType *p;
i = 1; // i的初值为第1个元素的位置
p = L->elem; // p的初值为第1个元素的存储位置
while (i <= L->length && ((*compare)(*p, e)) !=0 )  {
	p++;
	++i;
}
if (i <= L->length) return i;
else return 0;
} // LocateElem_Sq

Status MergeList_Sq(SqList *La, SqList *Lb,SqList *Lc) {
ElemType *pa,*pb,*pc,*pa_last,*pb_last;
pa = La->elem; pb = Lb->elem;
Lc->listsize = Lc->length = La->length+Lb->length;
pc = Lc->elem = (ElemType*)malloc(Lc->listsize*sizeof(ElemType));
if (!Lc->elem) return OVERFLOW; // 存储分配失败
pa_last = La->elem+La->length-1;
pb_last = Lb->elem+Lb->length-1;
while (pa <= pa_last && pb <= pb_last) { // 归并
	if (*pa <= *pb) *pc++ = *pa++; // 按值非递减插入
	else *pc++ = *pb++; }
while (pa <= pa_last) *pc++ = *pa++; // 插入La的剩余元素
while (pb <= pb_last) *pc++ = *pb++; // 插入Lb的剩余元素
return OK;
} // MergeList, 算法2.2的实现

