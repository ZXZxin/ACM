//题目链接：http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=1013
//题目大意：输入一个除法表达式，问是否可以添加括号使得这个除法表达式的值为整数
//解题思路：思路：第一个数一定是分子，第二个数一定是分母，后边其他的数都可以通过加不加括号，变成分子或分母，(这个是解题的关键)
                //只要找到有个数能把第二个数消成1就行了

#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;

const int maxn = 10000+10;

int gcd(int a,int b){
    return b == 0?a:gcd(b,a%b);
}

bool Judge(int a[],int k){
    a[1] /= gcd(a[0],a[1]);
    for(int i = 2; i < k; i++)a[1] /= gcd(a[i],a[1]);
    return a[1] == 1;
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,a[maxn];
    string s,str;
    int k;
    cin>>T;
    while(T--){
        getchar();
        k = 0;
        getline(cin,s);
        while(1){
            size_t found = s.find("/");
            if(found == string::npos){
                stringstream ss(s);
                ss>>a[k++];
                break;
            }
            str = s.substr(0,found);
            stringstream ss(str);
            ss>>a[k++];
            s.erase(0,found+1);
        }
        if(Judge(a,k))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
