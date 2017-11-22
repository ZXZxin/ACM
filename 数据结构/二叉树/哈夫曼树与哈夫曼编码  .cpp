//哈夫曼树与哈夫曼编码

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct{//haffman 树的结构
    unsigned int weight;//叶子结点权值
    unsigned int parent; //指向双亲，和孩子结点的指针
    unsigned int lChild;
    unsigned int rChild;
} Node, *HuffmanTree;

typedef char *HuffmanCode;//动态分配数组，存储哈夫曼编码

//选择两个parent为0，且weight最小的结点s1和s2的方法实现
//n 为叶子结点的总数，s1和 s2两个指针参数指向要选取出来的两个权值最小的结点
void select(HuffmanTree *huffmanTree, int n, int *s1, int *s2){
    int min;  //记录最小权值
    //遍历全部结点，找出单节点
    for(int i = 1; i <= n; i++) if((*huffmanTree)[i].parent == 0){min = i; break;}
    //继续遍历全部结点，找出权值最小的单节点
    for(int i = 1; i <= n; i++)if((*huffmanTree)[i].parent == 0&&(*huffmanTree)[i].weight < (*huffmanTree)[min].weight) min = i;
    *s1 = min;    //找到了最小权值的结点，s1指向
    //找出下一个单节点，且没有被 s1指向，那么i 赋值给 min，跳出循环
    for(int i = 1; i <= n; i++)  if((*huffmanTree)[i].parent == 0 && i != (*s1)){ min = i;break;}
    for(int i = 1; i <= n; i++)if((*huffmanTree)[i].parent == 0 && i != (*s1)&&(*huffmanTree)[i].weight < (*huffmanTree)[min].weight)min = i;
    *s2 = min;    //s2指针指向第二个权值最小的叶子结点
}

//创建哈夫曼树并求哈夫曼编码的算法如下，w数组存放已知的n个权值
void createHuffmanTree(HuffmanTree *huffmanTree, int w[], int n)
{

    int m = 2 * n - 1;//m 为哈夫曼树总共的结点数，n 为叶子结点数
    int s1,s2;//s1 和 s2 为两个当前结点里，要选取的最小权值的结点
    *huffmanTree = (HuffmanTree)malloc((m + 1) * sizeof(Node));    // 创建哈夫曼树的结点所需的空间，m+1，代表其中包含一个头结点
    //1--n号存放叶子结点，初始化叶子结点，结构数组来初始化每个叶子结点，初始的时候看做一个个单个结点的二叉树
    for(int i = 1; i <= n; i++){
        (*huffmanTree)[i].weight = w[i];//其中叶子结点的权值是 w【n】数组来保存
        //初始化叶子结点（单个结点二叉树）的孩子和双亲，单个结点，也就是没有孩子和双亲，==0
        (*huffmanTree)[i].lChild = 0;
        (*huffmanTree)[i].parent = 0;
        (*huffmanTree)[i].rChild = 0;
    }
    for(int i = n + 1; i <= m; i++){    //非叶子结点的初始化
        (*huffmanTree)[i].weight = 0;
        (*huffmanTree)[i].lChild = 0;
        (*huffmanTree)[i].parent = 0;
        (*huffmanTree)[i].rChild = 0;
    }

    printf("\n HuffmanTree: \n");
    for(int i = n + 1; i <= m; i++){    //创建非叶子结点，建哈夫曼树
        //在(*huffmanTree)[1]~(*huffmanTree)[i-1]的范围内选择两个parent为0且weight最小的结点，其序号分别赋值给s1、s2
        select(huffmanTree, i-1, &s1, &s2);
        //选出的两个权值最小的叶子结点，组成一个新的二叉树，根为 i 结点
        (*huffmanTree)[s1].parent = i;
        (*huffmanTree)[s2].parent = i;
        (*huffmanTree)[i].lChild = s1;
        (*huffmanTree)[i].rChild = s2;
        (*huffmanTree)[i].weight = (*huffmanTree)[s1].weight + (*huffmanTree)[s2].weight; //新的结点 i 的权值
        printf("%d (%d, %d)\n", (*huffmanTree)[i].weight, (*huffmanTree)[s1].weight, (*huffmanTree)[s2].weight);
    }
    printf("\n");
}

//哈夫曼树建立完毕，从 n 个叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码
void creatHuffmanCode(HuffmanTree *huffmanTree, HuffmanCode *huffmanCode, int n){
    int start,p; //编码的起始指针和指向当前结点的父节点
    unsigned int c; //遍历 n 个叶子结点的指示标记 c
    huffmanCode=(HuffmanCode *)malloc((n+1) * sizeof(char *)); //分配n个编码的头指针
    char *cd = (char *)malloc(n * sizeof(char));   //分配求当前编码的工作空间
    cd[n-1] = '\0';  //从右向左逐位存放编码，首先存放编码结束符
    for(int i = 1; i <= n; i++){   //求n个叶子结点对应的哈夫曼编码
        start = n - 1; //初始化编码起始指针
        for(c = i, p = (*huffmanTree)[i].parent; p != 0; c = p, p = (*huffmanTree)[p].parent){ //从叶子到根结点求编码
            if( (*huffmanTree)[p].lChild == c)cd[--start] = '0';//从右到左的顺序编码入数组内左分支标0
            else cd[--start] = '1'; //右分支标1
        }
        huffmanCode[i] = (char *)malloc((n - start) * sizeof(char)); //为第i个编码分配空间
        strcpy(huffmanCode[i], &cd[start]);
    }
    free(cd);
    for(int i = 1; i <= n; i++) printf("HuffmanCode of %3d is %s\n", (*huffmanTree)[i].weight, huffmanCode[i]); //打印编码序列
    printf("\n");
}

int main(void){
    HuffmanTree HT;
    HuffmanCode HC;
    int *w,n,wei,m;
    printf("\nn = " );
    scanf("%d",&n);
    w = (int *)malloc((n+1)*sizeof(int));
    printf("\ninput the %d element's weight:\n",n);
    for(int i = 1; i <= n; i++){
        printf("%d: ",i);
        fflush(stdin);  //清空缓存区
        scanf("%d",&wei);
        w[i] = wei;
    }
    createHuffmanTree(&HT, w, n);
    creatHuffmanCode(&HT,&HC,n);
    return 0;
}
