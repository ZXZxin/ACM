//��Ŀ���� : https://www.patest.cn/contests/gplt/L1-011
//��Ŀ���� : ����Ҫ��ȥ�� A �г��� B �е��ַ� ,Ȼ�����
//����˼· : ���ǹ�ϣ��˼������

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 10000 + 1;
typedef long long LL;

int main(){
    //freopen("in.txt","r",stdin);
    char s1[maxn],s2[maxn],s3[maxn];
    int a[257 + 200] = {0};
    gets(s1);gets(s2);
    int len1 = strlen(s1),len2 = strlen(s2);
    for(int i = 0; i < len2; i++)a[s2[i] - '0'+200] = 1;
    int k = 0;
    for(int i = 0; i < len1; i++)if(!a[s1[i] - '0'+200])s3[k++] = s1[i];
    for(int i = 0; i < k; i++)printf("%c",s3[i]);
    printf("\n");
    return 0;
}
