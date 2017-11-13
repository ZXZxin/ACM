//题目链接：https://vjudge.net/contest/169966#problem/F
//题目大意：给你二叉树的深度和小球的个数，当小球总根节点1下落的时候，每到一个结点开关发生变化，如果关闭，则往做走，否则往右走
//解题思路：直接模拟会超时，
            //思维思考：直接看小球的编号就可以知道是落在根节点的左子树还是右子树，对于落在左子树上的小球来说，只需要知道它是第几个
            //落在这个子树上的，就可以知道它接下来往哪边落,然后递归
/*
    小球在根节点的时候，一定是第1,3,5,7……个小球落在左子树，2,4,6,8……落在右子树。
    再向下看，假设我们现在在根节点的左子树上，那么就会发现第1,5,9……落在左子树，其他的落在右子树。
    那么就是所有落在当前节点的小球中，第2n - 1（n=1.2.3.4……）个落在左子树，第2n（n=1.2.3.4……）个落在右子树。
    如果题目给的是第m个小球，如果m是偶数，
    那么，小球的一定是向右子树落的第I/2个小球，就将当前答案ans*2+1（到达右子树），将m / 2；
    否则，小球是向左子树落的，当前答案ans*2，m = （m + 1） / 2；
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    int T,D,I,k;
    cin>>T;
    for(int i = 0; i < T+1; i++){
        cin>>D>>I;
        if(D == -1)break;
        int  k = 1;
        for(int j = 0; j < D - 1; j++){
            if(I%2){k *= 2; I = (I+1)/2;}//当I是奇数时，I是往左走的第（I+1）/2个小球
            else {k = k*2+1; I /= 2;}  //当I是偶数时，I时往右走的第I/2个小球
        }
        cout<<k<<endl;
    }
    return 0;
}



//超时代码
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 10+5;

int main(){
    //freopen("in.txt","r",stdin);
    int T,flag[1<<maxn],D,I,n,k;
    cin>>T;
    for(int i = 0; i < T+1; i++){
        cin>>D>>I;
        if(D == -1)break;
        n = (1<<D) - 1;
        memset(flag,0,sizeof(flag));
        for(int j = 0; j < I; j++){
            k = 1;
            for(;;){  //每个小球往下落
                flag[k] = !flag[k];
                if(flag[k])k = 2*k;
                else k = 2*k + 1;
                if(k>n)break;
            }
        }
        cout<<k/2<<endl;
    }
    return 0;
}


