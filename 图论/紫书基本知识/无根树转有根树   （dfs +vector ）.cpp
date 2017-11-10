//�޸���ת�и����������ڽӾ���������������ô������飩��
//�������е�n����㣬����n - 1����,����һ�������,���������

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
const int maxn = 100+10;
vector<int>G[maxn];
int pa[maxn];

void dfs(int u,int fa){   //�ݹ�ת��Ϊ��uΪ����������u�ĸ��ڵ�Ϊfa
    int d = G[u].size();   //���u �����ڽ��ĸ���
    for(int i = 0; i < d; i++){
        int v = G[u][i];//���u�ĵ�i�����ڵĽ��
        if(v != fa){dfs(v,pa[v] = u);}//��v �ĸ��ڵ���Ϊ u,Ȼ��ݹ�ת��Ϊ��v Ϊ��������
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
/*��������
6
2 1
4 2
5 2
3 1
6 3
1
*/
