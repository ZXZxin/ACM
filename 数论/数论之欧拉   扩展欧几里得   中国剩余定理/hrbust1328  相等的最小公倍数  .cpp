//hrbust1328
//��ŷ�����
//��1����n������ʱ����֪��������������
/*��2����Σ�������С��n��ÿһ�������У�
       ������ڲ����ʵ�һ������a, b����gcd(a, b) > 1,
       ��lcm(a, b) = a*b / gcd(a, b) < n, 
       ������� < n��ÿһ�������У�ÿһ�Զ������ʣ�
       �򲻿�������������������֮��ֻ��Ҫ��һ�����������������ɡ�
       ������ת��Ϊ�ж���С��n��ÿһ���������Ƿ����һ�����Ӳ����ʣ�ö�ټ��ɡ�*/

#include <iostream>
#include<math.h>
#define maxn 100
using namespace std;
typedef long long LL;

int gcd(int a, int b){
	if (b == 0)return a;
	return gcd(b, a%b);
}

int is_prime(int n){
	if (n <= 1)return 0;
	int m = sqrt(n + 0.5);
	for (int i = 2; i <= m; i++)
		if (n%i == 0)
			return 0;
	return 1;
}

int main(){
	int k, n;
	cin >> k;
	while (k--){
		cin >> n;
		if (is_prime(n)){
			cout << "NO" << endl;
			continue;
		}
		int flag = 0;
		for (int i = 2; i < n; i++){
			if (n%i == 0){
				int j = n / i;
				if (gcd(i, j) == 1){
					flag = 1;
					cout << "YES" << endl;
					break;
				}
			}
		}
		if (flag == 0) {
			cout << "NO" << endl;
		}
	}
	return 0;
}
