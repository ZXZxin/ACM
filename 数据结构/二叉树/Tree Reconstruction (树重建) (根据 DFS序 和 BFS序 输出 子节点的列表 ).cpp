//题目链接：
//题目大意：就是要你根据一棵树的BFS序列和DFS序列来输出每个结点的子节点的列表，当一个结点被扩展是shi
//解题思路: 没有想出来，看了题解也不是很懂，大概就是说如果BFS(v) = BFS(v) + 1且DFS(v) = DFS(u) + 1的话就一定是后一个兄弟结点
            //先储存好BFS中的每两个点之间的距离，这里利用栈来表示递归思想，在DFS中计算两个点的距离来判断是孩子还是兄弟还是其他
//下面是两个学习博客
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
