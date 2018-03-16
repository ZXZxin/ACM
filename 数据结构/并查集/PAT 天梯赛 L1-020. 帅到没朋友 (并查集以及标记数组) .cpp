//题目链接 : https://www.patest.cn/contests/gplt/L1-020

//解题思路 :
//(1)并查集查询每个集合的祖先

//(2)将所有的朋友圈看成一个朋友圈，所有此题其实就是求这个元素是否在之前被标记过，
         // 用一个标记数组看成朋友圈，当前如果输入的人数为1的话不标记，说明此朋友圈只有他自己！
         // 注意 : 因为题中已经将k>=2时限制了最少俩个不同的人了

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
    for(int i = 0; i < maxn; i++)Fa[i] = i; //注意这里要到100000
    for(int i = 0; i < n; i++){
        scanf("%d%d",&k,&root);
        for(int j = 1; j < k; j++){
            scanf("%d",&num);
            Union(root,num);
        }
        if(k != 1)Root[len++] = Find(Fa[root]); //只有一个时就不要保存了
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



//标记数组的妙用
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
            if( k == 1 )break;  //只有一个就不用标记了
            vis[num] = 1;
        }
    }
    scanf("%d",&m);
    bool flag = false;
    for(int i = 0; i < m; i++){
        scanf("%d",&ser);
        if(!vis[ser]){
            if(!flag){ printf("%05d",ser); flag = true; }  //注意前导0的补齐
            else printf(" %05d",ser);
            vis[ser] = 1;  //只输出一次
        }
    }
    if(flag)printf("\n");
    else printf("No one is handsome\n");
    return 0;
}




