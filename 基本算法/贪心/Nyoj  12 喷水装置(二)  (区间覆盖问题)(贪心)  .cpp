// 区间覆盖问题
//题目链接 : http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=12
//题目大意 : 中文题
//解题思路 : 想明白要将喷头覆盖的圆形部分转化为一个横轴上对应的一个区间然后使用区间覆盖的思想做
        /*区间覆盖问题 : 区间覆盖问题 :
        数轴上有n个区间[ai,bi]，选择尽量少的区间覆盖一条指定线段[s,t]。
        贪心策略：把各区间按照a从小到大排序，从前向后遍历，然后每次选择从当前起点S开始的最长区间，
        并以这个区间的右端点为新的起点，继续选择，直到找不到区间覆盖当前起点S或者S已经到达线段末端。
        需要注意的是，如果某一区间边界大于s,t的边界，应把它们变成s或t。因为超出的部分毫无意义，同时还会影响对数据的分析。*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;
const int maxn = 10000 + 10;

struct Range{
    int l,r;
    bool operator < (const Range & rhs)const {
        return l < rhs.l;
    }
}rag[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int T,n,w,h,x,r;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&w,&h);
        for(int i = 0; i < n; i++){
            scanf("%d%d",&x,&r);
            if(r*r < (h/2)*(h/2)){i--,n--;continue;}
            rag[i].l = x - sqrt(r*r - (h/2)*(h/2));
            rag[i].r = x + sqrt(r*r - (h/2)*(h/2));
        }
        sort(rag,rag+n);
        double End = 0;
        int k = -1,cnt = 0;
        while(End < w && rag[k+1].l <= End){
            double maxx = -1;
            for(int i = k + 1; rag[i].l <= End && i < n; i++){ //找出右端点最大的
                if(rag[i].r > maxx){
                    maxx = rag[i].r;
                    k = i;
                }
            }
            End = maxx; //更新End
            cnt++;
        }
        printf("%d\n",End < w ? 0 : cnt);
    }
    return 0;
}
