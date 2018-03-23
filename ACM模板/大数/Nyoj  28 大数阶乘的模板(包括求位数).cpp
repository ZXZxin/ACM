//http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=28
//大数阶乘的模板

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;
const int maxn = 100000 + 10;


//大数计算阶乘位数
//lg(N!)=[lg(N*(N-1)*(N-2)*......*3*2*1)]+1 = [lgN+lg(N-1)+lg(N-2)+......+lg3+lg2+lg1]+1;
int Factorial_digit(int n){
    double sum = 0;
    for(int i = 1; i <= n; i++){
        sum += log10(i);
    }
    return (int)sum+1;
}

//大数计算阶乘
string Big_Factorial(int n){
    int ans[maxn],digit = 1;
    ans[0] = 1;
    for(int i = 2; i <= n; i++){
        int num = 0;
        for(int j = 0; j < digit; j++){
            int temp = ans[j]*i + num;
            ans[j] = temp%10;
            num = temp/10;
        }
        while(num != 0){
            ans[digit] = num%10;
            num /= 10;
            digit++;
        }
    }
    string str = "";
    for(int i = digit-1; i >= 0; i--)str += ans[i] + '0';
    return str;
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        //cout<<Factorial_digit(n)<<endl; //阶乘的位数
        cout<<Big_Factorial(n)<<endl;  //求出阶乘
    }
    return 0;
}
