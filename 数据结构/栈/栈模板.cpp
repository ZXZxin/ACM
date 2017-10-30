/*ջ��˳��洢��ʾ */
#define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������ */
#define STACK_INCREMENT 2 /* �洢�ռ�������� */
typedef struct SqStack
{
    SElemType *base; /* ��ջ����֮ǰ������֮��base ��ֵΪ NULL */
    SElemType *top; /* ջ��ָ�� */
    int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
} SqStack; /* ˳��ջ */
void InitStack(SqStack *S)
{
    /* ����һ����ջ S */
    (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!(*S).base)
        exit(OVERFLOW); /* �洢����ʧ�� */
    (*S).top=(*S).base;
    (*S).stacksize=STACK_INIT_SIZE;
}
void DestroyStack(SqStack *S)
{
    /* ����ջ S��S ���ٴ��� */
    free((*S).base);
    (*S).base=NULL;
    (*S).top=NULL;
    (*S).stacksize=0;
}
Status StackEmpty(SqStack S)
{
    /* ��ջ S Ϊ��ջ���򷵻� TRUE�����򷵻� FALSE */
    if(S.top==S.base)
        return TRUE;
    else
        return FALSE;
}
Status GetTop(SqStack S,SElemType *e)
{
    /* ��ջ���գ����� e ���� S ��ջ��Ԫ�أ������� OK�����򷵻� ERROR */
    if(S.top>S.base)
    {
        *e=*(S.top-1);
        return OK;
    }
    else
        return ERROR;
}
void Push(SqStack *S,SElemType e)
{
    /* ����Ԫ�� e Ϊ�µ�ջ��Ԫ�� */
    if((*S).top-(*S).base>=(*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
    {
        (*S).base=(SElemType
                   *)realloc((*S).base,((*S).stacksize+STACK_INCREMENT)*sizeof(SElemType));
        if(!(*S).base)
            exit(OVERFLOW); /* �洢����ʧ�� */
        (*S).top=(*S).base+(*S).stacksize;
        (*S).stacksize+=STACK_INCREMENT;
    }
    *((*S).top)++=e;
}
Status Pop(SqStack *S,SElemType *e)
{
    /* ��ջ���գ���ɾ�� S ��ջ��Ԫ�أ��� e ������ֵ�������� OK�����򷵻� ERROR
    */
    if((*S).top==(*S).base)
        return ERROR;
    *e=*--(*S).top;
    return OK;
}
