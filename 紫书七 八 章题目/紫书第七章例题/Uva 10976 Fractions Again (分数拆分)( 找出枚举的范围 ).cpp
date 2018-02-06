//��Ŀ���ӣ�https://vjudge.net/contest/171111#problem/C
//��Ŀ����: ����n,�ҳ����е�x,y,x>=y,�� 1/n = 1/x + 1/y ;(n,x,y > 0)
//����˼·: x < y  -->  1/x > 1/y  -->  1/n - 1/y >= 1/y  -->  y <= 2*n ����ֻҪ y ö�ٵ� 2*n�Ϳ�����

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 100 + 10;
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        int sum = 0;
        for(int y = n+1; y <= 2*n; y++)if((y*n)%(y - n) == 0)sum++;
        printf("%d\n",sum);
        for(int y = n+1; y <= 2*n; y++){
            if((y*n)%(y - n) == 0)printf("1/%d = 1/%d + 1/%d\n",n,(y*n)/(y- n),y);
        }
    }
    return 0;
}
