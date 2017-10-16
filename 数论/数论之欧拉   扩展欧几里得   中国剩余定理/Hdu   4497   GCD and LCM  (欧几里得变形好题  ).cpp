//��Ŀ���ӣ�http://acm.split.hdu.edu.cn/showproblem.php?pid=4497
//��Ŀ����:����������G,L���ʴ��ڶ��ٶԣ�x,y,z������gcd(x,y,z)=G.��lcm(x,y,z)=L;
//����˼·��������L/G,������L%G������0�������Ȼ��L/G�ֽ⣬��L/G=(p1^r1)*(p2^r2)*(p3^r3)��(pm^rm)
             /*x=(p1^i1)*(p2^i2)*(p3^i3)��(pm^im)
               y=(p1^j1)*(p2^j2)*(p3^j3)��(pm^jm)
               z=(p1^k1)*(p2^k2)*(p3^k3)��(pm^km)
               ����ĳ��r��i��j��k����һ����һ����r������һ����һ����0������i,j,k��һ��3�������
               r 0 0 ����C(3,1)��
               r 0 r ����C(3,1)��
               r 0 1~r-1 ����(r-1)*A(3,3)��
               ����һ����6*r�֡�*/

//��1��
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
const int maxn = 40000;
using namespace std;

bool is_prime[maxn];
int prime[maxn];
int cnt;

void init(){
    cnt=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[1]=false;
    for(int i=2;i<maxn;i++){
        if(!is_prime[i])continue;
        prime[cnt++]=i;
        for(int j=i*i;j<maxn;j=j+i){
            is_prime[j]=false;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T,G,L;
    cin>>T;
    init();
    while(T--){
        cin>>G>>L;
        if(L%G!=0){cout<<0<<endl;continue;}
        int p=L/G;
        int sum=1;
        for(int i=0;i<cnt;i++){
            if(p%prime[i]==0){
            int temp=0;
            while(p%prime[i]==0){
                p/=prime[i];
                temp++;
            }
            sum*=6*temp;
        }
        if(p==1)break;
    }
    if(p!=1)sum*=6;
    cout<<sum<<endl;
    }
    return 0;
}



//(2)Ҳ���Բ���������

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int T,G,L;
    cin>>T;
    while(T--){
        cin>>G>>L;
        if(L%G!=0){cout<<0<<endl;continue;}
        int p=L/G;
        int sum=1;
        for(int i=2;i*i<=p;i++){
            if(p%i==0){
            int temp=0;
            while(p%i==0){
                p/=i;
                temp++;
            }
            sum*=(6*temp);
        }
        if(p==1)break;
    }
    if(p!=1)sum*=6;
    cout<<sum<<endl;
    }
    return 0;
}

