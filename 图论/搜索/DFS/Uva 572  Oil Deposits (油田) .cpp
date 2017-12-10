//题目链接：https://vjudge.net/contest/169966#problem/L
//题目大意：简单的求连通块的题目
//解题思路：直接DFS搜索

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;
const int maxn = 100 + 10;
char str[maxn][maxn];
int vis[maxn][maxn];
int idr[8][2] = {-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};
int n,m;

void DFS(int x,int y){
	if(x < 0||x >= n||y < 0||y >= m)return;
	//if(vis[x][y]||str[x][y] != '@')return ;
	vis[x][y] = true;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 2; j++){
			int fx = x + idr[i][0];
			int fy = y + idr[i][1];
			if(!vis[fx][fy]){
				if(str[fx][fy] == '@')
				DFS(fx,fy);
			}
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&m) != EOF&&n != 0 && m != 0){
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < n; i++){
			scanf("%s",str[i]);
		}
		int count = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(str[i][j] == '@')
				if(!vis[i][j]){
					DFS(i,j);
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
