//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1014
//题目大意：就是给你一个步数和模数，自己选定一个初始值按照那个函数算出一些数，如果这些数包含了所有的0 - Mod-1则输出Good Choice
//解题思路：直接模拟，加一个set看是否存在即可

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
    int n,m;
    set<int>s;
    int a[maxn];
    while(cin>>n>>m){
        s.clear();
        a[0] = 0;
        int i;
        for(i = 1; i < m; i++){
            a[i] = (a[i-1] + n)%m;
            if(a[i] == 0)break; //此句可省略
        }
        bool flag = true;
        for(int j = 0; j < i; j++)s.insert(a[j]);
        for(int j = 0; j < m; j++)if(!s.count(j)){flag = false;break;}
        printf("%10d%10d",n,m);
        if(flag)cout<<"    Good Choice"<<endl;//注意空格是4个
        else cout<<"    Bad Choice"<<endl;
        cout<<endl;
    }
    return 0;
}






