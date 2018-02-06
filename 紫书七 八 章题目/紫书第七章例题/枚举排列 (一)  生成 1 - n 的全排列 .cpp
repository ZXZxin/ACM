//���� 1 - n ����������

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 100 + 10;
using namespace std;

void print_permutation(int n,int *A,int cur){
    if(cur == n){
        for(int i = 0; i < cur; i++)printf("%d ",A[i]);
        printf("\n");
    }
    else for(int i = 1; i <= n; i++){ //���� 1 ~ n���������� //�ؼ�������һ�� //������A[cur]����1-n�ĸ�����
        bool flag = true;
        for(int j = 0; j < cur; j++)if(A[j] == i)flag = false;
        if(flag){
            A[cur] = i;
            print_permutation(n,A,cur+1);
        }
    }
}

int main(){
    int n;
    int a[maxn];
    scanf("%d",&n); //����n ,��� 1-n ������
    print_permutation(n,a,0);
    return 0;
}
