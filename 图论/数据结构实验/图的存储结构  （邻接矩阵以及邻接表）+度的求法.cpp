//数据结构实验（图）图的邻接矩阵和邻接表以及度的求法


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define Maxvex 100
#define Infinity 65535
using namespace std;

typedef char VertexType;
typedef int EdgeType;

typedef struct{
	VertexType vexs[Maxvex]; //顶点表
	EdgeType arc[Maxvex][Maxvex]; //邻接矩阵，可看作边表
	int numVertexes,numEdges;  //图中当前的顶点数和边数
}MGraph;


//有了上面的结构定义，构造一个图，其实就是给顶点表和边表输入数据的过程。
//建立无向网图的邻接矩阵表示
void CreateMGraph(MGraph *G,char *filename){
    FILE *in;
    if((in = fopen(filename,"r")) == NULL){cout<<"cannot open the file"<<endl;exit(0);}
	int weight;
	//printf("请输入顶点数和边数：\n");
	fscanf(in,"%d %d",&G->numVertexes,&G->numEdges);
	for(int i = 0; i < G->numVertexes; i++) fscanf(in,"%d",&G->vexs[i]);
	for(int i = 0; i < G->numVertexes; i++)
		for(int j = 0;j < G->numVertexes; j++)
			G->arc[i][j] = Infinity; //邻接矩阵初始化
    int i,j;
	for(int k = 0;k < G->numEdges; k++){//printf("输入边(vi,vj)的下标i,下标j和权w：\n");
		fscanf(in,"%d %d %d",&i,&j,&weight);
		G->arc[i][j] = weight;
		G->arc[j][i] = G->arc[i][j];
	}
}

void print(MGraph *G){
    for(int i = 0; i < G->numVertexes; i++){
        int sum = 0;
        cout<<"与"<<i<<"相连的边有：";
        for(int j = 0; j < G->numVertexes; j++)if(G->arc[i][j] != Infinity){cout<<j<<" ";sum++;}
        cout<<endl;
        cout<<i<<" 的度是 "<<sum<<endl;
    }
}

int main(){
    MGraph G;
    char s[10] = "in.txt";
    CreateMGraph(&G,s);
    print(&G);
    return 0;
}
/*
6 7
0 1 2 3 4 5
0 1 1
0 2 1
1 3 1
1 4 1
2 5 1
3 4 1
4 5 1
*/


#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define M 20					/*预定义图的最大顶点数*/
using namespace std;
typedef char DataType;  /*顶点信息数据类型*/
typedef struct node     /*边表结点*/
{
    int adjvex;                  /*邻接点*/
    struct node *next;
} EdgeNode;

typedef struct vnode    /*头结点类型*/
{
    DataType vertex;         /*顶点信息*/
    EdgeNode *FirstEdge; /*邻接链表头指针*/
} VertexNode;
typedef struct            /*邻接表类型*/
{
    VertexNode adjlist[M];  /*存放头结点的顺序表*/
    int n,e;                 /*图的顶点数与边数*/
} LinkedGraph;

void creat(LinkedGraph *g,char *filename,int c)
{
    int i,j,k;
    EdgeNode *s;
    FILE *fp;
    fp=fopen(filename,"r");
    if (fp){
        fscanf(fp,"%d%d",&g->n,&g->e);              /*读入顶点数与边数*/
        for(i = 0; i < g->n; i++){
            fscanf(fp,"%1s",&g->adjlist[i].vertex);    /*读入顶点信息*/
            g->adjlist[i].FirstEdge = NULL;         /*边表置为空表*/
        }
        for(k = 0; k < g->e; k++){                   /*循环e次建立边表*/
            fscanf(fp,"%d%d",&i,&j);                 /*输入无序对（i,j）*/
            s = (EdgeNode *)malloc(sizeof(EdgeNode));
            s->adjvex = j;                         /*邻接点序号为j*/
            s->next = g->adjlist[i].FirstEdge;
            g->adjlist[i].FirstEdge=s;           /*将新结点*s插入顶点vi的边表头部*/
            if (c == 0){                            /*无向图*/
                s = (EdgeNode *)malloc(sizeof(EdgeNode));
                s->adjvex = i;                         /*邻接点序号为i*/
                s->next = g->adjlist[j].FirstEdge;
                g->adjlist[j].FirstEdge = s;           /*将新结点*s插入顶点vj的边表头部*/
            }
        }
        fclose(fp);
    }
    else
        g->n = 0;
}

void print(LinkedGraph g){
   EdgeNode *p;
   for(int i=0;i<g.n;i++){
        printf("%c",g.adjlist[i].vertex);
        p=g.adjlist[i].FirstEdge;
        while (p){ printf("-->%d",p->adjvex);p=p->next;}
    printf("\n");
   }
}

void cacluatedu(LinkedGraph *g){
    EdgeNode *s;
    for(int i = 0; i < g->n; i++){
          int sum = 0;
          s = (EdgeNode *)malloc(sizeof(EdgeNode));
          s = g->adjlist[i].FirstEdge;
          while(s){sum++;s = s->next;}
          cout<<i<<"  的度是  "<<sum<<endl;
    }
}

int main(){
    FILE *in;
    char s[10] = "in.txt";
    LinkedGraph G;
    int flag = 0;
    creat(&G,s,flag);
    print(G);
    cout<<endl;
    cacluatedu(&G);
    return 0;
}
/*
6	7
012345
0 1
0 2
1 3
1 4
2 5
3 4
4 5
*/



