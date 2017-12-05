//�ؼ�·���㷨ʵ��
//ѧϰ���ͣ�https://www.cnblogs.com/Braveliu/p/3461649.html
        //https://www.cnblogs.com/hongyang/p/3407666.html

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 100 + 10;
typedef int DataType;
typedef struct node{
	int adjvex;//�ڽӵ��򣬴���ö����Ӧ���±�
	int weight; //���Զ���ߵ�Ȩֵ
	struct node *next;
}EdgeNode;
typedef struct vnode{
	DataType vertex;//������ֵ��
	int inDegree;//��ʾ��������
	EdgeNode *FirstEdge;
}VertexNode;
typedef struct{
	VertexNode adjlist[maxn];
	int n,e;
}LinkGraph;

bool vis[maxn];
stack<DataType>s2;

void CreatGraph(LinkGraph *G,int flag){
	EdgeNode *s;
	DataType u,v,w;
	scanf("%d%d",&G->n,&G->e);
	for(int i = 0; i < G->n; i++){
		scanf("%d",&G->adjlist[i].vertex);
		G->adjlist[i].FirstEdge = NULL;
		G->adjlist[i].inDegree = 0;
	}
	for(int i = 0; i < G->e; i++){//ע�������int�Ķ���Ҫ��0��ʼ
		scanf("%d%d%d",&u,&v,&w);
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = v;
		s->weight = w;
		s->next = G->adjlist[u].FirstEdge;
		G->adjlist[u].FirstEdge = s;
		G->adjlist[v].inDegree++;
		if(flag == 0){
			s = (EdgeNode*)malloc(sizeof(EdgeNode));
			s->adjvex = u;
			s->weight = w;
			s->next = G->adjlist[v].FirstEdge;
			G->adjlist[v].FirstEdge = s;
			G->adjlist[u].inDegree++;
		}
	}
}

bool topo1(LinkGraph *G,int* pEtv){//��ÿ�����ʼ������ʱ�����������
    stack<DataType>s1;
    int cnt = 0;
    for(int i = 0; i < G->n; i++){
        if(G->adjlist[i].inDegree == 0)s1.push(i);
    }
    for(int i = 0; i < G->n; i++)pEtv[i] = 0;
    while(!s1.empty()){
        DataType now = s1.top();
        s1.pop();++cnt;
        s2.push(now);
        if(G->n == cnt){
            printf("%d\n",G->adjlist[now].vertex);
            break;
        }
        printf("%d-->",G->adjlist[now].vertex);
        for(EdgeNode*p = G->adjlist[now].FirstEdge; p != NULL; p = p->next){
            if(--G->adjlist[p->adjvex].inDegree == 0)s1.push(p->adjvex);
            if(pEtv[now] + p->weight > pEtv[p->adjvex])pEtv[p->adjvex] = pEtv[now] + p->weight;
        }
    }
    return cnt == G->n;
}

void CriticalPath(LinkGraph *G,int* pEtv,int* pLtv){
    int ete = 0,lte = 0;
    for(int i = 0; i < G->n; i++)pLtv[i] = pEtv[G->n-1];
    while(!s2.empty()){
        DataType now = s2.top();
        s2.pop();
        for(EdgeNode *p = G->adjlist[now].FirstEdge; p != NULL; p = p->next){
            if(pLtv[p->adjvex] - p->weight < pLtv[now])pLtv[now] = pLtv[p->adjvex] - p->weight;
        }
    }
    //��ete,lte,�͹ؼ�·��
    for(int i = 0; i < G->n; i++){
        for(EdgeNode *p = G->adjlist[i].FirstEdge; p != NULL; p = p->next){
            ete = pEtv[i];
            lte = pLtv[p->adjvex] - p->weight;
            if(ete == lte){//�ؼ��
                printf("<V%d,V%d>: %d\n",G->adjlist[i].vertex,G->adjlist[p->adjvex].vertex,p->weight);
            }
        }
    }
}

void print(LinkGraph G){
	for(int i = 0; i < G.n; i++){
		printf("��%d�����ı�: ",G.adjlist[i].vertex);
		for(EdgeNode *p = G.adjlist[i].FirstEdge; p != NULL; p = p->next)printf("%d ",p->adjvex);
		printf("\n");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int flag = 1;//ֻ�������޻�ͼ����������
	LinkGraph G;
	CreatGraph(&G,flag);
	printf("The Graph is :\n");
	print(G);
	int pEtv[maxn],pLtv[maxn];
	if(!topo1(&G,pEtv)){printf("�л�·\n");return -1;}
	printf("��ӡ����pEtv��ֵ������������翪ʼʱ�䣩:\n");
	for(int i = 0; i < G.n; i++)printf("%d ",pEtv[i]);
	printf("\n");
	printf("�ؼ�·��:\n");
	CriticalPath(&G,pEtv,pLtv);
	return 0;
}
/*
��������
10 13
0 1 2 3 4 5 6 7 8 9
0 1 3
0 2 4
1 3 5
1 4 6
2 3 8
2 5 7
3 4 3
4 6 9
4 7 4
5 7 6
6 9 2
7 8 5
8 9 3
*/
/*
0-->1-->2-->3-->4-->6-->5-->7-->8-->9
��ӡ����pEtv��ֵ������������翪ʼʱ�䣩:
0 3 4 12 15 11 24 19 24 27
�ؼ�·��:
<V0,V2> :4
<V2,V3> :8
<V3,V4> :3
<V4,V7> :4
<V7,V8> :5
<V8,V9> :3
*/


