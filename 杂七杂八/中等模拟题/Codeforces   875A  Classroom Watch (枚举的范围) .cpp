//��Ŀ���ӣ�http://codeforces.com/problemset/problem/876/C
//��Ŀ���⣺���Ǹ���һ����������������������Щ�������Լ��������ÿһλ�ϵ�������λ��ʮλ�ȵȣ������������
//����˼·����Ŀ���ѣ�ģ�⼴�ɣ�����Ҫע��ö�ٵ�����������ǹؼ�����Ϊ���ֻ��10��9�η���ֻ��Ҫö�ٵ�С�������ǰ��81��������

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include<cmath>
using namespace std;
const int maxn = 1000 + 10;
int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);
    long i, temp, sum, n;
    int res[100],ans = 0;
    cin>>n;
    for (i = n - 90; i < n; ++i){  //��һ���ǹؼ���ֻ��Ҫö��С��9*9����
        sum = i,temp = i;
        while (temp > 0){
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == n){
            res[ans++] = i;
        }
    }
    printf("%d\n", ans);
    for (i = 0; i < ans; i++)printf("%ld\n", res[i]);
    return 0;
}
