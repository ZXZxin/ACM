//半数集问题:

/*问题描述：
给定一个自然数n，由n 开始可以依次产生半数集set(n)中的数如下。
(1) n∈set(n)；
(2) 在n 的左边加上一个自然数，但该自然数不能超过最近添加的数的一半；
(3) 按此规则进行处理，直到不能再添加自然数为止。
例如，set(6)={6,16,26,126,36,136}。半数集set(6)中有6 个元素。
注意半数集是多重集。
给定n,求set(n)中的个数:

*/
//分治递归求解


#include <stdio.h>
#include <string.h>
const int maxn = 500 + 10;

int vis[maxn];

int solve(int n){
    int sum = 1;
    if(vis[n] != 0)return vis[n];  //防止重复计算
    for(int i = 1; i <= n/2; i++)sum += solve(i); //递归子问题
    vis[n] = sum;
    return sum;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(~scanf("%d",&n)){
        memset(vis,0,sizeof(vis));
        printf("%d\n",solve(n));
    }
    return 0;
}
