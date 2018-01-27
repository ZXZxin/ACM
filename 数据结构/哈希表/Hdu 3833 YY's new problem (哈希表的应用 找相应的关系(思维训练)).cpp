//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=3833
//��Ŀ���⣺�����ҳ��������Ƿ�������P[i1]-P[i2]=P[i2]-P[i3], 1<=i1<i2<i3<=N.�Ĵ���
//����˼·����a[i]��ֵ��Ϊhash������Ӧ���±�ÿ������һ��hash������ֵ�ͼ�1,Ȼ��hash����Ѱ�ң�
           //��hash[i]�ĶԳƵ�ǰ��ͺ�����ң����hash[i-j]+hash[i+j]==1, ˵����i����ʱ�������ֿ��ܣ�һ�Ǳ�iС�����Ѿ����ֵ���i�������û���֣�
           //���߱�i������Ѿ����֣���iС������û���֣�û���ֵ�����i�ĺ��棬�Ѿ����ֵ���i��ǰ�棬����ҵ���������������С�
           //��Ҫע����ǣ���Ŀ˵����1��N�����У�����˵����N������

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 10000 + 10;
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    int T,n;
    scanf("%d",&T);
    int a[maxn],hash[maxn];
    while(T--){
        scanf("%d",&n);
        memset(hash,0,sizeof(hash));
        bool flag = false;
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
            hash[a[i]]++;
            for(int j = 1; j < a[i] && j + a[i] <= n; j++){
                if(hash[a[i] - j] + hash[a[i] + j] == 1){
                    flag = true;
                    break;
                }
            }
        }
        if(flag)printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
