//枚举全排列的模板
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

void Permutation(int num[],int k,int n){
    if( k == n-1){
        for(int i = 0; i < n; i++){
            printf("%d ",num[i]);
        }
        printf("\n");
    }
    else for(int i = k; i < n; i++){
        swap(num[i],num[k]);
        Permutation(num,k+1,n);
        swap(num[i],num[k]);
    }
}
int main(){
    int n,a[maxn];
    scanf("%d",&n);
    for(int i = 0; i < n; i++)scanf("%d",&a[i]);
    Permutation(a,0,n);
    return 0;
}
