//��ǵݼ������е�n^2�㷨�Լ���ӡ


#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int dp[31]; /* dp[i]��¼��[0,i]�����LIS */
int lis = 1;    /* LIS���ȣ���ʼ��Ϊ1 */

int LIS(int *arr, int arrsize)
{
	for (int i = 0; i < arrsize; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j) /// ע��iֻ��������С��Ԫ��
			if (arr[j] <= arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		lis = max(lis, dp[i]);
	}
	return lis;
}

/* �ݹ����LIS����Ϊ����dp���䵱�ˡ���ǡ����� */
void outputLIS(int *arr, int index)
{
	bool isLIS = false;
	if (index < 0 || lis == 0)
		return;
	if (dp[index] == lis)
	{
		--lis;
		isLIS = true;
	}
	outputLIS(arr, --index);
	if (isLIS)
		printf("%d ", arr[index + 1]);
}

int main(void)
{
	int arr[] = {1, 5, 8, 3, 4, 6, 7};
	printf("%d\n", LIS(arr, sizeof(arr) / sizeof(*arr)));//sizeof(arr)/sizeof(*arr)��ʾarr�����ʵ�ʳ���
	outputLIS(arr, sizeof(arr) / sizeof(*arr) - 1);
	return 0;
}
