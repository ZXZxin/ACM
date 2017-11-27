//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1018
//题目大意：给你n,求n的阶乘的位数
//解题思路：首先知道求某个数的位数的公式：x = (int)log10(a)+1
        //求n的阶乘的位数就是(int)log10(a1*a2*a3*...*an)+1 = int(log10(a1) +1og10(a2) + ..)+1   


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cmath>
using namespace std;

//求某个数的位数x = (int)log10(a) + 1

int main(){
    //freopen("in","r",stdin);
    //ios_base::sync_with_stdio(0);cin.tie(0);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		double sum = 0;
		for(int i = 1; i <= n; i++){
			sum += log10(i);
		}
		cout<<(int)sum+1<<endl;
	}
	return 0;
 }

