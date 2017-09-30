#include <stdio.h>
#include <stdlib.h>
typedef struct CLNode
{
    int data;
    struct CLNode* next;
} CLNode,*CLinkList;
void InitCL(CLinkList CL)
{
    if(CL!=NULL)
        CL->next=CL;
    else
        CL=(CLinkList)malloc(sizeof(CLNode));
}
void InsertFront(CLinkList CL,int value)
{
    CLinkList p;
    p=(CLinkList)malloc(sizeof(CLNode));
    p->data=value;
    p->next=CL->next;
    CL->next=p;
}
void InsertEnd(CLinkList CL,int value)
{
    CLinkList p,q;
    p=(CLinkList)malloc(sizeof(CLNode));
    p->data=value;
    q=CL;
    while(q->next!=CL)
    {
        q=q->next;
    }
    p->next=q->next;
    q->next=p;
}
void Print(CLinkList CL)
{
    CLinkList p;
    p=CL->next;
    while(p!=CL)
    {
        printf("%d/t",p->data);
        p=p->next;
    }
    printf("/n");
}

void DeleteFront(CLinkList CL,int *val)
{
    CLinkList p;
    p=CL->next;
    if(p!=CL)
    {
        CL->next=p->next;
        *val=p->data;
    }
    else
        printf("LinkList is empty!/n");
}
void DeleteEnd(CLinkList CL,int *val)
{
    CLinkList p,q;
    q=CL;
    p=CL->next;
    if(p!=CL)
    {
        while(p->next!=CL)
        {
            q=p;
            p=p->next;
        }
        *val=p->data;
        q->next=p->next;
    }
    else
        printf("LinkList is empty!/n");
}
int main()
{
    CLinkList ML;
    int i,res;
    ML=(CLinkList)malloc(sizeof(CLNode));
    InitCL(ML);
    DeleteFront(ML,&res);
    DeleteEnd(ML,&res);
    for(i=1; i<=8; i++)
    {
        InsertFront(ML,i+38);
        InsertEnd(ML,i+100);
    }
    Print(ML);
    DeleteFront(ML,&res);
    printf("%d is deleted from linklist./n",res);
    DeleteEnd(ML,&res);
    printf("%d is deleted from linklist./n",res);
    Print(ML);
    printf("Hello, world/n");
    getchar();
    return 0;
}
