//�˴�����(̰�ķ�)
//���� : ��n���ˣ���i��������Ϊwi��ÿ�Ҵ��������������ΪC�������ֻ�ܳ������ˡ������ٵĴ�װ�������ˡ�
//����˼· : ���ȴ�������˿�ʼ���ǣ���ô��Ӧ�ú����ص���ȥ�������ÿ���˶����ܺ�����������ôΨһ�ķ�������ÿ������һ�Ҵ���
            //������Ӧ��ѡ���ܹ�����һ���������������ص��Ǹ��������ӲŲ����˷ѡ�
//��֤����֤�� : (1)����i�����κ���ͬ��,��j(���߱�j�����)��ͬ������ٴ�������
               //(2)����i��kͬ������Ϊj����iƥ������صģ�����w(k)<=w(j)����j�������������ܻ�ʹ���������أ��õĴ������ࣻ

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int maxn = 100 + 10;
using namespace std;

int cmp(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    freopen("in.txt","r",stdin);
    int w[maxn],n,C;
    while(scanf("%d%d",&C,&n) != EOF){
        for(int i = 1; i <= n; i++)scanf("%d",&w[i]);
        //sort(w+1,w+1+n); //����
        qsort(w,n+1,sizeof(w[1]),cmp);  //����,�����±��һ����ʼ�±�
        int i = 1, j = n;
        int ans = 0;
        while( i <= j){
            if( i == j){ans++;break;} //����ȵ�ʱ��Ҳ����ζ�������������,ֻʣ�Լ���
            if(w[i] + w[j] <= C){
                ans++;
                i++;
                j--;
            }else{
                ans++;
                j--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
��������:
85 6
5 84 85 80 84 83
90 3
90 45 60
100 5
50 50 90 40 60
���:
5
3
3
*/
