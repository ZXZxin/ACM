//�����㷨����ʵ��
//(1)ֱ�Ӳ���(2)ϣ������(3)ð������(4)��������

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 100 + 10;

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

void InsertSort(int data[], int n) {//��������
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

//ϣ�������ѧϰ���ͣ�http://blog.csdn.net/morewindows/article/details/6668714
void ShellSort(int data[], int n) {//ϣ������
	/*for (int gap = n / 2; gap >= 1; gap /= 2) {//��ֱ�۵�д��
		for (int i = 1; i <= gap; i++) {
			for (int j = i + gap; j <= n; j += gap) {
				for (int k = j; data[k] < data[k - gap]; k -= gap)swap(data[k], data[k - gap]);//��ǰ�������ҵ��Լ���λ��
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
		for (int i = gap; i <= n; i++) {//ֱ�Ӵ�gap ����ʼ
			for (int j = i; data[j] < data[j - 1]; j -= gap)swap(data[j], data[j - 1]);
		}
	}*/
}

void BubbleSort(int data[], int n) {//ð������
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

void QuickSort(int data[], int left, int right) {//��������
	int i = left, j = right;
	data[0] = data[i];
	while (i < j) {
		while (i < j && data[0] < data[j])j--;   //�Ӻ���ǰ�ҵ���һ��С��key��
		if (i < j)data[i++] = data[j];   //���ҵ����������  ��ߵ�ֵ  ��ע���ʱdata[j] ��ֵ0
		while (i < j && data[0] > data[i])i++;   //��ǰ�����ҵ���һ������key��  
		if (i < j)data[j--] = data[i];   //���ҵ�����������ոյ�data[j]����ʵ��
	}
	data[i] = data[0];  //�ѹؼ��ַŵ��м�//Ҳ���ǹؼ��� data[0]��ߵľ���data[0]С,�ұߵľ���data[0]С
	if (left < right) {
		QuickSort(data, left, i - 1);
		QuickSort(data, i + 1, right);
	}
}

void ChoiceSort(int data[],int n) {//�򵥵�ѡ������
	for (int i = 1; i < n; i++) {//n - 1������
		int k = i;
		for (int j = i + 1; j <= n; j++) {
			if (data[j] < data[k])k = j;//�ҳ���С����
		}
		int temp;
		if (k != i) {//��ǰ�����������е����һ�����н���
			temp = data[k];
			data[k] = data[i];
			data[i] = temp;
		}
	}
}

void Merge(int data[], int l,int m,int r) {//�鲢�����һ�ι鲢����
	int *pd;
	pd = (int *)malloc((r - l + 1)*sizeof(int));//��ճ�һ���ռ䣬��ֹԽ��
	int i = l, j = m + 1,k = 0;
	while (i <= m && j <= r)pd[k++] = data[i] < data[j] ? data[i++] : data[j++];//�鲢���е��������Ա�����������ϲ�Ϊһ�������
	while (i <= m)pd[k++] = data[i++];//�����ʣ��ķ���
	while (j <= r)pd[k++] = data[j++];//���ұ�ʣ��ķ���
	for (k = 0, i = l; i <= r; i++, k++)data[i] = pd[k];
	free(pd);//��ʹ�õĸ����ռ��ͷ�
}

void MergeSort(int data[],int l,int r) {//�鲢������������
	int m;
	if (l < r) {
		m = (l + r) >> 1;//����
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
	////BubbleSort(a, n);//ð������
	////InsertSort(a, n); //��������
	////ShellSort(a, n);   //ϣ������
	////QuickSort(a, 1, n);   //��������
	////qsort(a, n + 1, sizeof(a[1]), cmp);  //qsort��������
	////ChoiceSort(a, n);//ѡ������
	MergeSort(a, 1, n);
	for (int i = 1; i <= 10; i++)printf("%d ", a[i]);
	return 0;
}
/*
10
7 3 33 6 20 1 2 8 56 3
*/
