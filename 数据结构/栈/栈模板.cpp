/*栈的顺序存储表示 */
#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
#define STACK_INCREMENT 2 /* 存储空间分配增量 */
typedef struct SqStack
{
    SElemType *base; /* 在栈构造之前和销毁之后，base 的值为 NULL */
    SElemType *top; /* 栈顶指针 */
    int stacksize; /* 当前已分配的存储空间，以元素为单位 */
} SqStack; /* 顺序栈 */
void InitStack(SqStack *S)
{
    /* 构造一个空栈 S */
    (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!(*S).base)
        exit(OVERFLOW); /* 存储分配失败 */
    (*S).top=(*S).base;
    (*S).stacksize=STACK_INIT_SIZE;
}
void DestroyStack(SqStack *S)
{
    /* 销毁栈 S，S 不再存在 */
    free((*S).base);
    (*S).base=NULL;
    (*S).top=NULL;
    (*S).stacksize=0;
}
Status StackEmpty(SqStack S)
{
    /* 若栈 S 为空栈，则返回 TRUE，否则返回 FALSE */
    if(S.top==S.base)
        return TRUE;
    else
        return FALSE;
}
Status GetTop(SqStack S,SElemType *e)
{
    /* 若栈不空，则用 e 返回 S 的栈顶元素，并返回 OK；否则返回 ERROR */
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
    /* 插入元素 e 为新的栈顶元素 */
    if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
    {
        (*S).base=(SElemType
                   *)realloc((*S).base,((*S).stacksize+STACK_INCREMENT)*sizeof(SElemType));
        if(!(*S).base)
            exit(OVERFLOW); /* 存储分配失败 */
        (*S).top=(*S).base+(*S).stacksize;
        (*S).stacksize+=STACK_INCREMENT;
    }
    *((*S).top)++=e;
}
Status Pop(SqStack *S,SElemType *e)
{
    /* 若栈不空，则删除 S 的栈顶元素，用 e 返回其值，并返回 OK；否则返回 ERROR
    */
    if((*S).top==(*S).base)
        return ERROR;
    *e=*--(*S).top;
    return OK;
}
