//区间选点问题
//题目链接 : http://poj.org/problem?id=1328
//题目大意 : 就是给你一些岛(在x轴上方),要你在x轴上布置尽可能少的雷达,来覆盖这些岛屿
//解题思路 : 先求出每个岛屿的可以覆盖的区间，然后就转换成了一个区间选点问题,用贪心的思想解决就是
            //一定要选择第一个,然后依此选择后面的,更新End(注意按照排序规则的不同来判断)

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
//        qsort(rad,n,sizeof(rad[0]),cmp);//注意排序，double型排序
        double End = rad[0].r; //这里wrong了好多次  不能int End = rad[0].r
        int sum = 1;
        for(int i = 1; i < n; i++){
            if(rad[i].l > End){
                sum++;
                End = rad[i].r;
            }
//            else {   //如果是按照左端点排列的话就要判断一下是否存在区间包含
//                if(rad[i].r < End){
//                    End = rad[i].r;
//                }
//            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
