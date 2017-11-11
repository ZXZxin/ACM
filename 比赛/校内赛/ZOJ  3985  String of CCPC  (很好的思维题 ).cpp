//题目链接：https://vjudge.net/contest/198250#problem/C
/*题目大意：
    给你一个只包含C和P的字符串，你每次可以在其中添加一个字符
    第k次添加字符要消耗k-1元
    统计字符串中CCPC的数量，每有一个CCPC你就会获得1元
    求最大收益*/
/*解题思路：
    你最多只用添加1次，因为你每次添加最多只会多一个CCPC，也就是赚到1块，可第2次开始就不免费了得不偿失
    一眼方法就是遇到"CCC"、"CPC"、"CCP"就添加，答案+1（只+一次）
    但很显然不对，就像CCCPC，如果你在CCC中间添加一个P，会成CCPCPC，原本的CCPC就没了
    所以还要特判下是否影响到之前已经有的CCPC
*/
#include <iostream>
#include <stdio.h>

using namespace std;
const int maxn = 200005+10;
char str[maxn];
bool flag[maxn];

int main(){
    int T,n;
    cin>>T;
    while(T--){
        int temp = 0,sum = 0;
        cin>>n;
        cin>>str;
        for(int i = 0; i < n; i++)flag[i] = false;
        for(int i = 0; i < n - 2; i++){
            if(str[i] == 'C'&&str[i+1] == 'C'&&str[i+2] == 'P'&&str[i+3] == 'C')
                sum++,flag[i] = true;
        }
        for(int i = 0; i < n-2; i++){
            if(flag[i])continue;
            if(str[i] == 'C'&&str[i+1] == 'C'&&str[i+2] == 'C'&&flag[i+1] == false)temp = 1;
            else if(str[i] == 'C'&&str[i+1] == 'P'&&str[i+2] == 'C'&&flag[i-1] == false)temp = 1;
            else if(str[i] == 'C'&&str[i+1] == 'C'&&str[i+2] == 'P')temp = 1;
        }
        cout<<sum + temp<<endl;
    }
    return 0;
}
