//最长非递减子序列的n^2算法以及打印


#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int dp[31]; /* dp[i]记录到[0,i]数组的LIS */
int lis = 1;    /* LIS长度，初始化为1 */

int LIS(int *arr, int arrsize)
{
	for (int i = 0; i < arrsize; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j) /// 注意i只遍历比它小的元素
			if (arr[j] <= arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		lis = max(lis, dp[i]);
	}
	return lis;
}

/* 递归输出LIS，因为数组dp还充当了“标记”作用 */
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
	printf("%d\n", LIS(arr, sizeof(arr) / sizeof(*arr)));//sizeof(arr)/sizeof(*arr)表示arr数组的实际长度
	outputLIS(arr, sizeof(arr) / sizeof(*arr) - 1);
	return 0;
}
