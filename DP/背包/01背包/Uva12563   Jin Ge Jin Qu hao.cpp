//题目链接：https://vjudge.net/contest/185947#problem/E
//题目大意：求在给定时间内，最多能唱多少歌曲，在最多歌曲的情况下，使唱的时间最长。
//解题思路：可以转化为01背包求解，要注意至少要流一秒钟唱劲歌金曲，利用滚动数组求解
            /*  需要注意的是，由于要求是连续唱歌，且要求在最多歌曲数的情况下时间最长0
            ，如果按普通的背包存储，很难得到最长时间，因为f[len] 只存储了最多的歌曲数，
            但并不知道这些歌曲到底唱了多少时间。假设最多歌曲数为num, 唱num首歌曲最少时间为tmin,
             那么数组中从f[tmin]到f[len]都等于num,我们无法得知唱num首歌的最大时间。
             比如说len = 10, t[1] = 5, t[2] = 8, 那么f[5] 到 f[10] 都等于1，
             无法知道唱从5到10哪个是唱1首歌的最长时间。如何处理呢？
            这里需要用到一个技巧：对决策进行一定的限定！在计算某个时间最多唱的歌曲时，
            必须是该时间内恰好唱完这些歌，时间多了不行。即f[j]表示的是在j 的时间恰好用完的情况下最多能唱多少首歌。
            比如上面的例子只有f[5] 和f[8]等于1，其他的都等于0。这样的话处理时先算出最多唱的歌曲数 num，
            然后从j = len开始遍历数组f, 第一个等于num的就是在最多歌曲情况下的最长时间。
            */
#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxn 10000
using namespace std;

int f[maxn];
int v[55];

int main(){
    //freopen("in.txt","r",stdin);
    int T;
    int kase=0;
    int t,n;
    cin>>T;
    while(T--){
        cin>>n>>t;
        for(int i=1;i<=n;i++)cin>>v[i];
        memset(f,0,sizeof(f));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=t-1;j>=v[i];j--){
                if(f[j-v[i]]>=1||j==v[i]){ //在j时间内可以唱完第i首歌
                    f[j]=max(f[j],f[j-v[i]]+1);
                    ans=max(ans,f[j]);
                }
            }
        }
        int i;
        for(i=t-1;f[i]!=ans;i--);
        if(ans==0)cout<<"Case "<<++kase<<": "<<1<<" "<<678<<endl;
        else cout<<"Case "<<++kase<<": "<<ans+1<<" "<<i+678<<endl;
    }
    return 0;
}
