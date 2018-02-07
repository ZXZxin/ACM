//题目链接：https://vjudge.net/contest/171111#problem/E
//题目大意: 如果一个字符串包含两个相邻的重复字串，则称是"容易的串"，否则是"困难的串"，输入n,L,
           //输出由前L个字符组成的，字典序第n小的困难的串
//解题思路:时间方面要用回溯法，然后就是判断每一个偶数长度的后缀是不是满足条件

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;
int n,L;
int s[maxn];
int cnt;

bool DFS(int cur){
    if(cnt++ == n){
        for(int i = 0; i < cur; i++){
            if(i % 64 == 0 && i != 0)printf("\n");
            else if(i % 4 == 0 && i != 0)printf(" ");
            printf("%c",s[i]+'A');
        }
        printf("\n%d\n",cur);
        return false;
    }else for(int i = 0; i < L; i++){
        s[cur] = i;
        bool flag = true;
        for(int j = 1 ; j*2 <= cur+1; j++){//尝试长度为  j*2 的 后缀
            bool ok = false;
            for(int k = 0; k < j; k++)if(s[cur - k] != s[cur - k - j]){ok = true;break;}
            if(!ok){flag = false;break;}
        }
        if(flag)if(!DFS(cur+1))return false;
    }
    return true;
}

int main(){
    while(scanf("%d%d",&n,&L) != EOF && n){
        cnt = 0;
        DFS(0);
    }
    return 0;
}

