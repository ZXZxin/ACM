//��Ŀ���ӣ�https://vjudge.net/contest/171957#problem/O
//��Ŀ���⣺������n������������m����Ԫ�飨u,v��,�ֱ��ʾu<v��
           //��ô�����б�����С��������������ʲô���ӡ�
//����˼·��ģ�����������

//��һ�֣�BFS+�ڽӾ���
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
		if(disgree[i]==0)//�ȰѶ�Ϊ0 �����
			q.push(i);

	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		ans[k++]=temp;
		for(int i=1;i<=n;i++)//Ѱ����һ�����Ϊ0�Ķ���
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
          graph[a][b]=1;//��¼�Ƿ��б�
          disgree[b]++;//��¼��
       }
    topo();
    }
	return 0;
}

//�ڶ��֣��ڽӱ�+�����������
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define maxn  5005

typedef struct///�ڽӱ�ʵ��
{
	int next_arc;//��һ����
	int point;
}Arc;///�ߵĽṹ�壬

Arc arc[maxn];//����ÿ����
int node[maxn];//����ÿ�����㣬node[i]��ʾ��i������ָ��ĵ�һ������arc�е�λ��
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
			arc[i].next_arc = node[a];//��һ���ǳ����㣬�Ժ�����һ��
			arc[i].point = b;
			node[a] = i;
			disgree[b]++;
		}
		topo();
	}
	return 0;
}

//�����֣��ڽӾ���+DFS
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

//�����֣��ڽӱ�+DFS
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define maxn  5005

typedef struct///�ڽӱ�ʵ��
{
	int next_arc;///��һ����
	int point;
} Arc; ///�ߵĽṹ�壬

Arc arc[maxn];///����ÿ����
int node[maxn];///����ÿ�����㣬node[i]��ʾ��i������ָ��ĵ�һ������arc�е�λ��
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
			arc[i].next_arc = node[a];///��һ���ǳ����㣬�Ժ�����һ��
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