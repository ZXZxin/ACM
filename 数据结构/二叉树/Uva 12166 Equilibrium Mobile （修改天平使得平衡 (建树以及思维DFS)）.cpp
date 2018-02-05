//��Ŀ���ӣ�https://vjudge.net/contest/169967#problem/F
//��Ŀ����:���ǰ���һ���ķ�ʽ����һ����ƽ������ ���� Ҫ�ı���ٸ����Ȳ�������ƽ�ﵽƽ��
//����˼·��һ��ʼû���뵽 ����취���������
/*  Ҫʹ�øĶ����������٣���ô��������һ�����Ȳ��䣬Ȼ�����������Ϊ��׼������������ƽ����ƽ�Ľṹ�Ƕ�������
    ��ô�ɴ����ǿ��Եó�����������Ϊd����Ϊw�ĳ���Ϊ��׼����ô������ƽ����������w * pow(2, d)����w << d��
������Ȼ�����ܻ���һЩ����������Ը���Ϊ��׼����ƽ��������ͬ������ƽ������Ϊsumw��
    ��ô��Щ���ȵ������ͱ�ʾ�����ʹ��ƽ��������Ϊsumw��Ҫʹ���ٸ����ȱ��ֲ��䡣
����������п��ܵ�sumwֵ�Լ����Ӧ�ĳ����������ҵ�Ҷ�Ӷ�Ӧ��������ƽ�����������ֵ��Ȼ�����ܵ�Ҷ�Ӽ�ȥ������ֵ���Ǵ�*/

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
    //node():data(0),left(NULL),right(NULL){}  //���Լ�һ�����캯��
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

void BFS(BiTree T){//��α���������  ���һ���Ƿ�����ȷ
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



//Ҳ���Բ�����
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
