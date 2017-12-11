//题目链接;https://vjudge.net/contest/201583#problem/F
//题目大意：就是给你一个字符串，求从某个下标位置开始，寻找一个字典序最大的长度为n的字符串，如果一样大，选择下标小的（可以顺逆时针）
//解题思路：可以暴力枚举，先把最大的下标找出来，然后关键用substr取一些长度为n的字符串，然后比大小

//PS:网上说还有后缀数组，以及KMP的解法，到时候再学
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;
const int maxn = 20000 + 10;
string str;

int main(){
    //freopen("in.txt","r",stdin);
    int T,n,ans,dir;//dir表示顺时针还是逆时针
    scanf("%d",&T);
    while(T--){
        string newstr,beststr;
        char maxch;
        ans = 1;
        dir = 0;
        scanf("%d",&n);
        cin>>str;
        maxch = str[0];
        beststr = str;
        for(int i = 0; i < n; i++)if(str[i] > maxch)maxch = str[i];
        str += str;//为了组成环
        for(int i = 0; i < n; i++){
            if(str[i] == maxch){
                newstr = str.substr(i,n);
                if(newstr > beststr){
                    dir = 0;
                    ans = i + 1;
                    beststr = newstr;
                }
            }
        }
        reverse(str.begin(),str.end());
        for(int i = 0; i < n; i++){
            if(str[i] == maxch){
                newstr = str.substr(i,n);
                if(newstr > beststr){
                    dir = 1;
                    ans = n - i;
                    beststr = newstr;
                }
                else if(newstr == beststr && ans > n - i){
                    dir = 1;
                    ans = n - i;
                    beststr = newstr;
                }
            }
        }
        printf("%d %d\n",ans,dir);
    }
    return 0;
}

