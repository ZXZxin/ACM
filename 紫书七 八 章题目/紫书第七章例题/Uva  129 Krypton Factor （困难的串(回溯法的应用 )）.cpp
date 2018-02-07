//��Ŀ���ӣ�https://vjudge.net/contest/171111#problem/E
//��Ŀ����: ���һ���ַ��������������ڵ��ظ��ִ��������"���׵Ĵ�"��������"���ѵĴ�"������n,L,
           //�����ǰL���ַ���ɵģ��ֵ����nС�����ѵĴ�
//����˼·:ʱ�䷽��Ҫ�û��ݷ���Ȼ������ж�ÿһ��ż�����ȵĺ�׺�ǲ�����������

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;
int n,L;
int s[maxn];
int cnt;

bool DFS(int cur){
    if(cnt++ == n){
        for(int i = 0; i < cur; i++){
            if(i % 64 == 0 && i != 0)printf("\n");
            else if(i % 4 == 0 && i != 0)printf(" ");
            printf("%c",s[i]+'A');
        }
        printf("\n%d\n",cur);
        return false;
    }else for(int i = 0; i < L; i++){
        s[cur] = i;
        bool flag = true;
        for(int j = 1 ; j*2 <= cur+1; j++){//���Գ���Ϊ  j*2 �� ��׺
            bool ok = false;
            for(int k = 0; k < j; k++)if(s[cur - k] != s[cur - k - j]){ok = true;break;}
            if(!ok){flag = false;break;}
        }
        if(flag)if(!DFS(cur+1))return false;
    }
    return true;
}

int main(){
    while(scanf("%d%d",&n,&L) != EOF && n){
        cnt = 0;
        DFS(0);
    }
    return 0;
}

