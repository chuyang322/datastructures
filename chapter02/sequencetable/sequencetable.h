#include "datastruct.h"
#include <stdlib.h>

#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
#define LISTINCREMENT 10   // 线性表存储空间的分配增量

typedef int ElemType;

typedef struct
{
    ElemType *elem; //存储空间地址
    int length;     //当前长度
    int listsize;   //当前分配的存储容量(以sizeof(ElemType)为单位)
} SqList;

Status InitList_Sq(SqList &L);
Status ListInsert_Sq(SqList &L, int i, ElemType e);
Status ListDelete_Sq(SqList &L, int i, ElemType &e);
int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc);
void ListPrint_Sq(SqList &L);
