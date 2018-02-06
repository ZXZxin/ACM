//题目链接: https://vjudge.net/contest/171111#problem/D
//题目大意: 输入正整数n,把 1,2,3...n组成一个环,使得相邻两个数之和均为素数,输出时按照从整数1开始逆时针排列
//解题思路: 比较容易的思路的是直接使用next_permutation生成这些排列并判断是否满足(代码放在下面(会超时))
    //  正确的方法是使用回溯法，将A[0] = 1,然后每次尝试取一个数，然后回溯，会快很多

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 16 + 5;

bool isp[maxn],vis[maxn];
int A[maxn];
int n;

bool is_Prime(int x){
    for(int i = 2; i*i <= x; i++)if(x % i == 0)return false;
    return true;
}

//思想就是判断一个条件，然后放置后面的数
//回溯法: 如果当前步骤(层)没有合法选择,则返回上一级调用
void DFS(int cur){
    if(cur == n && isp[A[0] + A[n-1]]){//递归边界，别忘了测试第一个数和最后一个数
        for(int i = 0; i < n; i++){
            if(i != 0)printf(" ");
            printf("%d",A[i]);
        }
        printf("\n");
    }
    else for(int i = 2; i <= n; i++){ //尝试放置每一个数
        if(!vis[i] && isp[A[cur - 1] + i]){
            A[cur] = i;
            vis[i] = true;  //设置使用标记
            DFS(cur+1);
            vis[i] = false;  //清除标记
        }
    }
}

int main(){
    int kase = 0;
    while(scanf("%d",&n) != EOF){
        memset(vis,false,sizeof(vis));
        for(int i = 2; i <= 2*n; i++)isp[i] = is_Prime(i);
        if(kase > 0)printf("\n");  //又是惨绝人寰的输出
        printf("Case %d:\n",++kase);
        A[0] = 1;//不要考虑A[0]非要是哪个，直接1就可以
        DFS(1);
    }
    return 0;
}

//超时的生成测试法
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 100 + 10;

bool isp[maxn];
int A[maxn];

bool is_Prime(int x){
    for(int i = 2; i*i <= x; i++)if(x % i == 0)return false;
    return true;
}

int main(){
    int n,kase = 0;
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; i++)A[i] = i + 1;
        for(int i = 2; i <= 2*n; i++)isp[i] = is_Prime(i);
        if(kase > 0)printf("\n");  //又是惨绝人寰的输出
        printf("Case %d:\n",++kase);
        do{
            bool flag = true;
            for(int i = 0; i < n; i++)if( !isp[A[i] + A[(i+1)%n]] ){flag = false;break;}
            if(flag){
                for(int i = 0; i < n; i++){
                    if(i != 0)printf(" ");
                    printf("%d",A[i]);
                }
                printf("\n");
            }
        }while(next_permutation(A+1,A+n));//1不用排列 每次先输出1，只是后面的排列
    }
    return 0;
}

