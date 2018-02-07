//题目链接:https://vjudge.net/contest/171111#problem/F
//题目大意:就是给你一个图,给出它们的相邻关系,每个结点有一个带宽b[i],一个结点的带宽是这个结点与相邻结点的最远的距离
          //整个图的带宽是结点中的最大带宽,要你求出最小带宽的排列
//解题思路: 这里主要还是枚举这些排列,然后一个个算出各个带宽取得最小值,以及剪枝的优化
    //注意这里的编号,以及vector的对应关系,mecypy的使用,这些都是很有用的知识

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 10;
const int INF = 100000000;

char s[maxn],letter[maxn];//输入以及各个位置上对应的字母
int id[91],P[maxn],pos[maxn],bestP[maxn];

int main(){
    while(scanf("%s",s) && s[0] != '#'){
        int len = strlen(s),n = 0;
        for(char ch = 'A'; ch <= 'Z'; ch++){
            if(strchr(s,ch) != NULL){
                letter[n] = ch;
                id[ch] = n++;//因为字符本身也可以表示成数字 为每一个在这个串中出现的字母编号
            }
        }
        //printf("%d",'Z');输出最大字母'Z'代表的ASSIC值  所以id数组只要91就可以
        vector<int>u,v;
        for(int i = 0; i < len; i++){
            int start = i;//记录每一个开始的字母
            i += 2;
            while(i < len && s[i] != ';'){
                u.push_back(id[s[start]]);//每个起点不只push了一次,这是为了下面对应关系,很妙
                v.push_back(id[s[i]]);
                i++;
            }
        }
        /*注意u中的内容,每一个起点不只是push了一次
        for(int i = 0; i < u.size(); i++)printf("%c ",letter[u[i]]);printf("\n");
        for(int i = 0; i < v.size(); i++)printf("%c ",letter[v[i]]);printf("\n");
        */
        for(int i = 0; i < n; i++)P[i] = i;
        int ans = INF;
        do{
            int bandWith = 0;
            for(int i = 0; i < n; i++)pos[P[i]] = i;//每个"字母"的位置
            for(int i = 0; i < u.size(); i++){
                bandWith = max(bandWith,abs(pos[u[i]] - pos[v[i]]));
                if(bandWith > ans)break;
            }
            if(bandWith < ans){
                ans = bandWith;
                memcpy(bestP,P,sizeof(P));//数组复制函数
            }
        }while(next_permutation(P,P+n));
        for(int i = 0; i < n; i++)printf("%c ",letter[bestP[i]]);
        printf("-> %d\n",ans);
    }
    return 0;
}
