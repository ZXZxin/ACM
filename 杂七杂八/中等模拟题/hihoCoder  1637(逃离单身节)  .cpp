//题目链接：http://hihocoder.com/problemset/problem/1637
//题目大意：输入n,输出爱心的边长为n的爱心
//解题思路：模拟即可

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 100+10;

int main() {
    int n;
    while(cin>>n){
       for(int i = 1; i <= n; i++)cout<<" ";
       for(int i = 1; i <= 2; i++){
            for(int j = 1; j <= n; j++)cout<<"_";
            for(int k = 1; k <= 3*n; k++)cout<<" ";
       }
       cout<<endl;
       for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == n - j+1)cout<<"/";
                else cout<<" ";
            }
            for(int j = n+1; j <= 2*n; j++)cout<<" ";
            for(int j = 2*n+1; j <= 3*n; j++){
                if(i + 2*n== j)cout<<"\\";
                else cout<<" ";
            }
            for(int j = 3*n+1 ;j <= 4*n; j++){
                if(i == n)cout<<"_";
                else cout<<" ";
            }
            for(int j = 4*n + 1; j <= 5*n; j++){
                if(i == 5*n - j + 1)cout<<"/";
                else cout<<" ";
            }
            for(int j = 5*n+1; j <= 6*n; j++)cout<<" ";
            for(int j = 6*n+1; j <= 7*n; j++){
                if(i +6*n == j)cout<<"\\";
                else cout<<" ";
            }
            cout<<endl;
       }
       for(int i = 1; i <= n; i++){
            cout<<"|";
            for(int j = 1; j <= 5*n + (n-1)*2; j++)cout<<" ";
            cout<<"|"<<endl;
       }
       for(int i = 1; i <= 3*n; i++){
            for(int j = 1; j <= 3*n; j++){
                if(i != j)cout<<" ";
                else cout<<"\\";
            }
            if(i == 3*n)for(int j = 1; j <= n; j++)cout<<"_";
            else for(int j = 3*n+1; j <= 4*n; j++)cout<<" ";
            for(int j = 4*n+1; j <= 7*n; j++){
                if(i == 7*n - j+1)cout<<"/";
                else cout<<" ";
            }
            cout<<endl;
       }
    }
    return 0;
}
