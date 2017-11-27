//题目链接：https://vjudge.net/contest/77417#problem/B
//题目大意，就是问通过啊a[i] = fabs(a[i+1] - a[i])不断循环（不超过1000次）中间是否会变成0，或者变回某个数，从而循环
//解题思路：比较简单，模拟即可（可利用set容器，省了一层判断的循环）

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <set>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 10+10;
int a[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        bool flag = false;
        for(int j = 0; j < 1000; j++){
            set<int>s;
            int temp = a[0];
            for(int i = 0; i < n - 1; i++){
                a[i] = fabs(a[i+1] - a[i]);
                s.insert(a[i]);
            }
            a[n-1] = fabs(temp - a[n-1]);
            s.insert(a[n-1]);
            if(s.size() == 1){cout<<"ZERO"<<endl;flag = true;break;}
        }
        if(!flag)cout<<"LOOP"<<endl;
    }
    return 0;
}
