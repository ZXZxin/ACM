#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#define maxn 20

using namespace std;
typedef char DataType;  /*������Ϣ��������*/
typedef struct node     /*�߱���*/
{
    int adjvex;                  /*�ڽӵ�*/
    struct node *next;
} EdgeNode;
int visited[maxn];	/*Ԥ����ͼ����󶥵���*/

typedef struct vnode    /*ͷ�������*/
{
    DataType vertex;         /*������Ϣ*/
    EdgeNode *FirstEdge; /*�ڽ�����ͷָ��*/
} VertexNode;

typedef struct            /*�ڽӱ�����*/
{
    VertexNode adjlist[maxn];  /*���ͷ����˳���*/
    int n,e;                 /*ͼ�Ķ����������*/
} LinkedGraph;

/*�������ܣ�����ͼ���ڽӱ�
  �����������ڽӱ�ָ�����g�����ͼ��Ϣ���ļ���filename;ͼ�����Ͳ���c��c=0��ʾ��������ͼ�������ʾ��������ͼ
  ��������ֵ����
*/
void creat(LinkedGraph *g,char *filename,int c)
{
    int i,j,k;
    EdgeNode *s;
    FILE *fp;
    fp=fopen(filename,"r");
    if (fp)
    {
        fscanf(fp,"%d%d",&g->n,&g->e);              /*���붥���������*/
        for(i = 1; i <= g->n; i++)
        {
            fscanf(fp,"%1s",&g->adjlist[i].vertex);    /*���붥����Ϣ*/
            g->adjlist[i].FirstEdge=NULL;         /*�߱���Ϊ�ձ�*/
        }
        for(k = 1; k <= g->e; k++)                   /*ѭ��e�ν����߱�*/
        {
            fscanf(fp,"%d%d",&i,&j); /*��������ԣ�i,j��*/
            s=(EdgeNode *)malloc(sizeof(EdgeNode));
            s->adjvex=j;                         /*�ڽӵ����Ϊj*/
            s->next=g->adjlist[i].FirstEdge;
            g->adjlist[i].FirstEdge=s;           /*���½��*s���붥��vi�ı߱�ͷ��*/
            if (c == 0)                            /*����ͼ*/
            {
                s=(EdgeNode *)malloc(sizeof(EdgeNode));
                s->adjvex=i;                         /*�ڽӵ����Ϊi*/
                s->next=g->adjlist[j].FirstEdge;
                g->adjlist[j].FirstEdge=s;           /*���½��*s���붥��vj�ı߱�ͷ��*/
            }
        }
        fclose(fp);
    }
    else
        g->n=0;
}

/*�뽫���������������������в���*/

void dfs(LinkedGraph g,int i)
{
    EdgeNode *p;
    printf("visit vertex: %c \n",g.adjlist[i].vertex);/*���ʶ���i*/
    visited[i] = 1;
    p = g.adjlist[i].FirstEdge;
    while (p)                /*��p���ڽӵ�������������������*/
    {
        if(!visited[p->adjvex])dfs(g,p->adjvex);
        p = p->next;
    }
}
/*�������ܣ�������ȱ���ͼ
  ����������ͼ���ڽӱ�g
*/
void DfsTraverse(LinkedGraph g)
{
    int i;
    for (i = 1; i <= g.n; i++)
        visited[i] = 0;     /*��ʼ����־����*/
    for (i = 1; i <= g.n; i++)
        if (!visited[i])  /*viδ���ʹ�*/
            dfs(g,i);
}

void bfs(LinkedGraph g, int i)
{
    queue<int>q;
    EdgeNode *p;
    /*�Ӷ���i����������ȱ���ͼg����ͨ����*/
    printf("visit vertex: %d ",i);/*���ʶ���i*/
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

/*�������ܣ�������ȱ���ͼg
  �����������ڽӱ�g
*/
int BfsTraverse(LinkedGraph g)
{
    int i,count = 0;
    for (i = 1; i <= g.n; i++)
        visited[i]=0;     /*��ʼ����־����*/
    for (i = 1; i <= g.n; i++)
        if (!visited[i])  /*viδ���ʹ�*/
        {
            printf("\n");
            count++;            /*��ͨ����������1*/
            bfs(g,i);
        }
    return count;
}
/*---����print():����ڽӱ�洢�ṹ---*/
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
    creat(&g,"in.txt",0);  	/*��֪g11.txt�д洢��ͼ����Ϣ*/
    printf("The graph is:\n");
    print(g);
    printf("\n");
    cout<<"DFS����Ϊ:"<<endl;
    DfsTraverse(g);
    printf("\n");
    cout<<"BFS����Ϊ:";
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

