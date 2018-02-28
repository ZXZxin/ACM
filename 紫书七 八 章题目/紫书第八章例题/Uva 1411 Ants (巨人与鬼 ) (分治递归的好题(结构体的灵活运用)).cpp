//题目链接 : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4157
//题目大意 : 给出平面上n个白点n个黑点，要求两两配对，且配对所连线段没有交点。
//解题思路 : 按照紫书上的写法 : 每次找出最左下的点,按照极角的方式,每当巨人和鬼的数量相同的时候
             //把这个和相同达到的最后一个连起来，然后分治递归求解

//这个题目值得学习的地方 : (1) 把read()行数封装在 结构体中 ,以及重载函数的写法
                         // (2) 结构体嵌套中注意的地方 以及sort()的用法

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

const int maxn = 100 + 10;
using namespace std;

int n;
int ans[maxn * 2]; //存放对应的鬼的序号

struct Point{  //点的结构体类型
    int x,y;
    Point(){}
    Point(int x,int y):x(x),y(y){}
    double angle(const Point& p)const{  //计算每个点的角度
        return atan2(y - p.y,x - p.x);
    }
    bool operator < (const Point & rhs)const {
        return (y < rhs.y)||(y == rhs.y && x < rhs.x);  //先选择前面的
    }
    void read(){
        scanf("%d%d",&x,&y);
    }
};


struct Node {
    Point p;
    int id;  //1 ~ n(巨人)或者 n+1 ~ 2n(鬼)
    double ang;  //角度
    bool operator < (const Node & rhs)const {  //按照角度排序
        return ang < rhs.ang;
    }
    void getAngle(const Node &rhs){  //获得两个点之间的连线和水平之间的夹角的角度
        ang = p.angle(rhs.p);
    }
    int type(){  //返回是巨人还是鬼
        return id <= n ? 1 : -1;
    }

}p[maxn * 2];


void solve(int l,int r){
    if( l > r)return;
    int pos = l;
    for(int i = l + 1; i <= r; i++){  //找出最靠左下的点
        if(p[i].p < p[pos].p){  //已经重载了运算符  //按照重载的规则比较
            pos = i;
        }
    }
    swap(p[pos],p[l]);
    for(int i = l + 1; i <= r; i++){//获得最左边的点和各点的角度
        p[i].getAngle(p[l]);
    }
    sort(p+1+l,p+1+r); //按角度排序
    int cnt = p[l].type();
    for(int i = l + 1; i <= r; i++){
        cnt += p[i].type();
        if(cnt == 0){
            ans[p[l].id] = p[i].id; //把每次选的最左下的和最后一个连起来
            ans[p[i].id] = p[l].id;
            solve(l+1,i-1);  //递归剩下的
            solve(i+1,r);
            return ;
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n) != EOF){
        memset(ans,0,sizeof(ans));
        for(int i = 1; i <= 2*n; i++){  //读入
            scanf("%d%d",&p[i].p.x,&p[i].p.y);
            //p[i].p.read();
            p[i].id = i;
        }
        solve(1,2*n);
        for(int i = 1; i <= n; i++){
            printf("%d\n",ans[i] - n);
        }
    }
    return 0;
}
