//题目链接：https://vjudge.net/contest/169966#problem/J
//题目大意：就是要你求水平方向的节点的权值的和（叶子掉到地上的和）
//解题思路：就是利用递归的思想，设置一个位置的标志pos，以及一个保存权值的数组，递归左子树，pos - 1,递归右子树pos + 1;直到计算出每个水平位置的权值

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int maxn = 1000 + 10;
int ans[maxn];

typedef struct node{
    int data;
    struct node *left,*right;
}BiNode,*BiTree;

BiTree Build(){//递归建树
    BiTree T = NULL;
    int x;
    T = (BiTree)malloc(sizeof(BiNode));
    scanf("%d",&x);
    if(x == -1)T = NULL;
    else {
        T->data = x;
        T->left = Build();
        T->right = Build();
    }
    return T;
}

void DFS(BiTree T,int pos){//一定要深刻理解递归的思想
    if(T == NULL)return;
    ans[pos] += T->data;
    DFS(T->left,pos - 1);
    DFS(T->right,pos + 1);
}

int main(){
    //freopen("in.txt","r",stdin);
    BiTree root;
    int kase = 0;
    while((root = Build()) != NULL){
        printf("Case %d:\n",++kase);
        memset(ans,0,sizeof(ans));
        DFS(root,40);
        int flag = 0;
        for(int i = 0; i < maxn; i++){
            if(ans[i] != 0 && flag == 0){
                printf("%d",ans[i]);
                flag = 1;
            }
            else if(ans[i] != 0 &&flag){
                printf(" %d",ans[i]);
            }
        }
        printf("\n\n");
    }
    return 0;
}


/*
数组实现：
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 1000+10;
int sum[maxn];
int L,R;

int read(int pos,int leaf){
    scanf("%d",&leaf);
    if( leaf != -1){
        sum[pos] += leaf;
        if(pos < L)L = pos;
        if(pos > R)R = pos;
        read(pos - 1,0);
        read(pos + 1,0);
    }
    return leaf;
}

int main(){
    freopen("in.txt","r",stdin);
    int kase = 0;
    while(read(L = R = 500,0) != -1){
        printf("Case %d:\n%d",++kase,sum[L]);
        for(int i = L + 1; i <= R; i++)printf(" %d",sum[i]);
        printf("\n\n");
        memset(sum,0,sizeof(sum));
    }
    return 0;
}
*/
