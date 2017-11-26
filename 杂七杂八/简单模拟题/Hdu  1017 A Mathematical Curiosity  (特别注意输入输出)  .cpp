//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1017
//题目大意：就是问能找到多少对小于n的整数对a,b满足题目中的式子
//解题思路：简单题，不过这一题的输入输出要特别注意，且注意m可以为0，最后一个样例后面不需要输出空行

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <set>
using namespace std;
const int maxn = 100000 + 10;
int main(){
    //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,T;
    cin>>T;
    for(int k = 0; k < T; k++){
        int kase = 0;
        while(cin>>n>>m&&(n||m)){ //注意m可以为0
            int sum = 0;
            for(int i = 1; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if((i*i+j*j+m)%(i*j) == 0)sum++;
                }
            }
            cout<<"Case "<<++kase<<": "<<sum<<endl;
        }
        if(k != T-1)cout<<endl;  //很多题目都有格式要求
    }
    return 0;
}






