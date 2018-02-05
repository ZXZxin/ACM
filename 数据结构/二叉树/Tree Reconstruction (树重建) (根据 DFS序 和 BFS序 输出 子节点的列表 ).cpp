//��Ŀ���ӣ�
//��Ŀ���⣺����Ҫ�����һ������BFS���к�DFS���������ÿ�������ӽڵ���б���һ����㱻��չ��shi
//����˼·: û����������������Ҳ���Ǻܶ�����ž���˵���BFS(v) = BFS(v) + 1��DFS(v) = DFS(u) + 1�Ļ���һ���Ǻ�һ���ֵܽ��
            //�ȴ����BFS�е�ÿ������֮��ľ��룬��������ջ����ʾ�ݹ�˼�룬��DFS�м���������ľ������ж��Ǻ��ӻ����ֵܻ�������
//����������ѧϰ����
//https://www.cnblogs.com/jerryRey/p/4622927.html
//https://www.cnblogs.com/Wade-/p/6358859.html
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>

const int maxn = 1000 + 10;
using namespace std;

vector<int>G[maxn];
int pos[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int n,root,v;
    while(scanf("%d",&n) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d",&v);
            G[i].clear();
            pos[v] = i;
        }
        scanf("%d",&root);
        stack<int>s;
        s.push(root);
        for(int i = 2; i <= n; i++){
            scanf("%d",&v);
            while(true){
                int u = s.top();
                if( u == root || (pos[v] == pos[u] + 1 && u > v) || pos[v] > pos[u] + 1){
                    G[u].push_back(v);
                    s.push(v);
                    break;
                }else {
                    s.pop();
                }
            }
        }
        for(int i = 1; i <= n; i++){
            printf("%d:",i);
            for(int j = 0; j < G[i].size(); j++){
                printf(" %d",G[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
