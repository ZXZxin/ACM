//ѡ���ཻ��������(̰�ķ�)
//��Ŀ���� : http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=966
//��Ŀ���� : ���Ǹ�һϵ�е����䣬Ҫ�����������࣬����Щ���䲻�ཻ����Ҫע�������Щ���䶼�Ǳ����䡣
//����˼· : ̰�Ĳ���һ��ѡ���һ����Ȼ����������ÿ�θ���ǰ���node[i].y(���忴����ѵ���ڰ���)

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 10;

struct Node{
    int x,y;
    bool operator < (const Node & rhs) const{
        return y < rhs.y || (y == rhs.y && x < rhs.x);
    }
}node[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int n,kase = 0;
    int path[maxn]; //��¼����
    while(scanf("%d",&n) != EOF){
        int temp; //��������� "��"
        for(int i = 0; i < n; i++){
            scanf("%d%d",&node[i].x,&node[i].y);
            if(node[i].x > node[i].y){  //��
                temp = node[i].x;
                node[i].x = node[i].y;
                node[i].y = temp;
            }
        }
        sort(node,node+n);
        int End = node[0].y;  //��ѡ���һ��
        int sum = 1; //��¼����,��һ������ѡ
        for(int i = 1; i < n; i++){
            if(node[i].x > End){
                path[sum++] = i;
                End = node[i].y;
            }
        }
        //printf("%d %d\n",node[0].x,node[0].y);
        //for(int i = 1; i < sum; i++)printf("%d %d\n",node[path[i]].x,node[path[i]].y); //�������
        printf("Case %d:\n",++kase);
        printf("%d.\n",sum);
    }
    return 0;
}
