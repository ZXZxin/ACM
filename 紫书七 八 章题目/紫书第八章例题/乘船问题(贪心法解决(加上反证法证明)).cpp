//乘船问题(贪心法)
//问题 : 有n个人，第i个人重量为wi。每艘船的最大载重量均为C，且最多只能乘两个人。用最少的船装载所有人。
//解题思路 : 首先从最轻的人开始考虑，那么他应该和最重的人去坐，如果每个人都不能和它坐船，那么唯一的方法就是每个人做一艘船。
            //否则，他应该选择能够和他一起坐船的人中最重的那个，这样子才不会浪费。
//反证法的证明 : (1)假设i不与任何人同船,把j(或者比j轻的人)来同船会减少船的数量
               //(2)假设i与k同船，因为j是与i匹配的最重的，所以w(k)<=w(j)，则j加入其它船可能会使其它船超重，用的船数会变多；

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
        //sort(w+1,w+1+n); //排序
        qsort(w,n+1,sizeof(w[1]),cmp);  //数组,最后的下标加一，开始下标
        int i = 1, j = n;
        int ans = 0;
        while( i <= j){
            if( i == j){ans++;break;} //当相等的时候也就意味着其他的配对了,只剩自己了
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
测试数据:
85 6
5 84 85 80 84 83
90 3
90 45 60
100 5
50 50 90 40 60
输出:
5
3
3
*/
