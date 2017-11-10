//题目链接：https://vjudge.net/contest/169966#problem/E
//题目大意：就是移动盒子,四个指令，移动之后输出奇数次序的和
//解题思路，就是链表的模拟操作，（注意本题inv这个变量的用法，由于4的操作所以记录是否有过4的操作，有的话1操作和2操作反过来）
//HINT：这个题目有个疑问，为什么把这个 if(op == 3&&Right[y] == x) swap(x,y);注释掉在下面加一种情况是错的（见注释代码）

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 100000+10;
int Left[maxn],Right[maxn];
int n,m;

void init(){
    for(int i = 1; i <= n; i++){Right[i] = (i + 1)%(n + 1); Left[i] = i - 1;}
    Left[0] = n; Right[0] = 1;//设置一个0是为了之后找到后继节点
}

void Link(int L,int R){
    Right[L] = R;
    Left[R] = L;
}

int main(){
    //freopen("in.txt","r",stdin);
    int kase = 0;
    while(cin>>n>>m){
        init();
        int x,y,op,inv = 0;
        for(int i = 0;i < m; i++){
            cin>>op;
            if(op == 4)inv = !inv;
            else {
                cin>>x>>y;
                if(op == 3&&Right[y] == x) swap(x,y); //这个操作是为了后面统一的操作（下面的else if(op == 3))//(1)
                if(op != 3&&inv)op = 3 - op;
                if(op == 1&&Left[y] == x)continue ;
                if(op == 2&&Right[y] == x)continue ;
                int LX = Left[x],RX = Right[x],LY = Left[y],RY = Right[y];
                if(op == 1){Link(LX,RX); Link(LY,x); Link(x,y);}
                else if(op == 2){Link(LX,RX); Link(x,RY); Link(y,x);}
                else if(op == 3){
                    if(x == Left[y]){Link(LX,y); Link(y,x); Link(x,RY);}
                    //else if(Right[y] == x){Link(y,RX);Link(y,x);Link(x,LY);}//省略(1)操作不注释这一行是错的
                    else{
                        Link(LX,y); Link(y,RX); Link(LY,x); Link(x,RY);
                    }
                }
            }
        }
        int b = 0;          //设置一个0是为了之后找到后继节点
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            b = Right[b];
            if(i%2 == 1)ans += b;
        }
        if(inv && n%2 == 0)ans = (long long)n*(n + 1)/2 - ans;//如果是偶数个数,且有过奇数次4的操作，则求整体的和减去所求的和
        cout<<"Case "<<++kase<<": "<<ans<<endl;
    }
    return 0;
}
