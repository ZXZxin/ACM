//n皇后问题：普通回溯法

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 100 + 10;
using namespace std;
int sum,n,cnt;
int C[maxn];

void Search(int cur){  //逐行放置皇后
    cnt++;
    if(cur == n)sum++;
    else for(int i = 0; i < n; i++){//尝试在各列放置皇后
        bool flag = true;
        C[cur] = i; //尝试把第cur行的皇后放在第i列//如果 等下不行的话 就下一个 i++
        for(int j = 0; j < cur; j++){ //检查是否和已经放置的冲突
            if(C[cur] == C[j] || C[cur] + cur == C[j] + j || cur - C[cur] == j - C[j]){//检查列,"副对角线","主对角线"
                flag = false;break;
            }
        }
        if(flag)Search(cur+1);
    }
}

int main(){
    while(scanf("%d",&n)){
        sum = cnt = 0;//解的个数 和 递归的次数
        Search(0);
        printf("%d %d\n",sum,cnt);
    }
    return 0;
}
