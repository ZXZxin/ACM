//��Ŀ����:http://acm.hdu.edu.cn/showproblem.php?pid=1013
//��Ŀ���⣺����һ������ÿ�ηֽ��ÿһλ�ϵ�������ӣ������С��10���������ͣ���������ֽ�
//����˼·��ֱ��ģ�ⲻ�У������Ժܴ�Ҫ���ַ���ģ�⣬����ÿȡһλ������������10��ȡģ
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

typedef long long LL;

string s;
int main(){
    //freopen("in","r",stdin);
    while(cin>>s && s[0] != '0'){
        int d = 0;
        for(int i = 0; i < s.size(); i++){
            d += (s[i] - '0');//��Ϊ����
            if(d >= 10)d = d/10 + d%10;  //��һ���ǹؼ�����
        }
        cout<<d<<endl;
    }
    return 0;
}
