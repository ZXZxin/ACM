#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int QElemType;
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode,*QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;
int InitQueue(LinkQueue *Q);
int DestroyQueue(LinkQueue *Q);
int ClearQueue(LinkQueue *Q);
int QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
int GetHead(LinkQueue Q,QElemType *e);
int InsertQueue(LinkQueue *Q,QElemType e);
int DelQueue(LinkQueue *Q,QElemType *e);
int PrintQueue(LinkQueue Q);
int InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr )malloc(sizeof(QNode));
    if(!Q->front)
    {
        perror("malloc error\n");
        return -1;
    }
    Q->front->next = NULL;
    Q->front->data = 0;
    return 0;
}
int DestroyQueue(LinkQueue *Q)
{
    while(Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    Q = NULL;
    return 0;
}
int ClearQueue(LinkQueue *Q)
{
    return 0;
}
int QueueEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int QueueLength(LinkQueue Q)
{
    return Q.front->data;
}
int GetHead(LinkQueue Q,QElemType *e)
{
    if(Q.front->next == NULL)
    {
        perror("Queue is empty!\n");
        *e = -1;
        return -1;
    }
    *e = Q.front->next->data;
    return 0;
}
int InsertQueue(LinkQueue *Q,QElemType e)
{
    QueuePtr p = (QueuePtr )malloc(sizeof(QNode));
    if(p == NULL)
    {
        perror("malloc error!\n");
        return -1;
    }
    p->data = e;
    p->next = NULL;
    (Q->rear)->next = p;
    Q->rear = p;
    Q->front->data++;
    return 0;
}
int DelQueue(LinkQueue *Q,QElemType *e)
{
    if(Q->front == Q->rear)
    {
        perror("The queue is empty!");
        return -1;
    }
    QueuePtr p = (QueuePtr )malloc(sizeof(QNode));
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p)
    {
        Q->rear = Q->front;
    }
    free(p);
    Q->front->data--;
    return 0;
}
int PrintQueue(LinkQueue Q)
{
    Q.front = Q.front->next;
    while(Q.front != NULL)
    {
        printf("%d-----",Q.front->data);
        Q.front = Q.front->next;
    }
    return 0;
}
