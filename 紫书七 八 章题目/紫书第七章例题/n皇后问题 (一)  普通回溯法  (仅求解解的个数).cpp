//n�ʺ����⣺��ͨ���ݷ�

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 100 + 10;
using namespace std;
int sum,n,cnt;
int C[maxn];

void Search(int cur){  //���з��ûʺ�
    cnt++;
    if(cur == n)sum++;
    else for(int i = 0; i < n; i++){//�����ڸ��з��ûʺ�
        bool flag = true;
        C[cur] = i; //���԰ѵ�cur�еĻʺ���ڵ�i��//��� ���²��еĻ� ����һ�� i++
        for(int j = 0; j < cur; j++){ //����Ƿ���Ѿ����õĳ�ͻ
            if(C[cur] == C[j] || C[cur] + cur == C[j] + j || cur - C[cur] == j - C[j]){//�����,"���Խ���","���Խ���"
                flag = false;break;
            }
        }
        if(flag)Search(cur+1);
    }
}

int main(){
    while(scanf("%d",&n)){
        sum = cnt = 0;//��ĸ��� �� �ݹ�Ĵ���
        Search(0);
        printf("%d %d\n",sum,cnt);
    }
    return 0;
}
