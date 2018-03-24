//��Ŀ���� : https://vjudge.net/contest/216415#problem/D
//��Ŀ���� : ��һ��ɫ��,�������Ų�ͬ��ͼ��ͼƬ,Ҫ�������ЩͼƬ,��ȷ��ɫ��ÿ�������
           //Ȼ�����һ����n,Ҫ�㾭��һϵ�еķ�תɸ��,ÿ�η�תɸ�ӵ�һ��,�;ͼ�����һ�������
           //Ҫ������̵Ĳ����ﵽn
//����˼· : BFS���,ע��vis�����ǵ���sum��ֵ
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 100000 + 10;
typedef long long LL;

struct Node {
    int id,step,sum;
    Node(){}
    Node(int id,int step,int sum):id(id),step(step),sum(sum){}
};

int n,Map[8][8];
bool vis[maxn];

void BFS(int s){
    if(n == 1){printf("-1\n");return ;} //����1ʱ���-1
    Node Now,Next;
    Now.id = 1,Now.sum = 0,Now.step = 0;
    vis[0] = true;
    queue<Node>q;
    q.push(Now);
    while(!q.empty()){
        Now = q.front();q.pop();
        if(Now.sum == n){printf("%d\n",Now.step); return;}
        for(int i = 1; i <= 6; i++){
            if(Map[Now.id][i]){
                int newSum = Now.sum + Map[Now.id][i];
                if(vis[newSum])continue;
                vis[newSum] = true;
                q.push(Node(i,Now.step+1,newSum));
            }
        }
    }
    printf("-1\n");
}


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(Map,0,sizeof(Map));
        memset(vis,false,sizeof(vis));
        for(int i = 1; i <= 6; i++){
            for(int j = 1; j <= 6; j++){
                if(i + j != 7 && i != j)Map[i][j] = j;
            }
        }
        BFS(1);
    }
    return 0;
}
