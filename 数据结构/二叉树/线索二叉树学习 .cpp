//����������
//ѧϰ���ͣ���1��http://blog.csdn.net/zhouzixin053/article/details/21647019
          //��2��http://blog.csdn.net/u014492609/article/details/40477795


#include <stdio.h>
#include <stdlib.h>

typedef char datatype;

//�����洢��־λ
// Link(0)����ʾָ�����Һ��ӵ�ָ��
// Thread(1)����ʾָ��ǰ����̵�����
typedef enum{Link,Thread} PointerTag;//����ö�����͵ĳ���

typedef struct BiThrNode{   //���������������Ľṹ��
    datatype data;
    struct BiThrNode *lchild,*rchild;
    PointerTag ltag;
    PointerTag rtag;
}BiThrNode,*BiThrTree;

BiThrTree pre;// ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��

void CreatBiThrTree(BiThrTree *T){
    datatype c;
    scanf("%c",&c);
    if(c == '#')*T = NULL;
    else {
        *T = (BiThrTree)malloc(sizeof(BiThrNode));
        (*T)->data = c;
        (*T)->ltag = Link; //��ʼ����Ϊ��������
        (*T)->rtag = Link;
        CreatBiThrTree(&(*T)->lchild);
        CreatBiThrTree(&(*T)->rchild);
    }
}

void InThreading(BiThrTree T){   //�������������
    if(T){
        InThreading(T->lchild);  // �ݹ�����������
        if(!T->lchild){    // ����ý��û�����ӣ�����ltagΪThread������lchildָ��ոշ��ʵĽ�㡣
            T->ltag = Thread;
            T->lchild = pre;
        }
        if(!pre->rchild){
            pre->rtag = Thread;
            pre->rchild = T;
        }
        pre = T;
        InThreading(T->rchild);   // �ݹ��Һ���������
    }
}

void InOrderThreading(BiThrTree *p,BiThrTree T){  //�ȴ���һ��ͷ��㣨ָ�����㣩
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
        p = p->rchild; //ת��������
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    BiThrTree P,T = NULL;
    CreatBiThrTree(&T);
    InOrderThreading(&P,T);
    printf("�����������ǣ�");
    InOrderTraverse(P);
    printf("\n");
    return 0;
}
