//��Ŀ���ӣ�https://vjudge.net/contest/172005#problem/K
//��Ŀ����: ���Ǹ���n,s1,v1,s2,v2������������,1�����,��ֵ,2�����,��ֵ,Ҫ����������װ���ļ�ֵ
//����˼·: ������Ҫ�Ƿ�����ö��,��Ϊ���ֻ��ö��n/s1�Ļ�,���s1��С�ͻᳬʱ,���s1��s2����СҲ�ᳬʱ
            //��ʱ��Ҫ���� ö��s2�� * s1 = s1�� * s2 ��������,���ǰ��v���ں���,��ô2�����s1 - 1��,
            //����ö�ٵ����Ե��������

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int maxn = 100 + 10;
using namespace std;
typedef long long LL;

int main(){
    //freopen("in.txt","r",stdin);
    int T,n,s1,v1,s2,v2,kase = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d",&n,&s1,&v1,&s2,&v2);
        if(s1 < s2){
            swap(s1,s2);
            swap(v1,v2);
        }
        LL maxx = 0;
        if( n / s1 >= 65536){ //��������С//����ö�����ͻ�ܴ� s2�� * s1 = s1�� * s2 ��������,���ǰ��v���ں���,��ô2�����s1 - 1��
            for(LL i = 0; i <= s1; i++){ //ö����s1������2
                maxx = max(maxx, v2*i + (n - s2*i)/s1*v1);
            }
            for(LL i = 0; i <= s2; i++){ //ö����s2������1
                maxx = max(maxx, v1*i + (n - s1*i)/s2*v2);
            }
        }else for(LL i = 0; i <= n/s1; i++){  //�����ö�ٱ��ٵ���һ��
            maxx = max(maxx, i*v1 + (n - s1*i)/s2*v2);
        }
        printf("Case #%d: %lld\n",++kase,maxx);
    }
    return 0;
}
