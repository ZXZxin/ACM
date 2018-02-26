#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 100 + 10;

int cmp(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}

void QuickSort(int *A,int x,int y){
    int i = x,j = y;
    int key = A[i]; //����߿�ʼ
    while(i < j){
        while(i < j && A[j] > key)j--;//�Ӻ���ǰ�ҵ�һ��С��key��
        if(i < j)A[i++] = A[j];   //���ҵ����������  ��ߵ�ֵ  ��ע���ʱdata[j] ��ֵ0
        while(i < j && A[i] < key)i++; //��ǰ�����ҵ���һ������key��
        if(i < j)A[j--] = A[i];  //���ҵ�����������ոյ�data[j]����ʵ��
    }
    A[i] = key;   //������һ��//�ѹؼ��ַŵ��м�//Ҳ���ǹؼ��� data[0]��ߵľ���data[0]С,�ұߵľ���data[0]С
    if(x < y){
        QuickSort(A,x,i-1);
        QuickSort(A,i+1,y);
    }
}

int mylower_bound(int *A,int x,int y,int v){  //����  ������ظ��� �½�(����1,2,2,2,3,4)����2,����1
    while(x < y){
        int m = x + (y-x)/2;
        //if(A[m] == v)return m;
        if(A[m] >= v)y = m; //�����
        else x = m + 1;    //���ұ�
    }
    return x;
}

int myupper_bound(int *A,int x,int y,int v){
    while(x < y){
        int m = x + (y-x)/2;
        if(A[m] <= v)x = m + 1;// ���ұ�
        else y = m; //�����
    }
    return x;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n,a[maxn],v; //b�����������������Ľ��
	while(scanf("%d",&n) != EOF){
        for (int i = 0; i < n; i++)scanf("%d", &a[i]);//1 3 2 9 4 7 2 2
        scanf("%d",&v); //����Ҫ���ҵ���
        QuickSort(a,0,n);
        //qsort(a,n,sizeof(a[0]),cmp); // ����֮����1 2 2 2 3 4 7 9
        printf("%d\n",mylower_bound(a,0,n,v)); //��� 1
        printf("%d\n",myupper_bound(a,0,n,v)); //��� 3 + 1
	}
	return 0;
}
/*
��������:
8
1 3 2 9 4 7 2 2
2
*/
