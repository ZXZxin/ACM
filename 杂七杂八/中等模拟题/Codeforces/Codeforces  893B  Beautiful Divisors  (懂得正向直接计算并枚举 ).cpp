//��Ŀ���ӣ�http://codeforces.com/problemset/problem/893/B
//��Ŀ���⣺��������һ����n���ҳ�����Beautiful Divisors����n�ܱ����Beautiful Divisors����������Beautiful Divisors����������Ŀ�е���˼����
//����˼·���������鱣����Щ����Ȼ��Ӵ�Сö���жϼ���

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main(){
    //freopen("in.txt","r",stdin);
    int n,m;
    int a[15];
//  for(int i = 1; i < 15; i++)a[i] = a[i-1]*4+pow(2,i);//�Լ��ҵĹ���
    for(int i = 1; i < 15; i++)a[i] = (pow(2,i)-1)*pow(2,i-1);
    while(scanf("%d",&n) != EOF){
        for(int i = 14; i >= 1; i--)if(n%a[i] == 0&&n>=a[i]){
            printf("%d\n",a[i]);
            break;
        }
    }
    return 0;
}
