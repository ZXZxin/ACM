typedef struct DuLNode
{
//自己定义数据类型。
    ElemType data;
    struct DuLNode *prior,*next;
} DuLNode,*DuLinkList;
// 带头结点的双向循环链表的基本操作
void InitList(DuLinkList *L)
{
    /* 产生空的双向循环链表 L */
    *L=(DuLinkList)malloc(sizeof(DuLNode));
    if(*L)
        (*L)->next=(*L)->prior=*L;
    else
        exit(OVERFLOW);
}
void DestroyList(DuLinkList *L)
// 销毁双向循环链表 L
{
    DuLinkList q,p=(*L)->next; /* p 指向第一个结点 */
    while(p!=*L) /* p 没到表头 */
    {
        q=p->next;
        free(p);
        p=q;
    }
    free(*L);
    *L=NULL;
}
// 重置链表为空表
void ClearList(DuLinkList L) /* 不改变 L */
{
    DuLinkList q,p=L->next; /* p 指向第一个结点 */
    while(p!=L) /* p 没到表头 */
    {
        q=p->next;
        free(p);
        p=q;

    }
    L->next=L->prior=L; /* 头结点的两个指针域均指向自身 */
}
// 验证是否为空表
Status ListEmpty(DuLinkList L)
{
    /* 初始条件：线性表 L 已存在*/
    if(L->next==L&&L->prior==L)
        return TRUE;
    else
        return FALSE;
}
// 计算表内元素个数
int ListLength(DuLinkList L)
{
    /* 初始条件：L 已存在。操作结果： */
    int i=0;
    DuLinkList p=L->next; /* p 指向第一个结点 */
    while(p!=L) /* p 没到表头 */
    {
        i++;
        p=p->next;
    }
    return i;
}
// 赋值
Status GetElem(DuLinkList L,int i,ElemType *e)
{
    /* 当第 i 个元素存在时，其值赋给 e 并返回 OK，否则返回 ERROR */
    int j=1; /* j 为计数器 */
    DuLinkList p=L->next; /* p 指向第一个结点 */
    while(p!=L&&jnext)
    {
        j++;
    }
    if(p==L||j>i) /* 第 i 个元素不存在 */
        return ERROR;
    *e=p->data; /* 取第 i 个元素 */
    return OK;
}
// 查找元素
int LocateElem(DuLinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
    /* 初始条件：L 已存在，compare()是数据元素判定函数 */
    /* 操作结果：返回 L 中第 1 个与 e 满足关系 compare()的数据元素的位序。 */
    /* 若这样的数据元素不存在，则返回值为 0 */
    int i=0;
    DuLinkList p=L->next; /* p 指向第 1 个元素 */
    while(p!=L)
    {
        i++;
        if(compare(p->data,e)) /* 找到这样的数据元素 */
            return i;
        p=p->next;
    }
    return 0;
}
// 查找元素前驱
Status PriorElem(DuLinkList L,ElemType cur_e,ElemType *pre_e)
{
    /* 操作结果：若 cur_e 是 L 的数据元素，且不是第一个，则用 pre_e 返回它的前
    驱， */
    /* 否则操作失败，pre_e 无定义 */
    DuLinkList p=L->next->next; /* p 指向第 2 个元素 */
    while(p!=L) /* p 没到表头 */
    {
        if(p->data==cur_e)
        {
            *pre_e=p->prior->data;
            return TRUE;
        }
        p=p->next;
    }
    return FALSE;
}
// 查找元素后继
Status NextElem(DuLinkList L,ElemType cur_e,ElemType *next_e)
{
    /* 操作结果：若 cur_e 是 L 的数据元素，且不是最后一个，则用 next_e 返回它的后
    继， */
    /* 否则操作失败，next_e 无定义 */
    DuLinkList p=L->next->next; /* p 指向第 2 个元素 */
    while(p!=L) /* p 没到表头 */
    {
        if(p->prior->data==cur_e)
        {
            *next_e=p->data;
            return TRUE;
        }
        p=p->next;
    }
    return FALSE;
}
// 查找元素地址
DuLinkList GetElemP(DuLinkList L,int i) /* 另加 */
{
    /* 在双向链表 L 中返回第 i 个元素的地址。i 为 0，返回头结点的地址。若第 i 个元
    素不存在，*/
    /* 返回 NULL */
    int j;
    DuLinkList p=L; /* p 指向头结点 */
    if(i<0||i>ListLength(L)) /* i 值不合法 */
        return NULL;
    for(j=1; j<=i; j++)
        p=p->next;
    return p;
}
// 元素的插入
Status ListInsert(DuLinkList L,int i,ElemType e)
{
    /* 在带头结点的双链循环线性表 L 中第 i 个位置之前插入元素 e，i 的合法值为 1≤i
    ≤表长+1 */
    /* 改进算法 2.18，否则无法在第表长+1 个结点之前插入元素 */
    DuLinkList p,s;
    if(i<1||i>ListLength(L)+1) /* i 值不合法 */
        return ERROR;
    p=GetElemP(L,i-1); /* 在 L 中确定第 i 个元素前驱的位置指针 p */
    if(!p) /* p=NULL,即第 i 个元素的前驱不存在(设头结点为第 1 个元素的前驱) */
        return ERROR;
    s=(DuLinkList)malloc(sizeof(DuLNode));
    if(!s)
        return OVERFLOW;
    s->data=e;
    s->prior=p; /* 在第 i-1 个元素之后插入 */
    s->next=p->next;
    p->next->prior=s;
    p->next=s;
    return OK;
}
// 元素的删除
Status ListDelete(DuLinkList L,int i,ElemType *e)
{
    /* 删除带头结点的双链循环线性表 L 的第 i 个元素，i 的合法值为 1≤i≤表长 */
    DuLinkList p;
    if(i<1) /* i 值不合法 */
        return ERROR;
    p=GetElemP(L,i); /* 在 L 中确定第 i 个元素的位置指针 p */
    if(!p) /* p=NULL,即第 i 个元素不存在 */
        return ERROR;
    *e=p->data;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    free(p);
    return OK;
}
// 正序查找
void ListTraverse(DuLinkList L,void(*visit)(ElemType))
{
    /* 由双链循环线性表 L 的头结点出发，正序对每个数据元素调用函数 visit() */
    DuLinkList p=L->next; /* p 指向头结点 */
    while(p!=L)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
}
void ListTraverseBack(DuLinkList L,void(*visit)(ElemType))
// 逆序查找
{
    /* 由双链循环线性表 L 的头结点出发，逆序对每个数据元素调用函数 visit()。另加
    */
    DuLinkList p=L->prior; /* p 指向尾结点 */
    while(p!=L)
    {
        visit(p->data);
        p=p->prior;
    }
    printf("\n");
}
