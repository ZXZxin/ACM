//��Ŀ���ӣ�http://poj.org/problem?id=1611
//��Ŀ���⣺������Ⱦ������ͨ��һЩ���ŽӴ�
          //����һЩ���ţ����ж����˱���Ⱦ
//����˼·�����鼯�ҳ��������ȣ����뼯��,Ȼ���ҳ���0��ͬһ�����ϵ�Ԫ�ظ�����˳����ranks��¼�����Ż�



#include <iostream>
#define maxn 30001
using namespace std;

int pa[maxn];
int ranks[maxn];

int Find(int v){
	if (pa[v] == v)return v;
	return pa[v] = Find(pa[v]);
}

void Union(int x, int y){
	int fx = Find(x);
	int fy = Find(y);
	if (fx == fy)return;
	if (ranks[fx] < ranks[fy])//fy�ĸ߶ȴ���fx
		pa[fx] = fy;  //���Ⱥϲ���ԭ����ʹ�����ĸ߶Ⱦ�����С
	else{
		pa[fy] = fx;
		if (ranks[fx] == ranks[fy])
			ranks[fy]++;
	}
}

int main(){
	int n, m, k, x, y;
	while (cin >> n >> m && (n || m)){
		int sum = 1;
		for (int i = 0; i < n; i++){//��ʼ��
			pa[i] = i;
			ranks[i] = 0;
		}
		for (int i = 0; i < m; i++){
			cin>>k;
			if (k >= 1)cin >> x;
			for (int j = 1; j < k; j++){
				cin >> y;
				Union(x, y);//�ϲ�����
			}
		}
		for (int i = 1; i < n; i++){
			if (Find(0) == Find(i))//��0��ͬһ�����ϵ�Ԫ��
				sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
