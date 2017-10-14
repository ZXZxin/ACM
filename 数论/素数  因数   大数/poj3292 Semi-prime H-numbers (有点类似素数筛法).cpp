//题目链接：http://poj.org/problem?id=3292
//题目大意：规定被4整除余1的数叫做H-number。H-prime表示H-number中只能被1和自身整除的数,
          //不能被其他H-number数整除，但可以被非H-number整除的数
          //H-semi-prime由两个H-prime相乘得到的.求1~n的H-semi-prime
//解题思路：先筛选出H-primes，再记录下H-semi-primes，最后记录下从1到h的H-semi-primes的个数就行了。

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
