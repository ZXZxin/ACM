//��Ŀ���� : https://www.patest.cn/contests/gplt/L1-020

//����˼· :
//(1)���鼯��ѯÿ�����ϵ�����

//(2)�����е�����Ȧ����һ������Ȧ�����д�����ʵ���������Ԫ���Ƿ���֮ǰ����ǹ���
         // ��һ��������鿴������Ȧ����ǰ������������Ϊ1�Ļ�����ǣ�˵��������Ȧֻ�����Լ���
         // ע�� : ��Ϊ�����Ѿ���k>=2ʱ����������������ͬ������

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

const int maxn = 100000 + 10;
using namespace std;

int Fa[maxn],Rank[maxn];

int Find(int v){
	if (Fa[v] == v)return v;
	return Fa[v] = Find(Fa[v]);
}

void Union(int x, int y){
	int fx = Find(x);
	int fy = Find(y);
	if (fx == fy)return;
	if (Rank[fx] < Rank[fy])
        Fa[fx] = fy;
	else{
		Fa[fy] = fx;
		if (Rank[fx] == Rank[fy])Rank[fy]++;
	}
}


int main(){
    int n,k,m,ser,num,Root[maxn],root,len = 0;
    bool vis[maxn];
    scanf("%d",&n);
    for(int i = 0; i < maxn; i++)Fa[i] = i; //ע������Ҫ��100000
    for(int i = 0; i < n; i++){
        scanf("%d%d",&k,&root);
        for(int j = 1; j < k; j++){
            scanf("%d",&num);
            Union(root,num);
        }
        if(k != 1)Root[len++] = Find(Fa[root]); //ֻ��һ��ʱ�Ͳ�Ҫ������
    }
    scanf("%d",&m);
    memset(vis,false,sizeof(vis));
    bool flag = false;
    for(int i = 0; i < m; i++){
        scanf("%d",&ser);
        if(!vis[ser]){
            bool ok = true;
            for(int j = 0; j < len; j++)if(Find(Fa[ser]) == Root[j]){ok = false;break;}
            if(ok){
                if(!flag){printf("%05d",ser); flag = true;}
                else printf(" %05d",ser);
                vis[ser] = true;
            }
        }
    }
    if(flag)printf("\n");
    else printf("No one is handsome\n");
    return 0;
}



//������������
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

const int maxn = 100000 + 10;
using namespace std;

int main(){
    int n,k,m,num,ser;
    int vis[maxn];
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < n; i++){
        scanf("%d",&k);
        for(int j = 0; j < k; j++){
            scanf("%d",&num);
            if( k == 1 )break;  //ֻ��һ���Ͳ��ñ����
            vis[num] = 1;
        }
    }
    scanf("%d",&m);
    bool flag = false;
    for(int i = 0; i < m; i++){
        scanf("%d",&ser);
        if(!vis[ser]){
            if(!flag){ printf("%05d",ser); flag = true; }  //ע��ǰ��0�Ĳ���
            else printf(" %05d",ser);
            vis[ser] = 1;  //ֻ���һ��
        }
    }
    if(flag)printf("\n");
    else printf("No one is handsome\n");
    return 0;
}




