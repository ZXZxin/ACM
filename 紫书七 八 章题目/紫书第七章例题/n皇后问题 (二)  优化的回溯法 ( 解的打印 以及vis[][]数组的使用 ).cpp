// n�ʺ����⣺�Ż��Ļ��ݷ�
#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 100 + 10;
using namespace std;

int sum,n,cnt;
int C[maxn];
bool vis[3][maxn];
int map[8][8];//��ӡ�������


//vis����ĺ���: ��ʾ�Ѿ����õĻʺ�ռ������Щ�С����Խ��ߺ͸��Խ���
//һ���ڻ��ݷ����޸��˸�����ȫ�ֱ�����һ��Ҫ��ʱ�����ǻָ�ԭ״
void Search(int cur){  //���з��ûʺ�
    cnt++;
    if(cur == n){
        sum++;
        for(int i = 0; i < cur; i++)map[i][C[i]] = 1;//��ӡ��
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d ",map[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        memset(map,0,sizeof(map));
    }
    else for(int i = 0; i < n; i++){ //������ cur�е� �� �� ���ûʺ�
        if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]){//�жϵ�ǰ���ԵĻʺ���С����Խ���
            vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = true;
            C[cur] = i;//cur �е����� i
            Search(cur+1);
            vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = false;//�мǣ�һ��Ҫ�Ļ���
        }
    }
}

int main(){
    while(scanf("%d",&n)){
        memset(vis,false,sizeof(vis));
        memset(map,0,sizeof(map));
        sum = cnt = 0;
        Search(0);
        printf("%d %d\n",sum,cnt);//��� ������� �� �ݹ����
    }
    return 0;
}
