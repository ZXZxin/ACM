#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
#define N 100
using namespace std;

const int maxn = 100 + 10;
const int STACK_INIT_SIZE = 100 + 10;
const int STACK_INCREMENT = 10;
typedef char datatype;

typedef struct node //二叉树结构定义
{
    datatype data;
    struct node *lchild,*rchild;
} BiNode;
typedef BiNode *BiTree;

typedef struct Seqqueue{
    int front,rear;
    BiTree data[maxn];
}Seqqueue;

typedef struct Sqstack{
    BiTree *base;
    BiTree *top;
    int stacksize;
}Sqstack;

bool InitStack(Sqstack &S){
    S.base = (BiTree *)malloc(STACK_INIT_SIZE*sizeof(BiTree));
    if(!S.base) return false;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return true;
}

bool IsstackEmpty(Sqstack &s){
    return s.top == s.base;
}

bool GetTop(Sqstack &S,BiTree &e){
    if(S.top == S.base) return false;
    e = *(S.top-1);
    return true;
}

bool Push(Sqstack &S,BiTree e){
    if(S.top - S.base >= S.stacksize){
        S.base = (BiTree *)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(BiTree));
    if(!S.base)return false;
    S.top = S.base+S.stacksize;
    S.stacksize += STACK_INCREMENT;
    }
    *S.top = e;
     S.top++;
    return true;
}

bool Pop(Sqstack &S,BiTree &e){
    if(S.base == S.top)return false;
    e = *(S.top-1);
    S.top--;
    //e = *--S.top;
    return true;
}

void initSeqqueue(Seqqueue &q){
    q.front = q.rear = 0;
}

void enqueue(Seqqueue &q,BiTree x){
    q.data[q.rear] = x;
    q.rear = (q.rear + 1) % maxn;
}

bool IsQueueEmpty(Seqqueue &q){
    return q.front == q.rear;
}

BiTree dequeue(Seqqueue &q){
    BiTree ch = q.data[q.front];
    q.front = (q.front + 1) % maxn;
    return ch;
}

BiTree creatBiTree()//先序遍历创建一颗二叉树
{
    char ch;
    BiTree t;
    scanf("%c",&ch);
    if  (ch=='#') t = NULL;
    else
    {
        t=(BiTree)malloc(sizeof(BiNode));
        t->data = ch;
        t->lchild = creatBiTree();
        t->rchild = creatBiTree();
    }
    return t;
}

void preorder(BiTree t){  /*前序递归遍历二叉树*/
    if (t){
        printf("%c",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void preorder_Nonrecursive(BiTree t){
    BiTree p = t;
    Sqstack s;
    InitStack(s);
    while(!IsstackEmpty(s)||p){
        if(p){
            Push(s,p);
            printf("%c",p->data);
            p = p->lchild;
        }
        else {
            Pop(s,p);
            p = p->rchild;
        }
    }
}

void preorder_Nonrecursive_1(BiTree t){
    BiTree p = t;
    Sqstack s;
    InitStack(s);
    while(!IsstackEmpty(s)||p){
        while(p){
            Push(s,p);
            printf("%c",p->data);
            p = p->lchild;
        }
        if(!IsstackEmpty(s)) {
            Pop(s,p);
            p = p->rchild;
        }
    }
}

void inorder(BiTree t){  //中序递归遍历二叉树
    if (t){
        inorder(t->lchild);
        printf("%c",t->data);
        inorder(t->rchild);
    }
}

void inorder_Nonrecursive(BiTree t){//中序非递归遍历二叉树
    BiTree p = t;
    Sqstack s;
    InitStack(s);
    while(!IsstackEmpty(s)||p){
        if(p){
            Push(s,p);
            p = p->lchild;
        }
        else {
            Pop(s,p);
            printf("%c",p->data);
            p = p->rchild;
        }
    }
}

void inorder_Nonrecursive_1(BiTree t){//中序非递归遍历二叉树
    BiTree p = t;
    Sqstack s;
    InitStack(s);
    while(!IsstackEmpty(s)||p){
        while(p){
            Push(s,p);
            p = p->lchild;
        }
        if(!IsstackEmpty(s)) {
            Pop(s,p);
            printf("%c",p->data);
            p = p->rchild;
        }
    }
}

void postorder(BiTree t){  //后序递归遍历二叉树
    if (t){
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%c",t->data);
    }
}

void postorder_Nonrecursive(BiTree t){//双栈法后续遍历
    Sqstack s1,s2;
    BiTree cur;
    InitStack(s1);
    InitStack(s2);
    Push(s1,t);
    while(!IsstackEmpty(s1)){
        Pop(s1,cur);
        Push(s2,cur);
        if(cur->lchild) Push(s1,cur->lchild);
        if(cur->rchild) Push(s1,cur->rchild);
    }
    while(!IsstackEmpty(s2)){
        Pop(s2,cur);
        printf("%c",cur->data);
    }
}

void postorder_Nonrecursive_1(BiTree t){
    Sqstack s;
    InitStack(s);
    BiTree cur,pre = NULL;//pre代表刚刚访问的结点，cur代表当前访问的结点
    Push(s,t);
    while(!IsstackEmpty(s)){
        GetTop(s,cur);
        if((!cur->lchild && !cur->rchild )||(pre && (pre == cur->lchild || pre == cur->rchild))){
            printf("%c",cur->data);//如果当前结点无左右子树则可以访问，或者左右孩子都已经访问也可以访问
            Pop(s,cur);
            pre = cur; //继续移动
        }
        else {
            if(cur->rchild) Push(s,cur->rchild);
            if(cur->lchild) Push(s,cur->lchild);
        }
    }
}

void levelorder(BiTree t){//递归层次遍历
    BiTree p = t;
    Seqqueue q;
    char str[maxn];
    initSeqqueue(q);
    int k = 0;
    enqueue(q,p);
    while(!IsQueueEmpty(q)){
        BiTree now = dequeue(q);
        str[k++] = now->data;
        if(now->lchild) enqueue(q,now->lchild);
        if(now->rchild) enqueue(q,now->rchild);
    }
    for(int i = 0; i < k; i++){
        printf("%c",str[i]);
    }
    printf("\n");
}

void levelorder_Nonrecursive(BiTree T)     //非递归层次遍历二叉树
{
    BiTree q[100];//定义队列有100个空间
    if (T == NULL)return;
    int front,rear;
    front = rear = 0;
    q[rear++] = T;
    while(front != rear)//如果队尾指针不等于对头指针时
    {
        printf("%c",q[front]->data);  //输出遍历结果
        if(q[front]->lchild != NULL)  //将队首结点的左孩子指针入队列
        {
            q[rear] = q[front]->lchild;
            rear++;    //队尾指针后移一位
        }
        if(q[front]->rchild != NULL)
        {
            q[rear] = q[front]->rchild;    //将队首结点的右孩子指针入队列
            rear++;   //队尾指针后移一位
        }
        front++;    //对头指针后移一位
    }
}

BiTree Search_Tree(BiTree t,datatype x){//二叉树结点值的查找
    if(!t)return NULL;
    if(t->data == x){
        return t;
    }
    else {
        if(!Search_Tree(t->lchild,x))return Search_Tree(t->rchild,x);
        return t;
    }
}

int CountNode(BiTree t){  //二叉树统计结点个数
    if(t)return CountNode(t->lchild)+CountNode(t->rchild)+1;
}

int depth(BiTree t){  //求二叉树的深度
    if(!t)return 0;
    int left,right;
    left = depth(t->lchild);
    right = depth(t->rchild);
    return left > right ? left + 1 : right + 1;
}

bool is_equal(BiTree t1,BiTree t2){
    if(!t1&&!t2)return true;
    else {
        if(t1 && t2 && t1->data == t2->data){
            if(is_equal(t1->lchild,t2->lchild))
                if(is_equal(t1->rchild,t2->rchild))
                return true;
        }
    }
    return false;
}

int main()
{
    BiTree t = NULL;
    printf("请按先序遍历的顺序输入二叉树：\n");
    t=creatBiTree();

    printf("二叉树的递归前序序列为：\n");
    preorder(t);
    printf("\n");
    printf("二叉树的非递归前序序列为：\n");
    preorder_Nonrecursive(t);
    printf("\n\n");

    printf("二叉树的递归中序序列为：\n");
    inorder(t);
    printf("\n");
    printf("二叉树的非递归中序序列为：\n");
    inorder_Nonrecursive(t);
    printf("\n\n");

    printf("二叉树的递归后续遍历为：\n");
    postorder(t);
    printf("\n");
    printf("二叉树的非递归后续遍历为：\n");
    postorder_Nonrecursive(t);
    printf("\n\n");

    printf("二叉树的递归层次遍历为：\n");
    levelorder(t);
    printf("二叉树的非递归层次遍历为：\n");
    levelorder_Nonrecursive(t);
    printf("\n\n");

    printf("二叉树的结点个数为：\n");
    printf("%d",CountNode(t));
    printf("\n\n");

    printf("二叉树的深度为：\n");
    printf("%d",depth(t));
    printf("\n\n");

    return 0;
}


//测试数据：//ABC##D#E##F##
