//排序算法程序实现
//(1)直接插入(2)希尔排序(3)冒泡排序(4)快速排序

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 100 + 10;

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

void InsertSort(int data[], int n) {//插入排序
	/*for (int i = 2; i <= n; i++) {
		data[0] = data[i];
		int j;
		for (j = i - 1; j >= 1; j--) {
			if (data[0] >= data[j])break;
			else data[j + 1] = data[j];
		}
		data[j + 1] = data[0];
	}*/
	for (int i = 2; i <= n; i++) {
		for (int j = i; data[j] < data[j - 1]; j--) {
			swap(data[j], data[j - 1]);
		}
	}
}

//希尔排序的学习博客：http://blog.csdn.net/morewindows/article/details/6668714
void ShellSort(int data[], int n) {//希尔排序
	/*for (int gap = n / 2; gap >= 1; gap /= 2) {//最直观的写法
		for (int i = 1; i <= gap; i++) {
			for (int j = i + gap; j <= n; j += gap) {
				for (int k = j; data[k] < data[k - gap]; k -= gap)swap(data[k], data[k - gap]);//与前面的相比找到自己的位置
			}
		}
	}*/
	for (int gap = n / 2; gap >= 1; gap /= 2) {
		for (int i = gap; i <= n; i++) {
			int temp = data[i];
			int j;
			for (j = i - gap; j >= 1; j -= gap) {
				if (temp >= data[j])break;
				data[j + gap] = data[j];
			}
			data[j + gap] = temp;
		}
	}
	/*for (int gap = n / 2; gap >= 1; gap /= 2) {
		for (int i = gap; i <= n; i++) {//直接从gap 个开始
			for (int j = i; data[j] < data[j - 1]; j -= gap)swap(data[j], data[j - 1]);
		}
	}*/
}

void BubbleSort(int data[], int n) {//冒泡排序法
	for (int i = n - 1; i > 0; i--) {
		int temp;
		bool flag = false;
		for (int j = 0; j <= i - 1; j++) {
			if (data[j] > data[j + 1]) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
				flag = true;
			}
		}
		if (!flag)break;
	}
}

void QuickSort(int data[], int left, int right) {//快速排序
	int i = left, j = right;
	data[0] = data[i];
	while (i < j) {
		while (i < j && data[0] < data[j])j--;   //从后往前找到第一个小于key的
		if (i < j)data[i++] = data[j];   //把找到的这个赋给  左边的值  ：注意此时data[j] 无值0
		while (i < j && data[0] > data[i])i++;   //从前往后找到第一个大于key的  
		if (i < j)data[j--] = data[i];   //把找到的这个赋给刚刚的data[j]，，实现
	}
	data[i] = data[0];  //把关键字放到中间//也就是关键字 data[0]左边的均比data[0]小,右边的均比data[0]小
	if (left < right) {
		QuickSort(data, left, i - 1);
		QuickSort(data, i + 1, right);
	}
}

void ChoiceSort(int data[],int n) {//简单的选择排序
	for (int i = 1; i < n; i++) {//n - 1次排序
		int k = i;
		for (int j = i + 1; j <= n; j++) {
			if (data[j] < data[k])k = j;//找出最小的数
		}
		int temp;
		if (k != i) {//和前面有序序列中的最后一个进行交换
			temp = data[k];
			data[k] = data[i];
			data[i] = temp;
		}
	}
}

void Merge(int data[], int l,int m,int r) {//归并排序的一次归并操作
	int *pd;
	pd = (int *)malloc((r - l + 1)*sizeof(int));//多空出一个空间，防止越界
	int i = l, j = m + 1,k = 0;
	while (i <= m && j <= r)pd[k++] = data[i] < data[j] ? data[i++] : data[j++];//归并，有点类似线性表的两个有序表合并为一个有序表
	while (i <= m)pd[k++] = data[i++];//把左边剩余的放入
	while (j <= r)pd[k++] = data[j++];//把右边剩余的放入
	for (k = 0, i = l; i <= r; i++, k++)data[i] = pd[k];
	free(pd);//把使用的辅助空间释放
}

void MergeSort(int data[],int l,int r) {//归并排序的整体操作
	int m;
	if (l < r) {
		m = (l + r) >> 1;//除二
		MergeSort(data, l, m);
		MergeSort(data, m + 1, r);
		Merge(data,l, m, r);
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	int a[maxn],n;
	scanf("%d", &n);
	//for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	////BubbleSort(a, n);//冒泡排序
	////InsertSort(a, n); //插入排序
	////ShellSort(a, n);   //希尔排序
	////QuickSort(a, 1, n);   //快速排序
	////qsort(a, n + 1, sizeof(a[1]), cmp);  //qsort快速排序
	////ChoiceSort(a, n);//选择排序
	MergeSort(a, 1, n);
	for (int i = 1; i <= 10; i++)printf("%d ", a[i]);
	return 0;
}
/*
10
7 3 33 6 20 1 2 8 56 3
*/
