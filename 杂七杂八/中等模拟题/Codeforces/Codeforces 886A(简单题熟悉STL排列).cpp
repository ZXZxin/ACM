//题目链接：http://codeforces.com/problemset/problem/886/A
//题目大意：给你6个数，问能不能分成相同的两组
//解题思路：可以直接暴力，这里放枚举排列的算法


#include <bits/stdc++.h>
using namespace std ;
int main (){
    int a[7];
    for(int i = 0; i < 6; i++)cin>>a[i];
    sort(a,a+6);
    do{
        if(a[0]+a[1]+a[2] == a[3]+a[4]+a[5]){
            cout<<"YES";return 0;
        }
    }
    while(next_permutation(a,a+6));
    cout<<"NO";
    return 0;
}

