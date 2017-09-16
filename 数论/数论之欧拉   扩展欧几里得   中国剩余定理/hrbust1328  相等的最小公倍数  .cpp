//hrbust1328
//简单欧几里得
//（1）当n是素数时，易知不会满足条件。
/*（2）其次，在满足小于n的每一对因子中，
       如果存在不互质的一对因子a, b，则gcd(a, b) > 1,
       则lcm(a, b) = a*b / gcd(a, b) < n, 
       则如果在 < n的每一对因子中，每一对都不互质，
       则不可能满足上述条件，反之，只需要有一对满足上述条件即可。
       则问题转换为判断在小于n的每一对因子中是否存在一对因子不互质，枚举即可。*/

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
