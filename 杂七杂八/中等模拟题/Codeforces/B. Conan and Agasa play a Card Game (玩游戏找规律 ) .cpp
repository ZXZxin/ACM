//��Ŀ���ӣ�http://codeforces.com/contest/914/problem/B
//��Ŀ����: ����Conan �� Agasa һ����һ��ֽ����Ϸ�� ÿ����ÿ���غϿ�������һ���ƣ����������Ƶ�ͬʱ
            //��������С����Ҳ�ᱻ�Զ����ߣ����ĸ��˵Ļغ�û�Ƶ�ʱ������˾����ˣ�����ÿ���˵���õ������˭��Ӯ
//����˼·: һ��ʼ��ıȽϼ򵥣�ֻ���������Ǹ������������֣�����ѡ������������Ȼ��ټ������ӷ��֣�ֻҪĳ�����ĸ�������������һ��ȡ���˶���Ӯ

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int maxn = 100000 + 10;
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	int a[maxn],b[maxn];
	memset(b, 0, sizeof(b));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	bool flag = true;
	int maxx = a[0];
	for (int i = 0; i < n; i++)if (a[i] > maxx)maxx = a[i];
	for (int i = 0; i < n; i++) b[a[i]]++;
	for (int i = 0; i <= maxx; i++)if (b[i] % 2 == 1) {
		flag = false; break;
	}
	if (!flag)printf("Conan\n");
	else printf("Agasa\n");
	return 0;
}