//��Ŀ����: http://poj.org/problem?id=1804
//��Ŀ����: ���Ǹ���һ����,Ҫ�����������Եĸ���
//����˼·: ֱ���� ����ѵڰ��µ� �鲢����Ĵ���
           //ע�� ���������� i < j && f[i] > f[j] ������� (1)���ֳɾ�����ȵ�����,(2)�ݹ����:ͳ��i��j������߻��߾����ұߵ��������Ը���
           //"�ϲ�����": ͳ��i �� ���,j���ұߵ�����Ը���
           //ע��ϲ�ʱ: ���Ǹ������ұߵ� ֮�� ,��� [p,m)֮���������ұߵĴ� ��û�н���T�����f(i)>f(j)
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 1000 + 10;
int cnt; //ͳ��������

void Merge(int *A,int x,int y,int *T){ //TΪ��ʱ�ռ�
    if(y - x > 1){
        int m = x + (y-x)/2;  //����
        int p = x, q = m, i = x;
        Merge(A,x,m,T); //�ݹ����
        Merge(A,m,y,T);
        while(p < m || q < y){
            if( q >= y || (p < m && A[p] <= A[q]))T[i++] = A[p++];
            else {
                T[i++] = A[q++];
                cnt += m - p; //����������, ���Ǹ������ұߵ� ֮�� ,��� [p,m)֮���������ұߵĴ�(f(i))
            }
        }
        for(i = x; i < y; i++)A[i] = T[i]; //ע����������
    }
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n,kase = 0,T,a[maxn],b[maxn]; //b�����������������Ľ��
	scanf("%d",&T);
	while(T--){
        scanf("%d", &n);
        cnt = 0;
        for (int i = 0; i < n; i++)scanf("%d", &a[i]);
        Merge(a,0,n,b);
        //for (int i = 0; i < n; i++)printf("%d ",a[i]);
        //printf("\n");
        //printf("�������Եĸ����� : %d\n",cnt);
        printf("Scenario #%d:\n%d\n\n",++kase,cnt);
	}
	return 0;
}
