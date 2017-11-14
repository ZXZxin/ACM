//线索二叉树
//学习博客：（1）http://blog.csdn.net/zhouzixin053/article/details/21647019
          //（2）http://blog.csdn.net/u014492609/article/details/40477795


#include <stdio.h>
#include <stdlib.h>

typedef char datatype;

//线索存储标志位
// Link(0)：表示指向左右孩子的指针
// Thread(1)：表示指向前驱后继的线索
typedef enum{Link,Thread} PointerTag;//定义枚举类型的常量

typedef struct BiThrNode{   //定义线索二叉树的结构体
    datatype data;
    struct BiThrNode *lchild,*rchild;
    PointerTag ltag;
    PointerTag rtag;
}BiThrNode,*BiThrTree;

BiThrTree pre;// 全局变量，始终指向刚刚访问过的结点

void CreatBiThrTree(BiThrTree *T){
    datatype c;
    scanf("%c",&c);
    if(c == '#')*T = NULL;
    else {
        *T = (BiThrTree)malloc(sizeof(BiThrNode));
        (*T)->data = c;
        (*T)->ltag = Link; //初始设置为左右子树
        (*T)->rtag = Link;
        CreatBiThrTree(&(*T)->lchild);
        CreatBiThrTree(&(*T)->rchild);
    }
}

void InThreading(BiThrTree T){   //中序遍历线索化
    if(T){
        InThreading(T->lchild);  // 递归左孩子线索化
        if(!T->lchild){    // 如果该结点没有左孩子，设置ltag为Thread，并把lchild指向刚刚访问的结点。
            T->ltag = Thread;
            T->lchild = pre;
        }
        if(!pre->rchild){
            pre->rtag = Thread;
            pre->rchild = T;
        }
        pre = T;
        InThreading(T->rchild);   // 递归右孩子线索化
    }
}

void InOrderThreading(BiThrTree *p,BiThrTree T){  //先创建一个头结点（指向根结点）
    *p = (BiThrTree)malloc(sizeof(BiThrNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;
    if(!T)(*p)->lchild = *p;
    else {
        (*p)->lchild = T;
        pre = *p;
        InThreading(T);
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
}

void InOrderTraverse(BiThrTree T){
    BiThrTree p = T->lchild;
    while(p != T){
        while(p->ltag == Link){
            p = p->lchild;
        }
        printf("%c",p->data);
        while(p->rtag == Thread && p->rchild != T){
            p = p->rchild;
            printf("%c",p->data);
        }
        p = p->rchild; //转到右子树
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    BiThrTree P,T = NULL;
    CreatBiThrTree(&T);
    InOrderThreading(&P,T);
    printf("中序遍历结果是；");
    InOrderTraverse(P);
    printf("\n");
    return 0;
}
