//���ؼ�������(ע��Ҫ������ (��Ϊ��ֹ�ظ�������(!i || P[i] != P[i-1)))

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int maxn = 100 + 10;
using namespace std;

void print_permutation(int n,int *A,int *P,int cur){ //A���Ǵ�����е��Ǹ����飬P�ǵ��õ��Ǹ�����
    if(cur == n){
        for(int i = 0; i < cur; i++)printf("%d ",A[i]);
        printf("\n");
    }
    else for(int i = 0; i < n; i++)if(!i || P[i] != P[i-1]){ //���� 1 ~ n���������� //�ؼ�������һ�� //������A[cur]����1-n�ĸ�����
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

