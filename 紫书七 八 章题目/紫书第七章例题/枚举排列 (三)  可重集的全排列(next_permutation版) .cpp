//可重集的全排列(next_permutation版) (STL中的(也要先排序))

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 100 + 10;

int main(){
    int P[maxn],n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)scanf("%d",&P[i]);
    sort(P,P+n);
    do{
        for(int i = 0; i < n; i++)printf("%d ",P[i]);
        printf("\n");
    }while(next_permutation(P,P+n));
    return 0;
}
