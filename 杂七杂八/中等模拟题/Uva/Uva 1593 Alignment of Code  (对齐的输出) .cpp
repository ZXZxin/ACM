//��Ŀ���ӣ�https://vjudge.net/contest/77417#problem/A
//��Ŀ���⣺�����������ַ��������ɸ����ʣ������е��ʶ������
//����˼·���ҳ�ÿһ�е�����ַ����������еĲ���ո���ǵģ�ע�ⲻ�������Ŀո����һ������Ҳ�ǣ���wa�˺ü��Σ�

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
    ios_base::sync_with_stdio(false);cin.tie(0);//���ܿ��Լ��ٰ�
	string a[maxn][maxn];
	string s,str;
	int row = 0,col;
	int coll[maxn];
	while(getline(cin,s)){
        col = 0;
		stringstream ss(s);
		while(ss>>str)a[row][col++] = str;
		coll[row++] = col;  //coll�����¼ÿһ�е�����
	}
	int ans[maxn];
    int k = 0,p = 0;
	for(int j = 0; j < coll[p],p < row; j++,p++){   //��ÿһ�е������ַ����ĳ���
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
			for(int p = 0; p < ans[j] - a[i][j].length(); p++)cout<<" ";//���˵Ĳ��ո�
		}
		cout<<a[i][coll[i]-1]<<endl;
	}
	return 0;
 }
