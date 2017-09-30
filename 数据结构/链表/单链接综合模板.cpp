#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//��ϵ�˽ڵ�ṹ��
typedef struct _LinkNode
{
    char name[9]; //����
    char phone[14]; //�绰
    struct _LinkNode* next; //��һ����ϵ��ָ��
} LinkNode;
//��ʼ������
LinkNode* InitList()
{
    LinkNode* head = NULL;
    head = (LinkNode*)malloc(sizeof(LinkNode));
    if(head == NULL)
    {
        printf("�ڴ����ʧ��\n");
        return NULL;
    }
//��ʼ�� ����ָ����һ�ڵ�ָ���ÿ�
    memset(head, 0, sizeof(LinkNode));
    head->next = NULL;
    return head;
}
//ȡԪ�ز�����i Ϊ��Ҫȡ��Ԫ������
LinkNode* GetElem(LinkNode* ls, int i)
{
    LinkNode* temp = NULL;
    int j = 0;
    if(ls == NULL)
    {
        printf("ͷ��㲻����\n");
        return NULL;
    }
    if(i < 1)
    {
        printf("�����������\n");
        return NULL;
    }
//temp ָ���һ��Ԫ��
    temp = ls->next;
    j = 1;
//ѭ���ҵ��� i ��Ԫ��
    while(temp != NULL && j < i)
    {
        temp = temp->next;
        j++;
    }
//�� i ��Ԫ��Ϊ�� ���� Ԫ���������� i
    if(temp == NULL || j != i)
    {
        printf("Ԫ�ز�����\n");
        return NULL;
    }
    return temp;
}
//������Ԫ�ص��� i ��λ��֮ǰ
void InsertElem(LinkNode* ls, int i, LinkNode* elem)
{
    LinkNode* temp = NULL;
    LinkNode* newnode = NULL;
    int j = 0;
    if(ls == NULL)
    {
        printf("���Ա�����\n");
        return ;
    }
    if(i < 1)
    {
        printf("�����������\n");
        return ;
    }
    if(elem == NULL)
    {
        printf("������Ԫ�ز�����");
        return ;
    }
    temp = ls;
    j = 1;
//Ѱ�ҵ� i-1 ���ڵ�
    while(temp != NULL && j < i)
    {
        temp = temp->next;
        j++;
    }

    if(j < i - 1)
    {
        printf("��%d ��Ԫ�ز�����\n", i - 1);
        return ;
    }
//Ϊ�½ڵ�����ڴ�

    newnode = (LinkNode*)malloc(sizeof(LinkNode));
    if(newnode == NULL)
    {
        printf("�ڴ����ʧ��\n");
        return ;
    }
    memcpy(newnode, elem, sizeof(LinkNode));

    newnode->next = temp->next;
    temp->next = newnode;
}
//��������
void DestroyList(LinkNode* ls)
{
    LinkNode* temp = NULL;
    LinkNode* next = NULL;
    if(ls == NULL)
    {
        printf("��������\n");
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
//�����������
void TravList(LinkNode* ls)
{
    LinkNode* temp = NULL;
    if(ls == NULL)
    {
        printf("��������\n");

        return ;
    }
    temp = ls->next;
    while(temp != NULL)
    {
        PrintNode(temp);
        temp = temp->next;
    }
}
//ɾ��Ԫ��
LinkNode DeleteElem(LinkNode* ls, int i)
{
    LinkNode ret = {"", "", NULL};
    LinkNode* temp = NULL;
    LinkNode* del = NULL;
    int j = 0;
    if(ls == NULL)
    {
        printf("��������\n");
        return ret;
    }
    if(i < 1)
    {
        printf("�����������\n");
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
        printf("��%d ��Ԫ�ز�����\n", i - 1);
        return ret;
    }
    if(temp->next == NULL)
    {
        printf("��%d ��Ԫ�ز�����\n", i);
        return ret;
    }

//�޸� i-1 Ԫ�ص�ָ�� ָ�� i ����һλ�ã� ������ i ��Ԫ����Ϣ�� ret �У�Ȼ��˵ɾ��
    //�� i ��Ԫ��
    del = temp->next;
    temp->next = del->next;
    memcpy(&ret, temp->next, sizeof(LinkNode));
    free(del);

    return ret;
}
//�޸ĵ� i ��Ԫ��
void ModifyElem(LinkNode* ls, int i, LinkNode* mod)
{
    LinkNode* temp = NULL;
    int j = 0;
    if(ls == NULL || mod == NULL || i < 1)
    {
        printf("������Ч\n");
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
        printf("��%d ��Ԫ�ز�����\n", i);
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
//��ʼ������
    head = InitList();
    if(head == NULL)
        return 1;
//�������
    for(i = 0; i < 20; i++)
    {
        sprintf(temp.name, "stu%03d", i + 1);
        sprintf(temp.phone, "1311122%04d", i + 10);
        InsertElem(head, i + 1, &temp);
    }
    TravList(head);
//���Ҳ�����֤ ����Ԫ��
    printf("\n �ֱ���ҵ� 1,20,10,21 ��Ԫ��\n");
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

//ɾ��Ԫ����֤
    printf("\n ɾ��Ԫ����֤\n");
    DeleteElem(head, 1);
    DeleteElem(head, 10);
    DeleteElem(head, 20);
    DeleteElem(head, 21);
    TravList(head);
//�޸�Ԫ����֤
    printf("\n �޸�Ԫ����֤\n");
    strcpy(temp.name, "mod");
    strcpy(temp.phone, "123");
    ModifyElem(head, 0, &temp);
    ModifyElem(head, 1, &temp);
    ModifyElem(head, 10, &temp);
    ModifyElem(head, 18, &temp);
    ModifyElem(head, 21, &temp);
    TravList(head);
//��������
    DestroyList(head);
    return 0;
}
