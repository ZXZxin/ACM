//��Ŀ���ӣ�https://vjudge.net/contest/169966#problem/H
//��Ŀ���⣺���Ǹ���һ����������ͺ��򣬽�����Ȼ����Ӹ��ڵ㵽Ҷ�ӵ�·��Ȩֵ��С�ĺ�
//����˼·�������ȵݹ齨����Ȼ��DFS����

//����ǰ�������Լ�����ͺ�����������
//�ص�ѧϰ����:http://blog.csdn.net/u010667082/article/details/46274447
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

BiTree Build(int *inorder,int *post, int len){//��������ͺ����������������
    if(post == NULL||inorder == NULL||len <= 0)//�ݹ���ڳ���Ϊ0ʱ��ʾ�������
         return NULL;
    int p = 0,leftlen,rightlen;
    while(inorder[p] != post[len - 1])p++;
    BiTree root = new BiNode();//ÿ�ν������ڵ�
    root->value = post[len - 1];
    leftlen = p;//�������ĳ���
    rightlen = len - leftlen - 1;//�������ĳ���
    root->left = Build(inorder,post,leftlen);//����ͺ������߶���Ҫ��һ��ʼ��ʼ
    root->right = Build(inorder + leftlen + 1,post + leftlen ,rightlen);//������ұ�������Ҫ��leftlen + 1��ʼѰ�� ������ĵ��ұ�������leftlen��ʼ
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
    while(getchar() != '\n')scanf("%d",&inorder[index++]);//�����жϻ��еı�־
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
