//�Ӽ����� ֮ �������취 (û���ظ�Ԫ��)  (������� 1 ~ n �� �Ӽ�)

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 10;

void print_subset(int n,int *A,int cur){
    for(int i = 0; i < cur; i++)printf("%d ",A[i]);printf("\n");//ÿ�����
    int s = cur ? A[cur - 1]+1 : 1;  //ȷ����ǰԪ�ص���С����ֵ
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
