//题目链接: https://vjudge.net/contest/169966#problem/K
//题目大意：利用四叉树处理图片，给你两张黑白图片的四叉树，f(黑)(其实就是叶子节点),p（灰）就是有孩子的节点，e(白)也是叶子节点，
        //问两张图片叠加后黑色的面积。
/*解题思路：把图片分成1024块1*1的小正方形，建立一位数组记录对应小正方形的颜色。
          利用递归根据字符串，建立相应四叉树。在建树的过程中，树节点计算当前节点对应的小正方形
          编号区间。这里处理类似于线段树，将父节点的区间等分成4份分别对应四棵子树的编号区间。
          建树到达叶子时（color为‘f’或者‘e’），直接将颜色数组赋值即可。当树建完时，颜色数组即染色
          将两棵树依次染色到同一数组，统计黑色节点个数即可。
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 1024 + 10;
char str[maxn];
int Color[maxn];

typedef struct node{
    char data;
    node *child[4];
}FNode,*FTree;

FTree DFS(char *str,int &step,int a,int b){
    FTree T = new FNode();
    T->data = str[step++];
    if(T->data == 'p'){
        T->child[0] = DFS(str,step,a,((a+b)/2+a)/2);//0 到 1/4区间
        T->child[1] = DFS(str,step,((a+b)/2+a)/2 + 1,(a+b)/2);// 1/4区间到 1/2区间
        T->child[2] = DFS(str,step,(a+b)/2 + 1,((a+b)/2+b)/2); // 1/2 区间到 3/4区间
        T->child[3] = DFS(str,step,((a+b)/2+b)/2 + 1,b);  // 3/4区间到  1区间
    }
    else if(T->data == 'f'){
        for(int i = a; i <= b; i++)Color[i] = 1;//黑色的赋值
    }
    return T;
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,step;
    scanf("%d",&T);
    while(T--){
        memset(Color,0,sizeof(Color));
        step = 0;
        scanf("%s",str);
        DFS(str,step,0,1023);
        step = 0;
        scanf("%s",str);
        DFS(str,step,0,1023);
        int sum = 0;
        for(int i = 0; i < 1024; i++)sum += Color[i];
        printf("There are %d black pixels.\n", sum);
    }
    return 0;

}

