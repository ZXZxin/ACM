//��Ŀ���ӣ�https://vjudge.net/contest/169967#problem/D
//��Ŀ����: ��������һ��8 * 8�����̣����һ��λ�õ���һ��λ�����ٵĲ���
//����˼·: ֱ��BFS���ɣ�ע��һЩϸ��

#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

const int N = 10;
using namespace std;
int sx,sy,ex,ey;
int dir[8][2] = { {-2,1} ,{-1,2}, {1,2} ,{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
bool vis[N][N];

struct node {
	int x, y,count;
};

bool check(int x, int y) {
	if (x >= 0 && x < 8 && y >= 0 && y < 8 && !vis[x][y])return true;
	else return false;
}

int BFS(int x, int y) {
    memset(vis, false, sizeof(vis));
	node Now,Next;
	queue<node>q;
	Now.x = x, Now.y = y, Now.count = 0;
	vis[Now.x][Now.y] = true;
	q.push(Now);
	while (!q.empty()) {
		Now = q.front();
		q.pop();
		if (Now.x == ex && Now.y == ey) {
			return Now.count;
		}
		for (int i = 0; i < 8; i++) {
			Next.x = Now.x + dir[i][0];
		    Next.y = Now.y + dir[i][1];
			if (check(Next.x, Next.y)) {
				vis[Next.x][Next.y] = true;
				Next.count = Now.count + 1;
				q.push(Next);
			}
		}
	}
}


int main() {
	//freopen("in.txt", "r", stdin);
	char c1, c2;
	int ans;
	while (cin>>c1>>sy>>c2>>ey) {
		sx = 7 - (c1 - 'a');//ת��������Ƚ��������ķ�ʽ
		sy -= 1;
		ex = 7 - (c2 - 'a');
		ey -= 1;
        //sx = c1 - 'a' + 1;
		//ex = c2 - 'a' + 1;
		if (sx == ex && sy == ey)ans = 0;
		else ans = BFS(sx,sy);
		printf("To get from %c%d to %c%d takes %d knight moves.\n",c1,sy+1,c2,ey+1,ans);//ע����������
	}
	return 0;
}

