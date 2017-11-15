//��Ŀ���ӣ�http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=1013
//��Ŀ���⣺����һ���������ʽ�����Ƿ�����������ʹ������������ʽ��ֵΪ����
//����˼·��˼·����һ����һ���Ƿ��ӣ��ڶ�����һ���Ƿ�ĸ�������������������ͨ���Ӳ������ţ���ɷ��ӻ��ĸ��(����ǽ���Ĺؼ�)
                //ֻҪ�ҵ��и����ܰѵڶ���������1������

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
