#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#define maxn 20

using namespace std;
typedef char DataType;  /*顶点信息数据类型*/
typedef struct node     /*边表结点*/
{
    int adjvex;                  /*邻接点*/
    struct node *next;
} EdgeNode;
int visited[maxn];	/*预定义图的最大顶点数*/

typedef struct vnode    /*头结点类型*/
{
    DataType vertex;         /*顶点信息*/
    EdgeNode *FirstEdge; /*邻接链表头指针*/
} VertexNode;

typedef struct            /*邻接表类型*/
{
    VertexNode adjlist[maxn];  /*存放头结点的顺序表*/
    int n,e;                 /*图的顶点数与边数*/
} LinkedGraph;

/*函数功能：建立图的邻接表
  函数参数：邻接表指针变量g；存放图信息的文件名filename;图的类型参数c，c=0表示建立无向图，否则表示建立有向图
  函数返回值：无
*/
void creat(LinkedGraph *g,char *filename,int c)
{
    int i,j,k;
    EdgeNode *s;
    FILE *fp;
    fp=fopen(filename,"r");
    if (fp)
    {
        fscanf(fp,"%d%d",&g->n,&g->e);              /*读入顶点数与边数*/
        for(i = 1; i <= g->n; i++)
        {
            fscanf(fp,"%1s",&g->adjlist[i].vertex);    /*读入顶点信息*/
            g->adjlist[i].FirstEdge=NULL;         /*边表置为空表*/
        }
        for(k = 1; k <= g->e; k++)                   /*循环e次建立边表*/
        {
            fscanf(fp,"%d%d",&i,&j); /*输入无序对（i,j）*/
            s=(EdgeNode *)malloc(sizeof(EdgeNode));
            s->adjvex=j;                         /*邻接点序号为j*/
            s->next=g->adjlist[i].FirstEdge;
            g->adjlist[i].FirstEdge=s;           /*将新结点*s插入顶点vi的边表头部*/
            if (c == 0)                            /*无向图*/
            {
                s=(EdgeNode *)malloc(sizeof(EdgeNode));
                s->adjvex=i;                         /*邻接点序号为i*/
                s->next=g->adjlist[j].FirstEdge;
                g->adjlist[j].FirstEdge=s;           /*将新结点*s插入顶点vj的边表头部*/
            }
        }
        fclose(fp);
    }
    else
        g->n=0;
}

/*请将本函数补充完整，并进行测试*/

void dfs(LinkedGraph g,int i)
{
    EdgeNode *p;
    printf("visit vertex: %c \n",g.adjlist[i].vertex);/*访问顶点i*/
    visited[i] = 1;
    p = g.adjlist[i].FirstEdge;
    while (p)                /*从p的邻接点出发进行深度优先搜索*/
    {
        if(!visited[p->adjvex])dfs(g,p->adjvex);
        p = p->next;
    }
}
/*函数功能：深度优先遍历图
  函数参数：图的邻接表g
*/
void DfsTraverse(LinkedGraph g)
{
    int i;
    for (i = 1; i <= g.n; i++)
        visited[i] = 0;     /*初始化标志数组*/
    for (i = 1; i <= g.n; i++)
        if (!visited[i])  /*vi未访问过*/
            dfs(g,i);
}

void bfs(LinkedGraph g, int i)
{
    queue<int>q;
    EdgeNode *p;
    /*从顶点i出发广度优先变量图g的连通分量*/
    printf("visit vertex: %d ",i);/*访问顶点i*/
    visited[i] = true;
    q.push(i);
    p = g.adjlist[i].FirstEdge;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        p = g.adjlist[now].FirstEdge;
        while(p)
        {
            if(!visited[p->adjvex])
            {
                cout<<p->adjvex<<" ";
                visited[p->adjvex] = true;
                q.push(p->adjvex);
            }
            else p = p->next;
        }
    }
}

/*函数功能：广度优先遍历图g
  函数参数：邻接表g
*/
int BfsTraverse(LinkedGraph g)
{
    int i,count = 0;
    for (i = 1; i <= g.n; i++)
        visited[i]=0;     /*初始化标志数组*/
    for (i = 1; i <= g.n; i++)
        if (!visited[i])  /*vi未访问过*/
        {
            printf("\n");
            count++;            /*连通分量个数加1*/
            bfs(g,i);
        }
    return count;
}
/*---函数print():输出邻接表存储结构---*/
void print(LinkedGraph  g)
{
    EdgeNode *p;
    int i;
    for (i = 1; i <= g.n; i++)
    {
        printf("%c",g.adjlist[i].vertex);
        p = g.adjlist[i].FirstEdge;
        while (p)
        {
            printf("-->%d",p->adjvex);
            p = p->next;
        }
        printf("\n");
    }
}
int main()
{
    LinkedGraph g;
    creat(&g,"in.txt",0);  	/*已知g11.txt中存储了图的信息*/
    printf("The graph is:\n");
    print(g);
    printf("\n");
    cout<<"DFS遍历为:"<<endl;
    DfsTraverse(g);
    printf("\n");
    cout<<"BFS遍历为:";
    BfsTraverse(g);
    printf("\n");
    return 0;
}
/*
8 9
12345678
1 2
1 3
2 4
2 5
3 6
3 7
4 8
5 8
6 7
*/

