//�����������(һ)��O(n*n*n)
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

int main(){
    //freopen("in.txt","r",stdin);
    int n,a[maxn];
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; i++)scanf("%d",&a[i]);
        int maxx = a[0];
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum = 0;
                for(int k = i; k <= j; k++)sum += a[k];
                if(maxx < sum)maxx = sum;
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}

/*
��������:
3
2 4 -3
5
2 5 -1 2 -1
*/

//�����������(��) O(n*n): �Ż���������͵��㷨: ����������֮�� = ����ǰ׺��֮��
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

int main(){
    //freopen("in.txt","r",stdin);
    int n,a[maxn];
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; i++)scanf("%d",&a[i]);
        int s[maxn];
        s[0] = a[0];
        for(int i = 1; i < n; i++)s[i] = s[i-1] + a[i];
        int maxx = a[0];
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                maxx = max(maxx,s[j] - s[i-1]);
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}


//�����������(��) O(n*logn): ���η�: (1)��������(2)�ݹ����(3)�ϲ�����
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

int maxsum(int *A,int x,int y){ //����A����[x,y)֮������������
    int v,L,R,maxx;
    if(y - x == 1)return A[x]; //�ݹ�߽�
    int m = x + (y-x)/2;
    maxx = max(maxsum(A,x,m),maxsum(A,m,y));  //���εڶ���: �ݹ����
    v = 0;L = A[m-1];
    for(int i = m-1; i >= x; i--)L = max(L,v += A[i]); //���ε�����:�ϲ�(1)���ӷֽ����������������L
    v = 0;R = A[m];
    for(int i = m; i < y; i++)R = max(R,v += A[i]); //���ε�����:�ϲ�(2)���ӷֽ�����ҵ����������R
    return max(maxx,L+R);  //��������Ľ� �� L+R ���бȽ�
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,a[maxn];
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; i++)scanf("%d",&a[i]);
        printf("%d\n",maxsum(a,0,n));
    }
    return 0;
}

