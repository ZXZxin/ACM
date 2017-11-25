//题目链接：https://vjudge.net/contest/77417#problem/A
//题目大意：输入若干行字符串（若干个单词）将各列单词对齐输出
//解题思路：找出每一列的最长的字符串，其他行的补齐空格就是的，注意不能输出多的空格（最后一个单词也是）（wa了好几次）

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
using namespace std;

const int maxn = 1000 + 10;
int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);//可能可以加速吧
	string a[maxn][maxn];
	string s,str;
	int row = 0,col;
	int coll[maxn];
	while(getline(cin,s)){
        col = 0;
		stringstream ss(s);
		while(ss>>str)a[row][col++] = str;
		coll[row++] = col;  //coll数组记录每一行的列数
	}
	int ans[maxn];
    int k = 0,p = 0;
	for(int j = 0; j < coll[p],p < row; j++,p++){   //找每一列的最大的字符串的长度
		int num = a[0][j].length();
		for(int i = 1; i < row; i++){
			if(a[i][j].length() > num){
				num = a[i][j].length();
			}
		}
		ans[k++] = num;
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < coll[i] - 1; j++){
			cout<<a[i][j]<<" ";
			for(int p = 0; p < ans[j] - a[i][j].length(); p++)cout<<" ";//多了的补空格
		}
		cout<<a[i][coll[i]-1]<<endl;
	}
	return 0;
 }
