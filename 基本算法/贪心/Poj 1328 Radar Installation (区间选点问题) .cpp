//����ѡ������
//��Ŀ���� : http://poj.org/problem?id=1328
//��Ŀ���� : ���Ǹ���һЩ��(��x���Ϸ�),Ҫ����x���ϲ��þ������ٵ��״�,��������Щ����
//����˼· : �����ÿ������Ŀ��Ը��ǵ����䣬Ȼ���ת������һ������ѡ������,��̰�ĵ�˼��������
            //һ��Ҫѡ���һ��,Ȼ������ѡ������,����End(ע�ⰴ���������Ĳ�ͬ���ж�)

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 10;

struct Rad{
    double l,r;
    Rad(){}
    Rad(double l,double r):l(l),r(r){}
    bool operator < (const Rad & rhs)const {
        return r < rhs.r || (r == rhs.r && l > rhs.l);
    }
};

int cmp(const void *a, const void *b){
    return (*(Rad *)a).l > (*(Rad *)b).l ? 1 : -1;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,d,kase = 0;
    int x[maxn],y[maxn];
    while(scanf("%d%d",&n,&d) &&n&&d){
        bool flag = true;\
        for(int i = 0; i < n; i++){
            scanf("%d%d",&x[i],&y[i]);
            if(y[i] > d)flag = false;
        }
        printf("Case %d: ",++kase);
        if(!flag){printf("-1\n");continue;}
        Rad rad[maxn];
        for(int i = 0; i < n; i++){
            rad[i].l = x[i] - sqrt(double(d*d - y[i]*y[i]));
            rad[i].r = x[i] + sqrt(double(d*d - y[i]*y[i]));
        }
        sort(rad,rad+n);
//        qsort(rad,n,sizeof(rad[0]),cmp);//ע������double������
        double End = rad[0].r; //����wrong�˺ö��  ����int End = rad[0].r
        int sum = 1;
        for(int i = 1; i < n; i++){
            if(rad[i].l > End){
                sum++;
                End = rad[i].r;
            }
//            else {   //����ǰ�����˵����еĻ���Ҫ�ж�һ���Ƿ�����������
//                if(rad[i].r < End){
//                    End = rad[i].r;
//                }
//            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
