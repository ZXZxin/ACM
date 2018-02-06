//题目链接：https://vjudge.net/contest/171111#problem/A
//题目大意: 就是给你一个2 - 79之间的数，问在 1000 - 100000之间的数哪些可以组成 abcde / efghi = n的情况，注意前导0
//解题思路: 这个枚举的方式和一般的不同这个是反向的枚举，重点是掌握这种思想

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 100 + 10;
using namespace std;

bool Ok(int x,int y){  //判断是不是一个 0123456789 的排列(没有重复的数字)
    int vis[15];
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < 5; i++){
        vis[x%10]++; vis[y%10]++;
        if(vis[x%10] > 1 || vis[y%10] > 1)return false;
        x /= 10; y /= 10;
    }
    return true;
}

int main(){
    int n,kase = 0;
    while(scanf("%d",&n) != EOF && n != 0){
        if(kase++)printf("\n");//惨绝人寰的输出
        bool flag = false;
        for(int i = 1000; ; i++){
            if(Ok(i,i*n)){
                flag = true;
                printf("%05d / %05d = %d\n",i*n,i,n);
            }
            if(i*n > 98765)break;
        }
        if(!flag)printf("There are no solutions for %d.\n",n);
    }
    return 0;
}


//刘汝佳的解法 (掌握 sprintf(str,"%05d%05d",i,i*n))的用法
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int maxn = 100 + 10;
using namespace std;

int main(){
    int n,kase = 0;
    char s[20];
    while(scanf("%d",&n) != EOF && n != 0){
        if(kase++)printf("\n");//惨绝人寰的输出
        int cnt = 0;
        for(int i = 1234;; i++){
            sprintf(s,"%05d%05d",i,i*n);//掌握这个用法
            if(strlen(s) > 10)break;
            sort(s,s+10);
            bool flag = true;
            for(int i = 0; i < 10; i++) if(s[i] - '0' != i){flag = false;break;}
            if(flag){
                cnt++;
                printf("%05d / %05d = %d\n",i*n,i,n);
            }
        }
        if(!cnt)printf("There are no solutions for %d.\n",n);
    }
    return 0;
}

