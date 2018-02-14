//��Ŀ����:https://vjudge.net/contest/171111#problem/I
//��Ŀ����: ���Ǹ���һ���Թ�,�������a,b,c��Ҫ���ҵ���Ӧ��A,B,C��Ҫ�Ĳ���(ע����������ռͬһ��λ��,Ҳ������һ��֮�ڽ���λ��)
/*����˼·:�������ڵ㣬ʹ��������BFS���ö�����ӳ��״̬��������Ӻͳ��ӡ�ʹ���������任����
          ���⣬������û�н����Ż�ֱ����ԭͼBFS����ô�϶��ǻᳬʱ�ģ����������һ���Ż�������
          ���Խ�ԭͼ��ú����ĸ�Ϳո񵥶��޳�������Ϊ��#�����ǲ����ʵ� ���ǰѷ�'#'�ĵط���һ��ͼ*/
//���������: ��������һֱû�н��
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;
const int maxn = 16 * 16;

struct Node{
    int a,b,c;
    Node(){};
    Node(int a,int b,int c):a(a),b(b),c(c){}
};

char maze[16][16],id[16][16];  //һ��ʼ���Թ� �� �Լ������Թ�
int deg[maxn - 60]; //��ʵû�б�Ҫmaxn�󲿷���#(�ϰ�)
int G[maxn][5]; //5������
int s[3],t[3]; //start,end;
int x[maxn],y[maxn]; //��¼ ����ͼ�� ÿ����� x , y����
int d[maxn][maxn][maxn];
int dir[5][2] = {{-1,0},{0,1},{1,0},{0,-1},{0,0}};

int ID(int a,int b,int c){
    return (a << 16) | (b << 8) | c;
}

bool is_conflict(int a,int b,int a2,int b2){
    return a2 == b2 || (a == b2 && b == a2);
}

void BFS(){
    //queue<int>q;
    queue<Node>q;
    Node u,u2;
    u.a = s[0]; u.b = s[1]; u.c = s[2];
    q.push(u);
    //q.push(ID(s[0],s[1],s[2]));
    memset(d,-1,sizeof(d));
    d[s[0]][s[1]][s[2]] = 0;
    while(!q.empty()){
        /*int */u = q.front();q.pop();
        //int a = (u>>16)&0xff, b = (u>>8)&0xff, c = u&0xff;
        int a = u.a, b = u.b, c = u.c;
        if(a == t[0] && b == t[1] && c == t[2]){printf("%d\n",d[a][b][c]);return;}
        for(int i = 0; i < deg[a]; i++){
            int a2 = G[a][i];
            for(int j = 0; j < deg[b]; j++){
                int b2 = G[b][j];
                if(is_conflict(a,b,a2,b2))continue;
                for(int k = 0; k < deg[c]; k++){
                    int c2 = G[c][k];
                    if(is_conflict(a,c,a2,c2))continue;
                    if(is_conflict(b,c,b2,c2))continue;
                    if(d[a2][b2][c2] != -1)continue;
                    d[a2][b2][c2] = d[a][b][c] + 1;
                    //q.push(ID(a2,b2,c2));
                    q.push(Node(a2,b2,c2));
                }
            }
        }
    }
    printf("-1\n");
}

int main(){
    int w,h,n;
    while(scanf("%d%d%d\n",&w,&h,&n) && n){ //ע��"\n" �ȼ��� getchar()������
        for(int i = 0; i < h; i++)fgets(maze[i],20,stdin);//��ȡ��󳤶�Ϊ20���ַ���

        int cnt = 0; //cntΪͼ�Ľ����
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)if(maze[i][j] != '#'){
                x[cnt] = i; y[cnt] = j; id[i][j] = cnt;
                if(islower(maze[i][j]))  s[maze[i][j] - 'a'] = cnt; //��¼��ʼλ��
                else if(isupper(maze[i][j]))  t[maze[i][j] - 'A'] = cnt;
                cnt++;
        }
        memset(deg,0,sizeof(deg));
        for(int i = 0; i < cnt; i++)
            for(int j = 0; j < 5; j++){
                int xx = x[i] + dir[j][0];
                int yy = y[i] + dir[j][1];
                if(maze[xx][yy] != '#')G[i][deg[i]++] = id[xx][yy];
        }
        if(n <= 2) { deg[cnt] = 1; G[cnt][0] = cnt; s[2] = t[2] = cnt++; } //����������
        if(n <= 1) { deg[cnt] = 1; G[cnt][0] = cnt; s[1] = t[1] = cnt++; }
        BFS();
    }
    return 0;
}
