//子集生成 之 增量构造法 (没有重复元素)  (升序输出 1 ~ n 的 子集)

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 10;

void print_subset(int n,int *A,int cur){
    for(int i = 0; i < cur; i++)printf("%d ",A[i]);printf("\n");//每次输出
    int s = cur ? A[cur - 1]+1 : 1;  //确定当前元素的最小可能值
    for(int i = s; i <= n; i++){
        A[cur] = i;
        print_subset(n,A,cur+1);
    }
}

int main(){
    int n;
    int A[maxn];
    while(scanf("%d",&n)){
        print_subset(n,A,0);
    }
    return 0;
}
