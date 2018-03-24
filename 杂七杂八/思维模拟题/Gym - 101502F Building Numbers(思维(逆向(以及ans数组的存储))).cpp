//��Ŀ���� : https://vjudge.net/contest/216415#problem/F
//��Ŀ���� : ���ǽ���һ�����Ĳ�����Ǽ���1���߼����Լ�����(*2),���ڸ���һ����,������m��ѯ������(l,r)
           //Ҫ������������������Ҫ��ѯ�ʵ�����
//��Ŀ���� : һ��ʼ�뵽BFS,���Ǻ�������vis���鲻���ᳬ�ڴ�,���ᳬʱ,���Բ�������,�������֮���ֿ���ֱ�Ӵ�����
           //�Ƶ�����,���������Ŀ��һ��������ans�����ʹ��,�������ᳬʱ(һ��ʼ�������ÿ���Ĵ���,����ֱ�����)

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 100000 + 10;
typedef long long LL;

int main(){
    int T,n,m,l,r;
    LL x,ans[maxn];
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        ans[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%lld",&x);
            LL step = 0,temp = x;
            while(temp != 1){
                if(temp%2)temp -= 1;
                else temp /= 2;
                step++;
            }
            ans[i] = ans[i-1]+step;
        }
        for(int i = 0; i < m; i++){
            scanf("%d%d",&l,&r);
            printf("%lld\n",ans[r]-ans[l-1]);
        }
    }
    return 0;
}

//û��ans�����˼·(��ʱ����ȡ)
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 100000 + 10;
typedef long long LL;

int main(){
    int T,n,m,l,r;
    LL a[maxn];
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++)scanf("%lld",&a[i]); //1 2 3 4 5
        for(int i = 0; i < m; i++){
            LL sum = 0;
            scanf("%lld%lld",&l,&r);
            for(int j = l; j <= r; j++){
                LL step = 0,temp = a[j];
                while(temp != 1){
                    if(temp%2)temp -= 1;
                    else temp /= 2;
                    step++;
                }
                sum += step;
            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}


//BFS��˼·(����ȡ)
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
    int step;
    LL sum;
    Node(){}
    Node(int step,LL sum):step(step),sum(sum){}
};

bool vis[maxn];

int BFS(int target){
    Node Now;
    Now.sum = 1,Now.step = 0;
    vis[1] = true;
    queue<Node>q;
    q.push(Now);
    while(!q.empty()){
        Now = q.front();q.pop();
        if(Now.sum == target)return Now.step;
        int NewSum = Now.sum*2;
        if(!vis[NewSum]){
            vis[NewSum] = true;
            q.push(Node(Now.step+1,NewSum));
        }
        NewSum = Now.sum+1;
        if(!vis[NewSum]){
            vis[NewSum] = true;
            q.push(Node(Now.step+1,NewSum));
        }
    }
}


int main(){
    int T,n,m,q;
    LL a[maxn],l,r;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++)scanf("%lld",&a[i]); //1 2 3 4 5
        for(int i = 0; i < m; i++){
            LL sum = 0;
            scanf("%lld%lld",&l,&r);
            for(int j = l; j <= r; j++){
                memset(vis,false,sizeof(vis));
                sum += BFS(a[j]);
            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}
