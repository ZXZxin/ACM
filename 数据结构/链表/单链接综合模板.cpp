#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//联系人节点结构体
typedef struct _LinkNode
{
    char name[9]; //姓名
    char phone[14]; //电话
    struct _LinkNode* next; //下一个联系人指针
} LinkNode;
//初始化操作
LinkNode* InitList()
{
    LinkNode* head = NULL;
    head = (LinkNode*)malloc(sizeof(LinkNode));
    if(head == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }
//初始化 将其指向下一节点指针置空
    memset(head, 0, sizeof(LinkNode));
    head->next = NULL;
    return head;
}
//取元素操作，i 为需要取的元素排序
LinkNode* GetElem(LinkNode* ls, int i)
{
    LinkNode* temp = NULL;
    int j = 0;
    if(ls == NULL)
    {
        printf("头结点不存在\n");
        return NULL;
    }
    if(i < 1)
    {
        printf("参数输入错误\n");
        return NULL;
    }
//temp 指向第一个元素
    temp = ls->next;
    j = 1;
//循环找到第 i 个元素
    while(temp != NULL && j < i)
    {
        temp = temp->next;
        j++;
    }
//第 i 个元素为空 或者 元素数量少于 i
    if(temp == NULL || j != i)
    {
        printf("元素不存在\n");
        return NULL;
    }
    return temp;
}
//插入新元素到第 i 个位置之前
void InsertElem(LinkNode* ls, int i, LinkNode* elem)
{
    LinkNode* temp = NULL;
    LinkNode* newnode = NULL;
    int j = 0;
    if(ls == NULL)
    {
        printf("线性表不存在\n");
        return ;
    }
    if(i < 1)
    {
        printf("参数输入错误\n");
        return ;
    }
    if(elem == NULL)
    {
        printf("待插入元素不存在");
        return ;
    }
    temp = ls;
    j = 1;
//寻找第 i-1 个节点
    while(temp != NULL && j < i)
    {
        temp = temp->next;
        j++;
    }

    if(j < i - 1)
    {
        printf("第%d 个元素不存在\n", i - 1);
        return ;
    }
//为新节点分配内存

    newnode = (LinkNode*)malloc(sizeof(LinkNode));
    if(newnode == NULL)
    {
        printf("内存分配失败\n");
        return ;
    }
    memcpy(newnode, elem, sizeof(LinkNode));

    newnode->next = temp->next;
    temp->next = newnode;
}
//销毁链表
void DestroyList(LinkNode* ls)
{
    LinkNode* temp = NULL;
    LinkNode* next = NULL;
    if(ls == NULL)
    {
        printf("链表不存在\n");
        return ;
    }
    temp = ls;
    while(temp != NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
}
void PrintNode(LinkNode* elem)
{
    if(elem == NULL)
        return ;
    printf("%8s %13s\n", elem->name, elem->phone);
}
//遍历输出链表
void TravList(LinkNode* ls)
{
    LinkNode* temp = NULL;
    if(ls == NULL)
    {
        printf("链表不存在\n");

        return ;
    }
    temp = ls->next;
    while(temp != NULL)
    {
        PrintNode(temp);
        temp = temp->next;
    }
}
//删除元素
LinkNode DeleteElem(LinkNode* ls, int i)
{
    LinkNode ret = {"", "", NULL};
    LinkNode* temp = NULL;
    LinkNode* del = NULL;
    int j = 0;
    if(ls == NULL)
    {
        printf("链表不存在\n");
        return ret;
    }
    if(i < 1)
    {
        printf("输入参数错误\n");
        return ret;
    }
    temp = ls;
    j = 1;
    while(temp != NULL && j < i)
    {
        temp = temp->next;
        j++;
    }
    if(temp == NULL || j != i)
    {
        printf("第%d 个元素不存在\n", i - 1);
        return ret;
    }
    if(temp->next == NULL)
    {
        printf("第%d 个元素不存在\n", i);
        return ret;
    }

//修改 i-1 元素的指针 指向 i 的下一位置， 拷贝第 i 个元素信息到 ret 中，然后说删除
    //第 i 个元素
    del = temp->next;
    temp->next = del->next;
    memcpy(&ret, temp->next, sizeof(LinkNode));
    free(del);

    return ret;
}
//修改第 i 个元素
void ModifyElem(LinkNode* ls, int i, LinkNode* mod)
{
    LinkNode* temp = NULL;
    int j = 0;
    if(ls == NULL || mod == NULL || i < 1)
    {
        printf("参数无效\n");
        return ;
    }
    temp = ls->next;
    j = 1;
    while(temp != NULL && j < i)
    {
        temp = temp->next;
        j++;
    }
    if(temp == NULL || j != i)
    {
        printf("第%d 个元素不存在\n", i);
        return ;
    }
    strcpy(temp->name, mod->name);
    strcpy(temp->phone, mod->phone);
}
int main()
{
    LinkNode* head = NULL;
    int i = 0;
    LinkNode temp;
    LinkNode* result;
//初始化链表
    head = InitList();
    if(head == NULL)
        return 1;
//链表操作
    for(i = 0; i < 20; i++)
    {
        sprintf(temp.name, "stu%03d", i + 1);
        sprintf(temp.phone, "1311122%04d", i + 10);
        InsertElem(head, i + 1, &temp);
    }
    TravList(head);
//查找操作验证 查找元素
    printf("\n 分别查找第 1,20,10,21 个元素\n");
    result = GetElem(head, 1);
    if(result != NULL)
    {
        printf("%8s %13s\n", result->name, result->phone);
    }
    result = GetElem(head, 20);
    if(result != NULL)
    {
        printf("%8s %13s\n", result->name, result->phone);
    }
    result = GetElem(head, 10);
    if(result != NULL)
    {
        printf("%8s %13s\n", result->name, result->phone);
    }
    result = GetElem(head, 21);
    if(result != NULL)
    {
        printf("%8s %13s\n", result->name, result->phone);
    }
    result = GetElem(head, -1);
    if(result != NULL)
    {
        printf("%8s %13s\n", result->name, result->phone);
    }

//删除元素验证
    printf("\n 删除元素验证\n");
    DeleteElem(head, 1);
    DeleteElem(head, 10);
    DeleteElem(head, 20);
    DeleteElem(head, 21);
    TravList(head);
//修改元素验证
    printf("\n 修改元素验证\n");
    strcpy(temp.name, "mod");
    strcpy(temp.phone, "123");
    ModifyElem(head, 0, &temp);
    ModifyElem(head, 1, &temp);
    ModifyElem(head, 10, &temp);
    ModifyElem(head, 18, &temp);
    ModifyElem(head, 21, &temp);
    TravList(head);
//销毁链表
    DestroyList(head);
    return 0;
}
