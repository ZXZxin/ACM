//题目链接 : https://www.patest.cn/contests/gplt/L1-006
//题目大意 : 中文题
//解题思路 : 先找出因子,然后暴力

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long LL;

const int maxn = 10000 + 10;

using namespace std;

int main() {
    LL n, num[maxn];
    int cnt = 0;
    cin >> n;
    for(LL i = 2; i <= sqrt(n); i++) {
        if(n % i == 0)
        { num[cnt++] = i; }
    }
    num[cnt++] = n;
    LL L = 0, R = 0, len, maxx = 0, i, j, ans;
    for(i = 0; i < cnt; i++) {
        len = 1;
        ans = num[i];
        for(j = i + 1; j < cnt; j++) {
            ans *= num[j];
            if(num[j] - num[j - 1] == 1 && n%ans == 0) len++;
            else break;
        }
        if(len > maxx) {
            L = i;
            R = j-1;
            maxx = len;
        }
    }
    cout << maxx << endl;
    for(LL i = L; i <= R; i++) {
        if(i == L) cout << num[i];
        else cout << "*" << num[i];
    }
    cout << endl;
    return 0;
}
