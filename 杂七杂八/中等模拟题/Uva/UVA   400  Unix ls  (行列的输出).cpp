//题目链接：https://vjudge.net/contest/77100#problem/H
//题目大意：给你n个字符串，要你按照字典序且是列的顺序输出，行列要求满足在60-列字符中，取输入的字符串中最长的一个串的长度M
            //除了最后一列，每一列占M+2个列，最后一列占M列
//解题思路：关键在于计算行与列，以及考虑怎样输出

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

const int maxn = 100+10;

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    while(cin>>n){
        int a[maxn];
        string s[maxn];
        int max_lenght = 0;
        for(int i = 0; i < n; i++){
            cin>>s[i];
            max_lenght = max(max_lenght,(int)s[i].length());
        }
        sort(s,s+n);
        int cols = (60 - max_lenght)/(max_lenght+2) + 1;//列数
        int rows = (n - 1)/cols + 1; //行数
        for(int i = 0; i < 60; i++)cout<<"-";cout<<endl;
        for(int i = 0; i < rows; i++){  //遍历行数
            for(int j = 0; j < cols; j++){   //每行输出
                if((i + rows*j) < n) cout<<s[i + rows*j];  //关键
                if(j == cols - 1){   //最后一列
                    for(int k = 0; k < max_lenght - s[i+rows*j].length(); k++)cout<<' ';
                }
                else {
                    for(int k = 0; k < max_lenght + 2 - s[i+rows*j].length(); k++)cout<<' ';
                }
            }
            cout<<endl;  //输出一行之后换行
        }
    }
    return 0;
}
