//��Ŀ���ӣ�http://poj.org/problem?id=1041
//��Ŀ���⣺����ÿ�� ������x,y,z���� x,y·��ͨ�� z �ֵ� ���� Ҫ���������С�ĵط���ʼ��һ��ŷ����· �����
//����˼·��DFS��ʱ��Ҫ ����ÿ���ֵ�������map[x][z] = y һ��ʼҲ��û���뵽

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>

const int maxn = 2000 + 5;
using namespace std;

int vis[maxn];
int map[50][maxn];
int in[maxn];
int maxx,minn,street_cnt;
stack<int>s;

void DFS(int u){
    for(int i = 1; i <= street_cnt; i++){ //����ÿ����
        if(map[u][i] && !vis[i]){
            vis[i] = 1;
            DFS(map[u][i]); //DFS u ͨ�� i �ܵ����Ǹ��� �� map[u][i]
            s.push(i);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int x,y,z;
    while(scanf("%d %d",&x,&y) != EOF && (x || y)){
        scanf("%d",&z);
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        memset(in,0,sizeof(in));
        while(!s.empty())s.pop();
        minn = x,maxx = x; //��¼·�ڵ���С��ź������
        if(y < x)minn = y;
        if(y > x)maxx = y;
        map[x][z] = y,map[y][z] = x;//���� x ͨ�� z �ܵ��� y
        in[x]++,in[y]++;
        street_cnt = 1;  //��¼�ֵ�������
        while(true){
            scanf("%d%d",&x,&y);
            if(x == 0 && y == 0)break;
            scanf("%d",&z);
            if(x < minn)minn = x;
            if(y < minn)minn = y;
            if(x > maxx)maxx = x;
            if(y > maxx)maxx = y;
            map[x][z] = y,map[y][z] = x;
            in[x]++,in[y]++;
            street_cnt++;
        }
        bool flag = true;
        DFS(minn);
        for(int i = 1; i <= maxx; i++)if(in[i]%2 != 0){  //ŷ����·������֮һ
           flag = false;break;
        }
        for(int i = 1; i <= street_cnt; i++)if(!vis[i]){  //�ж��ǲ�����ͨ��
            flag = false;break;
        }
        if(!flag)printf("Round trip does not exist.\n");
        else {
            while(s.size() != 1){
                printf("%d ",s.top());
                s.pop();
            }
            printf("%d\n",s.top());
        }
    }
    return 0;
}
