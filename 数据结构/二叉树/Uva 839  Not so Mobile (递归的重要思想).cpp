//题目链接;https://vjudge.net/contest/169966#problem/I
//题目大意：这是一个类似于树的天平，这个天平的每一端都有可能由一个子天平构成，而每个天平都满足一个公式 WL * DL = WR * DR，
         //其中WL，WR分别代表左边和右边物品的重量，DL，DR分别代表左边和右边物品里天平中心的距离。如果其中有一个天平不满足就要输出NO
//解题思路：就是递归（要仔细理解）
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
bool flag;

int Creat(int W1,int D1,int W2,int D2){
    int w1,d1,w2,d2;
    if(W1 == 0){//递归创建左子树
        scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
        W1 = Creat(w1,d1,w2,d2);
    }
    if(W2 == 0){//递归创建右子树
        scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
        W2 = Creat(w1,d1,w2,d2);
    }
    if(flag && W1*D1 != W2*D2)flag = false;//只要有一颗子树不满足都不行
    return W1 + W2;//每次返回左右的权值之和
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,w1,d1,w2,d2;
    scanf("%d",&T);
    while(T--){
        flag = true;
        scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
        Creat(w1,d1,w2,d2);
        if(flag)printf("YES\n");
        else printf("NO\n");
        if(T)printf("\n");
    }
    return 0;
}

//刘汝佳的代码
// 题意：输入一个树状天平，根据力矩相等原则判断是否平衡。采用递归方式输入，0表示中间结点
// 算法：在“建树”时直接读入并判断，并且无须把树保存下来
#include<iostream>
using namespace std;

// 输入一个子天平，返回子天平是否平衡，参数W修改为子天平的总重量
bool solve(int& W) {
    int W1, D1, W2, D2;
    bool b1 = true, b2 = true;
    cin >> W1 >> D1 >> W2 >> D2;
    if(!W1) b1 = solve(W1);
    if(!W2) b2 = solve(W2);
    W = W1 + W2;
    return b1 && b2 && (W1 * D1 == W2 * D2);
}

int main() {
    int T, W;
    cin >> T;
    while(T--) {
        if(solve(W)) cout << "YES\n"; else cout << "NO\n";
        if(T) cout << "\n";
    }
    return 0;
}


