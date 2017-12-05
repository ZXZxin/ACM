//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=5444
//题目大意：就是按照题目给的建树规则，建立相应的二叉树，然后相应的节点，向左搜素输出"E",向右搜素输出“W",而这个建树规则就是二叉搜素树的建树规则
//解题思路:直接模拟即可;掌握二叉查找树的基本算法


#include<stdio.h>
#include<algorithm>
using namespace std;

struct BiNode{
    int value;
    BiNode *left,*right;
};

void Remove(BiNode *p){
    if(p == NULL) return;
    Remove(p->left);
    Remove(p->right);
    free(p);
}

BiNode *Creat(BiNode *p,int x){
    if(p == NULL){
        BiNode *q = new BiNode;
        q->value = x;
        q->left = q->right = NULL;
        return q;
    }
    else{
        if(x < p->value) p->left = Creat(p->left,x);
        else p->right = Creat(p->right,x);
        return p;
    }
}

void Gets(BiNode *p,int x){
    if(p == NULL) return;
    else if(x == p->value) return;
    else if(x < p->value)
        {printf("E");Gets(p->left,x);}
    else if(x > p->value)
        {printf("W");Gets(p->right,x);}
}

int main(){
    //freopen("in.txt","r",stdin);
    int t,n,m,x,y;
    scanf("%d",&t);
    while(t--){
        BiNode *root = NULL;
        Remove(root);
        scanf("%d",&n);
        for(int i = 0;i < n; i++){
            scanf("%d",&x);
            root = Creat(root,x);
        }
        scanf("%d",&m);
        for(int i = 0;i < m; i++){
            scanf("%d",&y);
            Gets(root,y);
            printf("\n");
        }
    }
    return 0;
}

