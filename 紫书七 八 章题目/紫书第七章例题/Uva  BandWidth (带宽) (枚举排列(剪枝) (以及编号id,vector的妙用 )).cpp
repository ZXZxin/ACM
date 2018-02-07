//��Ŀ����:https://vjudge.net/contest/171111#problem/F
//��Ŀ����:���Ǹ���һ��ͼ,�������ǵ����ڹ�ϵ,ÿ�������һ������b[i],һ�����Ĵ����������������ڽ�����Զ�ľ���
          //����ͼ�Ĵ����ǽ���е�������,Ҫ�������С���������
//����˼·: ������Ҫ����ö����Щ����,Ȼ��һ���������������ȡ����Сֵ,�Լ���֦���Ż�
    //ע������ı��,�Լ�vector�Ķ�Ӧ��ϵ,mecypy��ʹ��,��Щ���Ǻ����õ�֪ʶ

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 10;
const int INF = 100000000;

char s[maxn],letter[maxn];//�����Լ�����λ���϶�Ӧ����ĸ
int id[91],P[maxn],pos[maxn],bestP[maxn];

int main(){
    while(scanf("%s",s) && s[0] != '#'){
        int len = strlen(s),n = 0;
        for(char ch = 'A'; ch <= 'Z'; ch++){
            if(strchr(s,ch) != NULL){
                letter[n] = ch;
                id[ch] = n++;//��Ϊ�ַ�����Ҳ���Ա�ʾ������ Ϊÿһ����������г��ֵ���ĸ���
            }
        }
        //printf("%d",'Z');��������ĸ'Z'�����ASSICֵ  ����id����ֻҪ91�Ϳ���
        vector<int>u,v;
        for(int i = 0; i < len; i++){
            int start = i;//��¼ÿһ����ʼ����ĸ
            i += 2;
            while(i < len && s[i] != ';'){
                u.push_back(id[s[start]]);//ÿ����㲻ֻpush��һ��,����Ϊ�������Ӧ��ϵ,����
                v.push_back(id[s[i]]);
                i++;
            }
        }
        /*ע��u�е�����,ÿһ����㲻ֻ��push��һ��
        for(int i = 0; i < u.size(); i++)printf("%c ",letter[u[i]]);printf("\n");
        for(int i = 0; i < v.size(); i++)printf("%c ",letter[v[i]]);printf("\n");
        */
        for(int i = 0; i < n; i++)P[i] = i;
        int ans = INF;
        do{
            int bandWith = 0;
            for(int i = 0; i < n; i++)pos[P[i]] = i;//ÿ��"��ĸ"��λ��
            for(int i = 0; i < u.size(); i++){
                bandWith = max(bandWith,abs(pos[u[i]] - pos[v[i]]));
                if(bandWith > ans)break;
            }
            if(bandWith < ans){
                ans = bandWith;
                memcpy(bestP,P,sizeof(P));//���鸴�ƺ���
            }
        }while(next_permutation(P,P+n));
        for(int i = 0; i < n; i++)printf("%c ",letter[bestP[i]]);
        printf("-> %d\n",ans);
    }
    return 0;
}
