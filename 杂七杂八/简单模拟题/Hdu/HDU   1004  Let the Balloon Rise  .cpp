//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1004
//题目大意：求出现次数最多的颜色
//解题思路：用map<string,int>记录

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

const int maxn = 1000+10;

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    while(cin>>n&&n){
        string s[maxn],temp;
        map<string,int>dict;
        dict.clear();
        for(int i = 0; i < n; i++){cin>>s[i];dict[s[i]]++;}
        int max_Element = 0;
        for(int i = 0; i < n; i++)if(dict[s[i]] > max_Element){max_Element = dict[s[i]]; temp = s[i];}
        cout<<temp<<endl;
    }
    return 0;
}
