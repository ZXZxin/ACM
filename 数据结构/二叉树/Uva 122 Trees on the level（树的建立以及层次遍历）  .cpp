//题目链接：https://vjudge.net/contest/169966#problem/G
//题目大意：按照从根结点到结点的顺序输入，层次输出树
//解题思路：简单BFS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stdlib.h>
using namespace std;
const int maxn = 100+10;

typedef struct Node{
    bool have_value;
    int data;
    struct Node *left,*right;
}BiNode,*BiTree;

BiTree root;
bool failed;
char s[maxn];

void removes(BiTree T){
    if(!T)return;
    removes(T->left);
    removes(T->right);
    free(T);
}

BiTree newnode(){
    BiTree T = NULL;
    T = (BiTree)malloc(sizeof(BiNode));
    if(T){
        T->have_value = false;
        T->left = T->right = NULL;
    }
    return T;
}

void addnode(int v,char *s){
    BiTree u = root;
    int len = strlen(s);
    for(int i = 0 ;i < len; i++){
        if(s[i] == 'L'){
            if(!u->left)u->left = newnode();
            u = u->left;
        }
        else if(s[i] == 'R'){
            if(!u->right)u->right = newnode();
            u = u->right;
        }
    }
    if(u->have_value == true)failed = false;
    u->data = v;
    u->have_value = true;
}

bool read(){
    failed = true;
    removes(root);
    root = newnode();
    int v;
    while(1){
        if(scanf("%s",s) != 1)return false;
        if(!strcmp(s,"()"))break;
        sscanf(&s[1],"%d",&v);
        addnode(v,strchr(s,',')+1);
    }
    return true;

}

bool BFS(vector<int>&ans){
    queue<BiTree>q;
    q.push(root);
    while(!q.empty()){
        BiTree now = q.front();
        q.pop();
        if(!now->have_value)return false;   //结点没有赋值过，表明输入有误
        ans.push_back(now->data);
        if(now->left)q.push(now->left);
        if(now->right)q.push(now->right);
    }
    return true;
}

int main(){
    vector<int>ans;
    while(read()){
        ans.clear();
        if(!BFS(ans)||!failed)cout<<"not complete"<<endl;
        else {
            for(int i = 0; i < ans.size() - 1; i++)cout<<ans[i]<<" ";
            cout<<ans[ans.size() - 1]<<endl;
        }
    }
    return 0;
}




//刘汝佳代码
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 256 + 10;

struct Node{
    bool have_value;
    int v;
    Node* left, *right;
    Node():have_value(false),left(NULL),right(NULL){}
};

Node* root;
Node* newnode() { return new Node();}

bool failed;
void addnode(int v, char* s) {
    int n = strlen(s);
    Node* u = root;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L') {
            if(u->left == NULL) u->left = newnode();
            u = u->left;
        }
        else if(s[i] == 'R') {
            if(u->right == NULL) u->right = newnode();
            u = u->right;
        }
    }
    if(u->have_value) failed = true;
    u->v = v;
    u->have_value = true;
}

void remove_tree(Node* u) {
    if(u == NULL) return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

char s[maxn];
bool read_input() {
    failed = false;
    remove_tree(root);
    root = newnode();
    for(;;) {
        if(scanf("%s", s) != 1) return false;
        if(!strcmp(s, "()")) break;
        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v, strchr(s, ',')+1);
    }
    return true;
}

bool bfs(vector<int>& ans) {
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()) {
        Node* u = q.front(); q.pop();
        if(!u->have_value) return false;
        ans.push_back(u->v);
        if(u->left != NULL) q.push(u->left);
        if(u->right != NULL) q.push(u->right);
    }
    return true;
}

int main() {
    vector<int> ans;
    while(read_input()){
        if(!bfs(ans)) failed = 1;
        if(failed) printf("not complete\n");
        else {
        for(int i = 0; i < ans.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
        }
    }
    return 0;
}
