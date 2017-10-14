//��Ŀ���ӣ�http://poj.org/problem?id=3292
//��Ŀ���⣺�涨��4������1��������H-number��H-prime��ʾH-number��ֻ�ܱ�1��������������,
          //���ܱ�����H-number�������������Ա���H-number��������
          //H-semi-prime������H-prime��˵õ���.��1~n��H-semi-prime
//����˼·����ɸѡ��H-primes���ټ�¼��H-semi-primes������¼�´�1��h��H-semi-primes�ĸ��������ˡ�

#include <stdio.h>
#include <string.h>
#define maxn 10000

int is_prime[maxn];
bool flag[maxn];
int visit[maxn];
int cnt;

void init(){
    memset(is_prime,true,sizeof(is_prime));
    is_prime[1]=1;
    for(int i=5;i<maxn;i=i+4){
       if(!is_prime[i])continue;
       for(int j=i*5;j<maxn;j=j+4*i)is_prime[j]=false;
    }
}

void sovle(){
    for(int i=5;i<maxn;i=i+4){
        for(int j=5;j<maxn;j=j+4){
            if(i*j>maxn)break;
            if(is_prime[i]&&is_prime[j])
                flag[i*j]=true;
        }
    }
    int sum=0;
    for(int i=5;i<maxn;++i)
    if(flag[i])visit[i]=++sum;
    else visit[i]=sum;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    init();
    sovle();
    while(scanf("%d",&n)!=EOF&&n){
        printf("%d %d\n",n,visit[n]);
    }
    return 0;
}
