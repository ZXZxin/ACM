//��Ŀ����: https://vjudge.net/contest/171111#problem/D
//��Ŀ����: ����������n,�� 1,2,3...n���һ����,ʹ������������֮�;�Ϊ����,���ʱ���մ�����1��ʼ��ʱ������
//����˼·: �Ƚ����׵�˼·����ֱ��ʹ��next_permutation������Щ���в��ж��Ƿ�����(�����������(�ᳬʱ))
    //  ��ȷ�ķ�����ʹ�û��ݷ�����A[0] = 1,Ȼ��ÿ�γ���ȡһ������Ȼ����ݣ����ܶ�

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 16 + 5;

bool isp[maxn],vis[maxn];
int A[maxn];
int n;

bool is_Prime(int x){
    for(int i = 2; i*i <= x; i++)if(x % i == 0)return false;
    return true;
}

//˼������ж�һ��������Ȼ����ú������
//���ݷ�: �����ǰ����(��)û�кϷ�ѡ��,�򷵻���һ������
void DFS(int cur){
    if(cur == n && isp[A[0] + A[n-1]]){//�ݹ�߽磬�����˲��Ե�һ���������һ����
        for(int i = 0; i < n; i++){
            if(i != 0)printf(" ");
            printf("%d",A[i]);
        }
        printf("\n");
    }
    else for(int i = 2; i <= n; i++){ //���Է���ÿһ����
        if(!vis[i] && isp[A[cur - 1] + i]){
            A[cur] = i;
            vis[i] = true;  //����ʹ�ñ��
            DFS(cur+1);
            vis[i] = false;  //������
        }
    }
}

int main(){
    int kase = 0;
    while(scanf("%d",&n) != EOF){
        memset(vis,false,sizeof(vis));
        for(int i = 2; i <= 2*n; i++)isp[i] = is_Prime(i);
        if(kase > 0)printf("\n");  //���ǲҾ���徵����
        printf("Case %d:\n",++kase);
        A[0] = 1;//��Ҫ����A[0]��Ҫ���ĸ���ֱ��1�Ϳ���
        DFS(1);
    }
    return 0;
}

//��ʱ�����ɲ��Է�
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 100 + 10;

bool isp[maxn];
int A[maxn];

bool is_Prime(int x){
    for(int i = 2; i*i <= x; i++)if(x % i == 0)return false;
    return true;
}

int main(){
    int n,kase = 0;
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; i++)A[i] = i + 1;
        for(int i = 2; i <= 2*n; i++)isp[i] = is_Prime(i);
        if(kase > 0)printf("\n");  //���ǲҾ���徵����
        printf("Case %d:\n",++kase);
        do{
            bool flag = true;
            for(int i = 0; i < n; i++)if( !isp[A[i] + A[(i+1)%n]] ){flag = false;break;}
            if(flag){
                for(int i = 0; i < n; i++){
                    if(i != 0)printf(" ");
                    printf("%d",A[i]);
                }
                printf("\n");
            }
        }while(next_permutation(A+1,A+n));//1�������� ÿ�������1��ֻ�Ǻ��������
    }
    return 0;
}

