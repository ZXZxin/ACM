// 1~n 的所有子集：位向量法
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

const int maxn = 100 + 10;
using namespace std;

//位向量B[i] = 1,当且仅当i在子集 A 中
void print_subset(int n,int *B,int cur){
    if(cur == n+1){
        for(int i = 1; i <= cur; i++){
            if(B[i])printf("%d ",i);
        }
        printf("\n");
        return ;
    }
    B[cur] = 1;
    print_subset(n,B,cur + 1);
    B[cur] = 0;
    print_subset(n,B,cur + 1);
}

int B[maxn]; //不知道怎么滴，放在main函数里面就得不到正确的答案
int main() {
    int n;
    while(scanf("%d", &n)){
        print_subset(n, B, 1);
    }
    return 0;
}

// 0~n - 1  的所有子集：位向量法
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

const int maxn = 100 + 10;
using namespace std;

//位向量B[i] = 1,当且仅当i在子集 A 中
void print_subset(int n,int *B,int cur){
    if(cur == n){
        for(int i = 0; i < cur; i++){
            if(B[i])printf("%d ",i);
        }
        printf("\n");
        return ;
    }
    B[cur] = 1;
    print_subset(n,B,cur + 1);
    B[cur] = 0;
    print_subset(n,B,cur + 1);
}

int main() {
    int n;
    int B[maxn];
    while(scanf("%d", &n)){
        print_subset(n, B, 0);
    }
    return 0;
}
