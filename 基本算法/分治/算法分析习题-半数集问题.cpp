//����������:

/*����������
����һ����Ȼ��n����n ��ʼ�������β���������set(n)�е������¡�
(1) n��set(n)��
(2) ��n ����߼���һ����Ȼ����������Ȼ�����ܳ��������ӵ�����һ�룻
(3) ���˹�����д���ֱ�������������Ȼ��Ϊֹ��
���磬set(6)={6,16,26,126,36,136}��������set(6)����6 ��Ԫ�ء�
ע��������Ƕ��ؼ���
����n,��set(n)�еĸ���:

*/
//���εݹ����


#include <stdio.h>
#include <string.h>
const int maxn = 500 + 10;

int vis[maxn];

int solve(int n){
    int sum = 1;
    if(vis[n] != 0)return vis[n];  //��ֹ�ظ�����
    for(int i = 1; i <= n/2; i++)sum += solve(i); //�ݹ�������
    vis[n] = sum;
    return sum;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(~scanf("%d",&n)){
        memset(vis,0,sizeof(vis));
        printf("%d\n",solve(n));
    }
    return 0;
}
