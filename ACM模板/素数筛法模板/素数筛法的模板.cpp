//素数筛选的模板 :   |埃式筛法|
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;
const int maxn = 1000 + 10;
int prime[maxn];
bool is_prime[maxn];

int Sieve(int n){
    int k = 0;
    for(int i = 0; i <= n; i++)is_prime[i] = true;
    is_prime[0] = false,is_prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            prime[k++] = i;
            for(int j = i*i; j <= n; j+=i)is_prime[j] = false; // 轻剪枝，j必定是i的倍数
        }
    }
    return k;
}

int main(){
    int len = Sieve(1000);
    for(int  i = 0; i < len; i++)cout<<prime[i]<<endl;
    return 0;
}
