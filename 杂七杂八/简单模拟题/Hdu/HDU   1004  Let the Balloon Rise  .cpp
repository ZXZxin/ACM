//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=1004
//��Ŀ���⣺����ִ���������ɫ
//����˼·����map<string,int>��¼

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
