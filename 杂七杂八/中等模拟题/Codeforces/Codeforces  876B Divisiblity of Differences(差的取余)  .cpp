//题目链接：http://codeforces.com/problemset/problem/876/B
//题目大意：就是给你n,k,m并给出n个数，问能能不能从n个数中选k个数，使得这k个数中任意两个数的差都能整除m
//解题思路:关键其实就是要懂得数论中的同余，两个数的差能余m，则两个数余m后相等

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 100000 + 10;
int main(){
    //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,m;
    int a[maxn];
    vector<int>ans;
    while(cin>>n>>k>>m){
        ans.clear();
        int mod[maxn],sum[maxn];
        memset(sum,0,sizeof(sum));
        for(int i = 0; i < n; i++){
            cin>>a[i];
            mod[i] = a[i];
            mod[i] %= m;
        }
        for(int i = 0; i < n; i++)sum[mod[i]]++;//统计每个余数的个数
        int maxx= 0,maxi;
        for(int i = 0; i < m; i++){
            if(sum[i] > maxx){maxx = sum[i];maxi = i;}  //记录余数最多的
        }
        if(maxx < k)cout<<"No"<<endl;
        else{
            cout<<"Yes"<<endl;
            for(int i = 0; i < n; i++){
                if(maxi == mod[i])ans.push_back(a[i]);
                if(ans.size() == k)break;//有k个就够了
            }
            for(int i = 0; i < ans.size() - 1; i++)cout<<ans[i]<<" ";
            cout<<ans[ans.size() - 1]<<endl;
        }
    }
    return 0;
}
