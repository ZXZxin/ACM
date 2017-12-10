//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=5461
//题目大意：就是给你n个数，和a,b要你求a*num[i]*num[i]+b*num[j]的最大值
//解题思路：关键就是找出最大的和次大的，以及绝对值最小的，和绝对值次小的，要考虑到各种情况

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long LL;
const int maxn = 1000010 + 10;

int main(){
    //freopen("in.txt","r",stdin);
    LL T,n,a,b;
    LL num[maxn];
    cin>>T;
    int kase = 0;
    while(T--){
        scanf("%lld%lld%lld",&n,&a,&b);
        for(int i = 0; i < n; i++)scanf("%lld",&num[i]);
        sort(num,num+n);
        int minn = num[0],maxx = num[0];
        for(int i = 0 ; i < n; i++)if(fabs(num[i]) > fabs(maxx))maxx = num[i];//找出绝对值最大的数
        for(int i = 0 ; i < n; i++)if(fabs(minn) > fabs(num[i]))minn = fabs(num[i]);//找出绝对值最小的数
        cout<<"Case #"<<++kase<<": ";
        if(a > 0&&b > 0){
            if(maxx == num[n-1]){
                /*if(a*maxx*maxx+b*num[n-2] > a*num[n-2]*num[n-2]+b*maxx) */cout<<a*maxx*maxx+b*num[n-2]<<endl;
               // else cout<<a*num[n-2]*num[n-2]+b*maxx<<endl;
            }
            else {
                cout<<a*maxx*maxx+b*num[n-1]<<endl;
            }
        }
        else if(a > 0&&b < 0){
            if(maxx != num[0])cout<<a*maxx*maxx+b*num[0]<<endl;
            else cout<<a*maxx*maxx+b*num[1]<<endl;
        }
        else if(a < 0&&b > 0)cout<<a*minn*minn+b*num[n-1]<<endl;
        else if(a < 0&&b < 0)cout<<a*minn*minn+b*num[0]<<endl;
        else if(a > 0&&b == 0)cout<<a*maxx*maxx<<endl;
        else if(a < 0&&b == 0)cout<<a*minn*minn<<endl;
        else if(a == 0&&b > 0)cout<<b*num[n-1]<<endl;
        else if(a == 0&&b < 0)cout<<b*num[0]<<endl;
    }
    return 0;
}
