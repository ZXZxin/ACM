//题目链接：https://vjudge.net/contest/169967#problem/F
//题目大意:就是按照一定的方式输入一个天平，问你 最少 要改变多少个砰砣才能让天平达到平衡
//解题思路：一开始没有想到 解决办法，看了题解
/*  要使得改动的数量最少，那么就至少有一个秤砣不变，然后以这个秤砣为基准来调整整个天平。天平的结构是二叉树，
    那么由此我们可以得出，如果以深度为d重量为w的秤砣为基准，那么整个天平的重量就是w * pow(2, d)，即w << d。
　　当然，可能会有一些秤砣算出的以各自为基准的天平总重量相同，设天平总重量为sumw，
    那么这些秤砣的数量就表示了如果使天平的总重量为sumw需要使多少个秤砣保持不变。
　　求出所有可能的sumw值以及其对应的秤砣数量，找到叶子对应的整个天平的数量的最大值，然后用总的叶子减去这个最大值就是答案*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>

const int maxn = 1<<16 + 5;
using namespace std;

typedef long long LL;
typedef struct node{
    LL data;
    struct node *left,*right;
    //node():data(0),left(NULL),right(NULL){}  //可以加一个构造函数
}BiNode,*BiTree;
char s[maxn];
map<LL,int>dict;
int sum;

BiTree Build(int b,int e){
    BiTree root = new BiNode();
    if(s[b] == '['){
        int p = 0;
        for(int i = b + 1; i <= e; i++){
            if(s[i] == '[')p++;
            if(s[i] == ']')p--;
            if(p == 0 && s[i] == ','){
                root->data = 0;
                root->left = Build(b+1,i-1);
                root->right = Build(i+1,e-1);
                return root;
            }
        }
    }
    else {
        LL w = 0;
        for(int i = b; i <= e; i++)w = w*10 + (s[i] - '0');
        root->data = w;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
}

void DFS(int ans,BiTree T){
    if(T->left == NULL && T->right == NULL){
        sum++;
        dict[T->data << ans]++;
    }
    else {
        DFS(ans + 1,T->left);
        DFS(ans + 1,T->right);
    }
}

void BFS(BiTree T){//层次遍历二叉树  检测一下是否建树正确
    BiTree p = T;
    queue<BiTree>q;
    q.push(p);
    while(!q.empty()){
        BiTree now = q.front();q.pop();
        printf("%ld ",now->data);
        if(now->left)q.push(now->left);
        if(now->right)q.push(now->right);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        dict.clear();
        scanf("%s",s);
        int len = strlen(s) - 1;
        sum = 0;
        BiTree root = new BiNode();
        root = Build(0,len);
        //BFS(root);printf("\n");
        DFS(0,root);
        int maxx = -1;
        map<LL,int>::iterator it;
        for(it = dict.begin(); it != dict.end(); it++){
            maxx = max(maxx,it->second);
        }
        printf("%d\n",sum - maxx);
    }
    return 0;
}



//也可以不建树
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>

const int maxn = 1<<16 + 5;
using namespace std;

typedef long long LL;
char s[maxn];
map<LL,int>dict;
int sum;

void DFS(int dep,int b,int e){
    if(s[b] == '['){
        int p = 0;
        for(int i = b + 1; i <= e; i++){
            if(s[i] == '[')p++;
            if(s[i] == ']')p--;
            if(p == 0 && s[i] == ','){
                DFS(dep+1,b+1,i-1);
                DFS(dep+1,i+1,e-1);
            }
        }
    }else {
        LL w = 0;
        for(int i = b; i <= e; i++)w = w*10 + (s[i] - '0');
        sum++,dict[w<<dep]++;
    }

}

int main(){
    //freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        dict.clear();
        scanf("%s",s);
        int len = strlen(s) - 1;
        sum = 0;
        DFS(0,0,len);
        int maxx = -1;
        map<LL,int>::iterator it;
        for(it = dict.begin(); it != dict.end(); it++){
            maxx = max(maxx,it->second);
        }
        printf("%d\n",sum - maxx);
    }
    return 0;
}
