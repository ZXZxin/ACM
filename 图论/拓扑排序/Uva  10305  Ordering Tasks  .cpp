//题目链接：https://vjudge.net/contest/171957#problem/O
//题目大意：假设有n个变量，还有m个二元组（u,v）,分别表示u<v，
           //那么，所有变量从小到大排列起来是什么样子。
//解体思路：模板简单拓扑排序

//第一种：BFS+邻接矩阵
#include <iostream>
#include <string.h>
#include <queue>
#define maxn 1000
using namespace std;

int graph[maxn][maxn],disgree[maxn],ans[maxn];
int m,n;

void topo()
{
	int k=0;
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(disgree[i]==0)//先把度为0 的入队
			q.push(i);

	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		ans[k++]=temp;
		for(int i=1;i<=n;i++)//寻找下一个入度为0的顶点
			if(graph[temp][i]!=0)
				if(--disgree[i]==0)
					q.push(i);
	}
  cout<<ans[0];
  for(int i=1;i<k;i++)
  cout<<" "<<ans[i];
  cout<<endl;
}


int main()
{
	int a,b;
    while(cin>>n>>m&&(n||m))
    {
     memset(graph, 0, sizeof(graph));
     memset(disgree, 0, sizeof(disgree));
       for(int i=0;i<m;i++)
       {
       	  cin>>a>>b;
          graph[a][b]=1;//记录是否有边
          disgree[b]++;//记录度
       }
    topo();
    }
	return 0;
}

//第二种：邻接表+广度优先搜索
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define maxn  5005

typedef struct///邻接表实现
{
	int next_arc;//下一条边
	int point;
}Arc;///边的结构体，

Arc arc[maxn];//储存每条边
int node[maxn];//储存每个顶点，node[i]表示第i个顶点指向的第一条边在arc中的位置
int disgree[maxn];
int top[maxn];

int n, m;


void topo()
{
	int k = 0;
	queue<int>q;
	for (int i = 1; i <= n; i++)
		if (disgree[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		top[k++] = temp;
		for (int i = node[temp]; i != -1; i = arc[i].next_arc)
			if (--disgree[arc[i].point] == 0)
				q.push(arc[i].point);
	}
	cout << top[0];
	for (int i = 1; i < k; i++)
		cout << " " << top[i];
	cout << endl;
}


int main()
{
	int a, b;
	while (cin >> n >> m && (m || n))
	{
		memset(node, -1, sizeof(node));
		memset(disgree, 0, sizeof(disgree));
		for (int i = 1; i <= m; i++)
		{
			cin >> a >> b;
			arc[i].next_arc = node[a];//第一次是出发点，以后是下一个
			arc[i].point = b;
			node[a] = i;
			disgree[b]++;
		}
		topo();
	}
	return 0;
}

//第三种：邻接矩阵+DFS
#include <iostream>
#include <string.h>
#define maxn 1000
using namespace std;

int n, m, t;
int graph[maxn][maxn], vis[maxn], ans[maxn];


void dfs(int v)
{
	for (int j = 1; j <= n; j++)
		if (graph[v][j])
			if (!vis[j])
				dfs(j);
	vis[v] = 1;
	ans[--t] = v;
}

int main()
{
	int a, b;
	while (cin >> n >> m && (m || n))
	{
		memset(vis, 0, sizeof(vis));
		memset(graph, 0, sizeof(graph));
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			graph[a][b] = 1;
		}
		t = n;
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i);
		for (int i = 0; i < n - 1; i++)
			cout << ans[i] << " ";
		cout << ans[n - 1] << endl;
	}
	return 0;
}

//第四种：邻接表+DFS
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define maxn  5005

typedef struct///邻接表实现
{
	int next_arc;///下一条边
	int point;
} Arc; ///边的结构体，

Arc arc[maxn];///储存每条边
int node[maxn];///储存每个顶点，node[i]表示第i个顶点指向的第一条边在arc中的位置
int vis[maxn];
int top[maxn];

int n, m, t;

void dfs(int v)
{
	for (int i = node[v]; i != -1; i = arc[i].next_arc)
	{
		if (!vis[arc[i].point])
		{
			dfs(arc[i].point);
		}
	}
	vis[v] = 1;
	top[--t] = v;
}


int main()
{
	int a, b;
	while (cin >> n >> m && (m || n))
	{
		memset(node, -1, sizeof(node));
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= m; i++)
		{
			cin >> a >> b;
			arc[i].next_arc = node[a];///第一次是出发点，以后是下一个
			arc[i].point = b;
			node[a] = i;
			vis[arc[i].point] = 0;
		}
		t = n;
		for (int j = 1; j <= n; j++)
			if (!vis[j])
				dfs(j);
		for (int i = 0; i < n - 1; i++)
			cout << top[i] << " ";
		cout << top[n - 1] << endl;
	}
	return 0;
}