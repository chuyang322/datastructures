#include <stdio.h>
#include "sequencetable.h"

//--------------------------------------------------------
//顺序表基本函数实现
//--------------------------------------------------------
Status InitList_Sq(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
    {
        exit(OVERFLOW);
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
} // InitList.Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    //在顺序线性表L中第i个位置之前插入新的元素e
    //i的合法值为1<=i<=ListLength_Sq(L)+1
    if (i < 1 || i > L.length + 1)
    {
        return ERROR; //i值不合法
    }
    if (L.length >= L.listsize) //空间已满，增加分配
    {
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
        {
            exit(OVERFLOW); //分配失败
        }
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    ElemType *q = &(L.elem[i - 1]); //q为插入位置
    for (ElemType *p = &(L.elem[L.length - 1]); p >= q; --p)
    {
        *(p + 1) = *p; //插入位置之后的元素后移
    }
    *q = e;     //插入e
    ++L.length; //表长+1
    return OK;
} //ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    //在顺序线性表L中删除第i个元素，并用e返回其值
    //i的合法值为1<=i<=ListLength_Sq(L)
    if ((i < 1) || (i > L.length))
    {
        return ERROR; //i值不合法
    }
    ElemType *p = &(L.elem[i]);          //p为删除元素的位置
    e = *p;                              //被删除元素的值赋给e
    ElemType *q = L.elem + L.length - 1; //表尾元素的位置
    for (++p; p <= q; ++p)
    {
        *(p - 1) = *p; //被删除之后的元素左移
    }
    --L.length; //表长-1
    return OK;
} //ListDelete_Sq

int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    //在顺序表L中查找第一个与e满足compare()的元素位序
    //若找到，则返回其在L中的位序，否则返回0
    int i = 1;
    ElemType *p = L.elem;
    while (i <= L.length && !(*compare)(*p++, e))
    {
        ++i;
    }
    if (i <= L.length)
        return i;
    else
        return 0;
} //LocateElem_Sq

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
{
    //已知顺序表La和Lb的元素按值非递减排列
    //归并La和Lb得到新的表Lc，Lc也按值非递减排列
    ElemType *pa = La.elem;
    ElemType *pb = Lb.elem;
    Lc.listsize = Lc.length = La.length + Lb.length;
    ElemType *pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if (!Lc.elem)
        exit(OVERFLOW); //存储分配失败
    ElemType *pa_last = La.elem + La.length - 1;
    ElemType *pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last) //归并
    {
        if (*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }
    //插入剩余元素
    while (pa <= pa_last)
    {
        *pc++ = *pa++;
    }
    while (pb <= pb_last)
    {
        *pc++ = *pb++;
    }
} //MergeList_Sq

void ListPrint_Sq(SqList &L)
{
    int n = L.length;
    printf("----------------------------------------------------\n");
    printf("顺序表");
    for (int i = 0; i < n; i++)
    {
        ElemType e = L.elem[i];
        printf("->%d", e);
    }
    printf("\n----------------------------------------------------\n");
} //ListPrint_Sq

//----------------------------------------------------------------
//下面代码用来操作顺序表
//----------------------------------------------------------------
void init();
void insert(SqList &L);

void init()
{
    SqList L;
    printf("初始化顺序表...\n");
    InitList_Sq(L);
    while (1)
    {
        printf("请选择操作...\n0) 退出      1) 插入     2）删除\n->");
        int cz;
        scanf("%d", &cz);
        if (cz == 0)
            break;
        switch (cz)
        {
        case 1:
            insert(L);
            break;

        default:
            break;
        }
    }
}

void insert(SqList &L)
{
    while (1)
    {
        int i;
        ElemType e;
        printf("请输入要插入的位置和数据a,b(0退出)：");
        scanf("%d,%d", &i, &e);
        if (i == 0)
            break;
        ListInsert_Sq(L, i, e);
        ListPrint_Sq(L);
    }
}

int main()
{
    init();
    return 0;
}