typedef struct DuLNode
{
//�Լ������������͡�
    ElemType data;
    struct DuLNode *prior,*next;
} DuLNode,*DuLinkList;
// ��ͷ����˫��ѭ������Ļ�������
void InitList(DuLinkList *L)
{
    /* �����յ�˫��ѭ������ L */
    *L=(DuLinkList)malloc(sizeof(DuLNode));
    if(*L)
        (*L)->next=(*L)->prior=*L;
    else
        exit(OVERFLOW);
}
void DestroyList(DuLinkList *L)
// ����˫��ѭ������ L
{
    DuLinkList q,p=(*L)->next; /* p ָ���һ����� */
    while(p!=*L) /* p û����ͷ */
    {
        q=p->next;
        free(p);
        p=q;
    }
    free(*L);
    *L=NULL;
}
// ��������Ϊ�ձ�
void ClearList(DuLinkList L) /* ���ı� L */
{
    DuLinkList q,p=L->next; /* p ָ���һ����� */
    while(p!=L) /* p û����ͷ */
    {
        q=p->next;
        free(p);
        p=q;

    }
    L->next=L->prior=L; /* ͷ��������ָ�����ָ������ */
}
// ��֤�Ƿ�Ϊ�ձ�
Status ListEmpty(DuLinkList L)
{
    /* ��ʼ���������Ա� L �Ѵ���*/
    if(L->next==L&&L->prior==L)
        return TRUE;
    else
        return FALSE;
}
// �������Ԫ�ظ���
int ListLength(DuLinkList L)
{
    /* ��ʼ������L �Ѵ��ڡ���������� */
    int i=0;
    DuLinkList p=L->next; /* p ָ���һ����� */
    while(p!=L) /* p û����ͷ */
    {
        i++;
        p=p->next;
    }
    return i;
}
// ��ֵ
Status GetElem(DuLinkList L,int i,ElemType *e)
{
    /* ���� i ��Ԫ�ش���ʱ����ֵ���� e ������ OK�����򷵻� ERROR */
    int j=1; /* j Ϊ������ */
    DuLinkList p=L->next; /* p ָ���һ����� */
    while(p!=L&&jnext)
    {
        j++;
    }
    if(p==L||j>i) /* �� i ��Ԫ�ز����� */
        return ERROR;
    *e=p->data; /* ȡ�� i ��Ԫ�� */
    return OK;
}
// ����Ԫ��
int LocateElem(DuLinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
    /* ��ʼ������L �Ѵ��ڣ�compare()������Ԫ���ж����� */
    /* ������������� L �е� 1 ���� e �����ϵ compare()������Ԫ�ص�λ�� */
    /* ������������Ԫ�ز����ڣ��򷵻�ֵΪ 0 */
    int i=0;
    DuLinkList p=L->next; /* p ָ��� 1 ��Ԫ�� */
    while(p!=L)
    {
        i++;
        if(compare(p->data,e)) /* �ҵ�����������Ԫ�� */
            return i;
        p=p->next;
    }
    return 0;
}
// ����Ԫ��ǰ��
Status PriorElem(DuLinkList L,ElemType cur_e,ElemType *pre_e)
{
    /* ����������� cur_e �� L ������Ԫ�أ��Ҳ��ǵ�һ�������� pre_e ��������ǰ
    ���� */
    /* �������ʧ�ܣ�pre_e �޶��� */
    DuLinkList p=L->next->next; /* p ָ��� 2 ��Ԫ�� */
    while(p!=L) /* p û����ͷ */
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
// ����Ԫ�غ��
Status NextElem(DuLinkList L,ElemType cur_e,ElemType *next_e)
{
    /* ����������� cur_e �� L ������Ԫ�أ��Ҳ������һ�������� next_e �������ĺ�
    �̣� */
    /* �������ʧ�ܣ�next_e �޶��� */
    DuLinkList p=L->next->next; /* p ָ��� 2 ��Ԫ�� */
    while(p!=L) /* p û����ͷ */
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
// ����Ԫ�ص�ַ
DuLinkList GetElemP(DuLinkList L,int i) /* ��� */
{
    /* ��˫������ L �з��ص� i ��Ԫ�صĵ�ַ��i Ϊ 0������ͷ���ĵ�ַ������ i ��Ԫ
    �ز����ڣ�*/
    /* ���� NULL */
    int j;
    DuLinkList p=L; /* p ָ��ͷ��� */
    if(i<0||i>ListLength(L)) /* i ֵ���Ϸ� */
        return NULL;
    for(j=1; j<=i; j++)
        p=p->next;
    return p;
}
// Ԫ�صĲ���
Status ListInsert(DuLinkList L,int i,ElemType e)
{
    /* �ڴ�ͷ����˫��ѭ�����Ա� L �е� i ��λ��֮ǰ����Ԫ�� e��i �ĺϷ�ֵΪ 1��i
    �ܱ�+1 */
    /* �Ľ��㷨 2.18�������޷��ڵڱ�+1 �����֮ǰ����Ԫ�� */
    DuLinkList p,s;
    if(i<1||i>ListLength(L)+1) /* i ֵ���Ϸ� */
        return ERROR;
    p=GetElemP(L,i-1); /* �� L ��ȷ���� i ��Ԫ��ǰ����λ��ָ�� p */
    if(!p) /* p=NULL,���� i ��Ԫ�ص�ǰ��������(��ͷ���Ϊ�� 1 ��Ԫ�ص�ǰ��) */
        return ERROR;
    s=(DuLinkList)malloc(sizeof(DuLNode));
    if(!s)
        return OVERFLOW;
    s->data=e;
    s->prior=p; /* �ڵ� i-1 ��Ԫ��֮����� */
    s->next=p->next;
    p->next->prior=s;
    p->next=s;
    return OK;
}
// Ԫ�ص�ɾ��
Status ListDelete(DuLinkList L,int i,ElemType *e)
{
    /* ɾ����ͷ����˫��ѭ�����Ա� L �ĵ� i ��Ԫ�أ�i �ĺϷ�ֵΪ 1��i�ܱ� */
    DuLinkList p;
    if(i<1) /* i ֵ���Ϸ� */
        return ERROR;
    p=GetElemP(L,i); /* �� L ��ȷ���� i ��Ԫ�ص�λ��ָ�� p */
    if(!p) /* p=NULL,���� i ��Ԫ�ز����� */
        return ERROR;
    *e=p->data;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    free(p);
    return OK;
}
// �������
void ListTraverse(DuLinkList L,void(*visit)(ElemType))
{
    /* ��˫��ѭ�����Ա� L ��ͷ�������������ÿ������Ԫ�ص��ú��� visit() */
    DuLinkList p=L->next; /* p ָ��ͷ��� */
    while(p!=L)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
}
void ListTraverseBack(DuLinkList L,void(*visit)(ElemType))
// �������
{
    /* ��˫��ѭ�����Ա� L ��ͷ�������������ÿ������Ԫ�ص��ú��� visit()�����
    */
    DuLinkList p=L->prior; /* p ָ��β��� */
    while(p!=L)
    {
        visit(p->data);
        p=p->prior;
    }
    printf("\n");
}
