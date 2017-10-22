//��Ŀ����:https://vjudge.net/contest/193113#problem/C
//��Ŀ���⣺������
//����˼·����������������Ʊ�Ȩ��������Ҫ�󾭹����ٶ��ٴεĸı�һЩ�㣬��ʹ������ܴﵽn-1
            //���ǰ�ǰ��û��Y����������Y�ĵ��Ȩֵ����Ϊ0����ǰ����k��Y��Ҫ��ֱ�ӱ䵽������Ҫ��ǰ���ɾ�����ĵ㣨i��j����Ȩֵ����Ϊk
            //������������·��������Ĵ�

#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>

#include<string>
#include<iostream>

const int maxn = 50+5;
const int INF = 1000000000;
using namespace std;

int d[maxn][maxn];
int n;

void floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    char ch;
    while(T--){
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            d[i][j]=INF;
        }
    }
        cin>>n;
        for(int i=0;i<n;i++){
            int k=0;
            for(int j=0;j<n;j++){
                cin>>ch;
                if(ch=='Y'){
                    d[i][j]=k++;
                }
            }
        }
    floyd();
    if(d[0][n-1]==INF)cout<<"-1"<<endl;
    else cout<<d[0][n-1]<<endl;
    }
    return 0;
}


