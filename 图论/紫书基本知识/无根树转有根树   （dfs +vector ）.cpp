//无根树转有根树（不用邻接矩阵做（开不下这么大的数组））
//输入树中的n个结点，输入n - 1条边,输入一个根结点,构造这颗树

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
const int maxn = 100+10;
vector<int>G[maxn];
int pa[maxn];

void dfs(int u,int fa){   //递归转化为以u为根的子树，u的父节点为fa
    int d = G[u].size();   //结点u 的相邻结点的个数
    for(int i = 0; i < d; i++){
        int v = G[u][i];//结点u的第i个相邻的结点
        if(v != fa){dfs(v,pa[v] = u);}//把v 的父节点设为 u,然后递归转化为以v 为根的子树
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,root;
    cin>>n;
    for(int i = 0; i < n - 1; i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin>>root;
    pa[root] = -1;
    dfs(root,-1);
    for(int i = 1; i < n; i++){
        cout<<i<<" "<<pa[i]<<endl;
    }
    return 0;
}
/*测试数据
6
2 1
4 2
5 2
3 1
6 3
1
*/
