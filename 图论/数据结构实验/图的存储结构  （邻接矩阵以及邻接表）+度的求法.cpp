//���ݽṹʵ�飨ͼ��ͼ���ڽӾ�����ڽӱ��Լ��ȵ���


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define Maxvex 100
#define Infinity 65535
using namespace std;

typedef char VertexType;
typedef int EdgeType;

typedef struct{
	VertexType vexs[Maxvex]; //�����
	EdgeType arc[Maxvex][Maxvex]; //�ڽӾ��󣬿ɿ����߱�
	int numVertexes,numEdges;  //ͼ�е�ǰ�Ķ������ͱ���
}MGraph;


//��������Ľṹ���壬����һ��ͼ����ʵ���Ǹ������ͱ߱��������ݵĹ��̡�
//����������ͼ���ڽӾ����ʾ
void CreateMGraph(MGraph *G,char *filename){
    FILE *in;
    if((in = fopen(filename,"r")) == NULL){cout<<"cannot open the file"<<endl;exit(0);}
	int weight;
	//printf("�����붥�����ͱ�����\n");
	fscanf(in,"%d %d",&G->numVertexes,&G->numEdges);
	for(int i = 0; i < G->numVertexes; i++) fscanf(in,"%d",&G->vexs[i]);
	for(int i = 0; i < G->numVertexes; i++)
		for(int j = 0;j < G->numVertexes; j++)
			G->arc[i][j] = Infinity; //�ڽӾ����ʼ��
    int i,j;
	for(int k = 0;k < G->numEdges; k++){//printf("�����(vi,vj)���±�i,�±�j��Ȩw��\n");
		fscanf(in,"%d %d %d",&i,&j,&weight);
		G->arc[i][j] = weight;
		G->arc[j][i] = G->arc[i][j];
	}
}

void print(MGraph *G){
    for(int i = 0; i < G->numVertexes; i++){
        int sum = 0;
        cout<<"��"<<i<<"�����ı��У�";
        for(int j = 0; j < G->numVertexes; j++)if(G->arc[i][j] != Infinity){cout<<j<<" ";sum++;}
        cout<<endl;
        cout<<i<<" �Ķ��� "<<sum<<endl;
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
#define M 20					/*Ԥ����ͼ����󶥵���*/
using namespace std;
typedef char DataType;  /*������Ϣ��������*/
typedef struct node     /*�߱���*/
{
    int adjvex;                  /*�ڽӵ�*/
    struct node *next;
} EdgeNode;

typedef struct vnode    /*ͷ�������*/
{
    DataType vertex;         /*������Ϣ*/
    EdgeNode *FirstEdge; /*�ڽ�����ͷָ��*/
} VertexNode;
typedef struct            /*�ڽӱ�����*/
{
    VertexNode adjlist[M];  /*���ͷ����˳���*/
    int n,e;                 /*ͼ�Ķ����������*/
} LinkedGraph;

void creat(LinkedGraph *g,char *filename,int c)
{
    int i,j,k;
    EdgeNode *s;
    FILE *fp;
    fp=fopen(filename,"r");
    if (fp){
        fscanf(fp,"%d%d",&g->n,&g->e);              /*���붥���������*/
        for(i = 0; i < g->n; i++){
            fscanf(fp,"%1s",&g->adjlist[i].vertex);    /*���붥����Ϣ*/
            g->adjlist[i].FirstEdge = NULL;         /*�߱���Ϊ�ձ�*/
        }
        for(k = 0; k < g->e; k++){                   /*ѭ��e�ν����߱�*/
            fscanf(fp,"%d%d",&i,&j);                 /*��������ԣ�i,j��*/
            s = (EdgeNode *)malloc(sizeof(EdgeNode));
            s->adjvex = j;                         /*�ڽӵ����Ϊj*/
            s->next = g->adjlist[i].FirstEdge;
            g->adjlist[i].FirstEdge=s;           /*���½��*s���붥��vi�ı߱�ͷ��*/
            if (c == 0){                            /*����ͼ*/
                s = (EdgeNode *)malloc(sizeof(EdgeNode));
                s->adjvex = i;                         /*�ڽӵ����Ϊi*/
                s->next = g->adjlist[j].FirstEdge;
                g->adjlist[j].FirstEdge = s;           /*���½��*s���붥��vj�ı߱�ͷ��*/
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
          cout<<i<<"  �Ķ���  "<<sum<<endl;
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



