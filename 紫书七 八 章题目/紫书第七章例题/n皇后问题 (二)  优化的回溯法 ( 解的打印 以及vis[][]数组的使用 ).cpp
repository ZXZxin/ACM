// n皇后问题：优化的回溯法
#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 100 + 10;
using namespace std;

int sum,n,cnt;
int C[maxn];
bool vis[3][maxn];
int map[8][8];//打印解的数组


//vis数组的含义: 表示已经放置的皇后占据了哪些列、主对角线和副对角线
//一般在回溯法中修改了辅助的全局变量，一定要及时把他们恢复原状
void Search(int cur){  //逐行放置皇后
    cnt++;
    if(cur == n){
        sum++;
        for(int i = 0; i < cur; i++)map[i][C[i]] = 1;//打印解
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d ",map[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        memset(map,0,sizeof(map));
    }
    else for(int i = 0; i < n; i++){ //尝试在 cur行的 各 列 放置皇后
        if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]){//判断当前尝试的皇后的列、主对角线
            vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = true;
            C[cur] = i;//cur 行的列是 i
            Search(cur+1);
            vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = false;//切记！一定要改回来
        }
    }
}

int main(){
    while(scanf("%d",&n)){
        memset(vis,false,sizeof(vis));
        memset(map,0,sizeof(map));
        sum = cnt = 0;
        Search(0);
        printf("%d %d\n",sum,cnt);//输出 解决方案 和 递归次数
    }
    return 0;
}
