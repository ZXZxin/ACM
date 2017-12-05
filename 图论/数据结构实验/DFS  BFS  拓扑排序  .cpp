//数据结构  BFS  DFS   拓扑排序
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 100 + 10;
typedef int DataType;
typedef struct node{
	int adjvex;
	//int weight; //可以定义边的权值
	struct node *next;
}EdgeNode;
typedef struct vnode{
	DataType vertex;//顶点域
	int inDegree;//表示顶点的入度
	EdgeNode *FirstEdge;
}VertexNode;
typedef struct{
	VertexNode adjlist[maxn];
	int n,e;
}LinkGraph;
bool vis[maxn];

void CreatGraph(LinkGraph *G,int flag){
	EdgeNode *s;
	DataType u,v;
	scanf("%d%d",&G->n,&G->e);
	for(int i = 0; i < G->n; i++){
		scanf("%d",&G->adjlist[i].vertex);
		G->adjlist[i].FirstEdge = NULL;
		G->adjlist[i].inDegree = 0;
	}
	for(int i = 0; i < G->e; i++){//注意输入的int的顶点要从0开始
		scanf("%d%d",&u,&v);
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = v;
		s->next = G->adjlist[u].FirstEdge;
		G->adjlist[u].FirstEdge = s;
		G->adjlist[v].inDegree++;
		if(flag == 0){
			s = (EdgeNode*)malloc(sizeof(EdgeNode));
			s->adjvex = u;
			s->next = G->adjlist[v].FirstEdge;
			G->adjlist[v].FirstEdge = s;
			G->adjlist[u].inDegree++;
		}
	}
}

void DFS(LinkGraph G,DataType u){
	vis[u] = true;
	printf("%d ",u);
	for(EdgeNode* p = G.adjlist[u].FirstEdge; p != NULL; p = p->next){
		if(!vis[p->adjvex])DFS(G,p->adjvex);
	}
}

void BFS(LinkGraph G,int u){
	queue<DataType>q;
	q.push(u);
	vis[u] = true;
	while(!q.empty()){
		DataType now = q.front();q.pop();
		printf("%d ",G.adjlist[now].vertex);
		for(EdgeNode* p = G.adjlist[now].FirstEdge; p != NULL; p = p->next){
			if(!vis[p->adjvex]){
				q.push(p->adjvex);
				vis[p->adjvex] = true;
			}
		}
	}
}

void topo(LinkGraph *G){
	queue<DataType>q;
	for(int i = 0; i < G->n; i++){
		if(G->adjlist[i].inDegree == 0)q.push(i);
	}
	while(!q.empty()){
		DataType now = q.front();q.pop();
		printf("%d ",now);
		for(EdgeNode* p = G->adjlist[now].FirstEdge; p != NULL; p = p->next){
			if(--G->adjlist[p->adjvex].inDegree == 0)q.push(p->adjvex);
		}
	}
}
void print(LinkGraph G){
	for(int i = 0; i < G.n; i++){
		printf("与%d相连的边: ",G.adjlist[i].vertex);
		for(EdgeNode *p = G.adjlist[i].FirstEdge; p != NULL; p = p->next)printf("%d ",p->adjvex);
		printf("\n");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int flag = 1;//只有又向无环图有拓扑排序
	memset(vis,false,sizeof(vis));
	LinkGraph G;
	CreatGraph(&G,flag);
	printf("The Graph is :\n");
	print(G);
	int count = 0;
	for(int i = 0; i < G.n; i++){
		if(!vis[G.adjlist[i].vertex]){
			printf("DFS连通分量的起始点：%d\n",G.adjlist[i].vertex);//输出连通分量的起始位置
			DFS(G,G.adjlist[i].vertex);
			printf("\n");
			count++;//可以记录连通分量的数量
		}
	}
	printf("DFS连通分量的个数：%d\n",count);
	memset(vis,false,sizeof(vis));
	count = 0;
	for(int i = 0; i < G.n; i++){
		if(!vis[G.adjlist[i].vertex]){
			printf("BFS连通分量的起始点：%d\n",G.adjlist[i].vertex);//输出连通分量的起始位置
			BFS(G,G.adjlist[i].vertex);
			count++;
		}
	}
	printf("\nBFS连通分量的个数：%d\n",count);
	printf("拓扑序列为：\n");
	topo(&G);
	return 0;
}
/*
8 9
0 1 2 3 4 5 6 7
0 1
0 2
1 3
1 4
2 5
2 6
3 7
4 7
5 6
*/


