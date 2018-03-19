//题目链接 : https://vjudge.net/contest/173113#problem/A
//题目大意 : 就是给你一组数,要你经过一系列的翻转,来使得从上到下从小到大排序,输出步骤
        //  反转的规则就是某个编号以上的全部翻转过来,看下面的例子,步骤就是3,1
/*8 7 2
  4 6 5
  6 4 8
  7 8 4
  5 5 6
  2 2 7
*/
//解题思路 : 从下到上依此选择大的,如果不在最顶端,就先把剩下的最大的移到最顶端
            //然后再移动到选择排序的那个位置,有点选择排序的思想
/*
    8 2 7 4 6 5 4 2
    4 5 5 6 4 2 2 4
    6 7 2 2 2 4 5 5
    7 6 6 5 5 6 6 6
    5 4 4 7 7 7 7 7
    2 8 8 8 8 8 8 8
步骤: 1 4 2 5 3 4 5
*/
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
const int maxn = 100 + 10;

bool is_Sort(int *a,int n){
    for(int i = 0; i < n-1; i++)if(a[i] > a[i+1])return false;
    return true;
}

int main(){
    int a[maxn],n;
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        int n = 0;
        while(ss>>a[n])n++;
        int ans[maxn],len = 0; //记录编号
        for(int i = n-1; i >= 0; i--){
            if(is_Sort(a,n))break;
            int maxi = i,maxx = a[i],tmp;
            for(int j = i; j >= 0; j--)if(a[j] > maxx) { maxi = j; maxx = a[j]; }
            if(maxi == i)continue;
            if(maxi == 0){
                for(int k = 0; k < (i+1)/2 ;k++){tmp = a[k]; a[k] = a[i-k]; a[i-k] = tmp;}
                ans[len++] = n-i;
            }else {
                for(int k = 0; k < (maxi+1)/2; k++){tmp = a[k]; a[k] = a[maxi-k]; a[maxi-k] = tmp;}
                ans[len++] = n-maxi;
                for(int k = 0; k < (i+1)/2 ;k++){tmp = a[k]; a[k] = a[i-k]; a[i-k] = tmp;}
                ans[len++] = n-i;
            }
        }
        cout<<s<<endl;
        if(len != 0){
            for(int i = 0; i < len; i++)printf("%d ",ans[i]);
            printf("0\n");
        }else printf("0\n");
    }
    return 0;
}

