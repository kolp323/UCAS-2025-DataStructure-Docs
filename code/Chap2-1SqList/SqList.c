#include "SqList.h"
Status InitList_Sq ( SqList *L ){
//����һ���յġ�����ΪLIST_INIT_SIZE�����Ա�L
L->elem = (ElemType *)malloc(LIST_INIT_SIZE *sizeof( ElemType ) ) ;

if (!L->elem ) return OVERFLOW;	//�洢����ʧ��
L->length= 0; 			   		//�ձ���Ϊ0
L->listsize = LIST_INIT_SIZE; 	//��ʼ�洢����
return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList *L, int i, ElemType e) {
ElemType *p;
// ����ִ���������
if(i<1 || i>L->length+1) return ERROR; //iֵ���Ϸ�
if(L->length>= L->listsize){
	// ��ǰ�洢�ռ���������������
	 ElemType *newbase =
	    (ElemType *) realloc(L->elem, (L->listsize+LISTINCREMENT)*sizeof(ElemType));
	if (!newbase) return ERROR; // �洢����ʧ��
	L->elem = newbase; //�µĻ���ַ
	L->listsize += LISTINCREMENT; //�µĴ洢����
	}

ElemType *q= &(L->elem[i-1]); //qΪ����λ��
//����λ�ü�֮���Ԫ������
for(p=&(L->elem[L->length-1]);p>=q;--p)
	 *(p+1) =*p;
*q =e;			//����e
++L->length;	//����1
return OK;
}//ListInsert_Sq

Status ListDelete_Sq(SqList *L, int i, ElemType *e) {
 ElemType *p, *q;
 if ((i<1) || (i>L->length)) return ERROR;  // iֵ���Ϸ�
 p = &(L->elem[i-1]); 		// pΪ��ɾ��Ԫ�ص�λ��
 *e = *p;                   // ��ɾ��Ԫ�ص�ֵ����e
 q = L->elem+ L->length-1;  // qΪ��βԪ�ص�λ��
 for (++p; p<=q; ++p)
	*(p-1) = *p;  			// ��ɾ��Ԫ��֮���Ԫ������
  --L->length;             // ����1
  return OK;
} // ListDelete_Sq


Status compare(ElemType a, ElemType b)
{
  if (a<b) return LESS;
  if (a>b) return GREATER;
  return 0;
}

// L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
int LocateElem_Sq(SqList *L, ElemType e, Status (*compare)(ElemType, ElemType)) {
int i; ElemType *p;
i = 1; // i�ĳ�ֵΪ��1��Ԫ�ص�λ��
p = L->elem; // p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
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
if (!Lc->elem) return OVERFLOW; // �洢����ʧ��
pa_last = La->elem+La->length-1;
pb_last = Lb->elem+Lb->length-1;
while (pa <= pa_last && pb <= pb_last) { // �鲢
	if (*pa <= *pb) *pc++ = *pa++; // ��ֵ�ǵݼ�����
	else *pc++ = *pb++; }
while (pa <= pa_last) *pc++ = *pa++; // ����La��ʣ��Ԫ��
while (pb <= pb_last) *pc++ = *pb++; // ����Lb��ʣ��Ԫ��
return OK;
} // MergeList, �㷨2.2��ʵ��

