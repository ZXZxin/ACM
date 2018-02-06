//可重集的排列(注意要先排序 (因为防止重复加入了(!i || P[i] != P[i-1)))

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int maxn = 100 + 10;
using namespace std;

void print_permutation(int n,int *A,int *P,int cur){ //A还是存放排列的那个数组，P是调用的那个数组
    if(cur == n){
        for(int i = 0; i < cur; i++)printf("%d ",A[i]);
        printf("\n");
    }
    else for(int i = 0; i < n; i++)if(!i || P[i] != P[i-1]){ //生成 1 ~ n的所有排列 //关键就在这一步 //尝试在A[cur]填入1-n的各个数
        int c1 = 0,c2 = 0;
        for(int j = 0; j < cur; j++)if(A[j] == P[i])c1++;
        for(int j = 0; j < n; j++)if(P[j] == P[i])c2++;
        if(c1 < c2){
            A[cur] = P[i];
            print_permutation(n,A,P,cur+1);
        }
    }
}

int main(){
    int n;
    int P[maxn],A[maxn];
    scanf("%d",&n);
    for(int i = 0; i < n; i++)scanf("%d",&P[i]);
    sort(P,P+n);
    print_permutation(n,A,P,0);
    return 0;
}

