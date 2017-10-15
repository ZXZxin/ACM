//��Ŀ���ӣ�http://acm.split.hdu.edu.cn/showproblem.php?pid=6025
//��Ŀ���⣺����һ������Ҫ��ȥ������һ������ʹ�����ǵ�gcd���
//����˼·����ǰ׺gcd�ͺ�׺gcd��Ȼ��ö��ÿһ��������ÿһ������ǰ׺gcd���׺gcd��gcd��ȡ���ֵ

#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn = 1e5+20;//��Ҫ
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

int pre[maxn];
int nxt[maxn];
int a[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        pre[1]=a[1];
        for(int i=2;i<=n;i++)pre[i]=gcd(pre[i-1],a[i]);
        nxt[n]=a[n];
        for(int i=n-1;i>=1;i--)nxt[i]=gcd(nxt[i+1],a[i]);
        int ans=max(nxt[2],pre[n-1]);
        for(int i=2;i<n;i++){
            ans=max(ans,gcd(pre[i-1],nxt[i+1]));
        }
        printf("%d\n",ans);
    }
    return 0;
}
