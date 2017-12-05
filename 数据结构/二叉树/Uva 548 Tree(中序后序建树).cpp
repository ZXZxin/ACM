//题目链接：https://vjudge.net/contest/169966#problem/H
//题目大意：就是给你一棵二叉树的中序和后续遍历，要你建树之后求出从根到叶子的最小的权值和
//解题思路：根据题目建树，然后DFS遍历求解即可

//根据前序中序，以及中序和后序建立二叉树
//学习博客:http://blog.csdn.net/u010667082/article/details/46274447
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 10000+10;
const int INF = 10000000000;

typedef struct node{
    int value;
    struct node *left,*right;
}BiNode,*BiTree;

int inorder[maxn],post[maxn];
int best,best_sum;

BiTree Build(int *inorder,int *post, int len){//根据中序和后序遍历建立二叉树
    if(post == NULL||inorder == NULL||len <= 0)//递归出口长度为0时表示建树完毕
         return NULL;
    int p = 0,leftlen,rightlen;
    while(inorder[p] != post[len - 1])p++;
    BiTree root = new BiNode();//每次建立根节点
    root->value = post[len - 1];
    leftlen = p;//左子树的长度
    rightlen = len - leftlen - 1;//右子树的长度
    root->left = Build(inorder,post,leftlen);//中序和后序的左边都是要从一开始开始
    root->right = Build(inorder + leftlen + 1,post + leftlen ,rightlen);//中序的右边子树是要从leftlen + 1开始寻找 ，后序的的右边子树从leftlen开始
    return root;
}

void DFS(BiTree T,int sum){
    sum += T->value;
    //cout<<sum<<endl;
    if(T->left == NULL && T->right == NULL){
        if(sum < best_sum || (sum == best_sum && T->value < best)){best_sum = sum; best = T->value;}
    }
    if(T->left)DFS(T->left,sum);
    if(T->right)DFS(T->right,sum);
}

int input(){
    int index = 1;
    while(getchar() != '\n')scanf("%d",&inorder[index++]);//输入判断换行的标志
    for(int i = 0; i < index; i++)scanf("%d",&post[i]);
    return index;
}

int main(){
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&inorder[0]) != EOF){
        int len = input();
        best_sum = INF;
        BiTree root = new BiNode();
        root = Build(inorder,post,len);
        DFS(root,0);
        printf("%d\n",best);
    }

    return 0;
}

