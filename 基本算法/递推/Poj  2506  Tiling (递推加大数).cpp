//��Ŀ���� : http://poj.org/problem?id=2506
//��Ŀ���� : ����������2*1,1*2,2*2��שƴ��2*n�ĳ�����,�ж�����ƴ��
//����˼· : ����n��ʱ��,���������Ѿ��̺���n-1��ש,��n��ֻ�����ŷ�
                    //���������Ѿ��̺���n-2��ש,���������3�ַ�ʽ,����������һ�ַ�������������ͬ��
                    //����f[n] = 2* f[n-2] + f[n-1]

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 10000 + 10;

//�ӷ�
string BigPositiveInteger_Add(string s1,string s2){
    int a[maxn],b[maxn];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int len1 = s1.size(),len2 = s2.size();
    int maxL = max(len1,len2);
    for(int i = 0; i < len1; i++)a[i] = s1[len1-1-i]-'0';
    for(int i = 0; i < len2; i++)b[i] = s2[len2-1-i]-'0';
    for(int i = 0; i < maxL; i++){
        if(a[i]+b[i] >= 10){
            int temp = a[i]+b[i];
            a[i] = temp%10;
            a[i+1] += (temp/10);
        }
        else a[i] += b[i];
    }
    string c = "";
    if(a[maxL] != 0) c += a[maxL] + '0';
    for(int i = maxL-1; i >= 0; i--)c += a[i] + '0';
    return c;
}


//�˷�
string BigInteger_Multiply(string s1,string s2){
    int a[maxn],b[maxn],c[maxn*2 + 5];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int len1 = s1.size(),len2 = s2.size();
    for(int i = 0; i < len1; i++)a[i] = s1[len1-1-i]-'0'; //����
    for(int i = 0; i < len2; i++)b[i] = s2[len2-1-i]-'0';
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            c[i+j] += a[i]*b[j];
        }
    }
    for(int i = 0; i < maxn*2; i++){
        if(c[i] >= 10){
            c[i+1] += c[i]/10;
            c[i] %= 10;
        }
    }
    string ans = "";
    int i;
    for(i = maxn * 2; i >= 0; i--)if(c[i] != 0)break;
    for(;i >= 0; i--)ans += c[i] + '0';
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    string s[255];
    s[0] = "1",s[1] = "1";  //ע��0��ʱ����1
    for(int i = 2;i <= 255; i++){
        string temp = BigInteger_Multiply("2",s[i-2]);
        s[i] = BigPositiveInteger_Add(s[i-1],temp);
    }
    while(~scanf("%d",&n))cout<<s[n]<<endl;
    return 0;
}
