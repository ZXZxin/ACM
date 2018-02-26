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
    int key = A[i]; //从左边开始
    while(i < j){
        while(i < j && A[j] > key)j--;//从后往前找第一个小于key的
        if(i < j)A[i++] = A[j];   //把找到的这个赋给  左边的值  ：注意此时data[j] 无值0
        while(i < j && A[i] < key)i++; //从前往后找到第一个大于key的
        if(i < j)A[j--] = A[i];  //把找到的这个赋给刚刚的data[j]，，实现
    }
    A[i] = key;   //继续下一步//把关键字放到中间//也就是关键字 data[0]左边的均比data[0]小,右边的均比data[0]小
    if(x < y){
        QuickSort(A,x,i-1);
        QuickSort(A,i+1,y);
    }
}

int mylower_bound(int *A,int x,int y,int v){  //返回  如果有重复的 下界(比如1,2,2,2,3,4)查找2,返回1
    while(x < y){
        int m = x + (y-x)/2;
        //if(A[m] == v)return m;
        if(A[m] >= v)y = m; //在左边
        else x = m + 1;    //在右边
    }
    return x;
}

int myupper_bound(int *A,int x,int y,int v){
    while(x < y){
        int m = x + (y-x)/2;
        if(A[m] <= v)x = m + 1;// 在右边
        else y = m; //在左边
    }
    return x;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n,a[maxn],v; //b数组用来保存排序后的结果
	while(scanf("%d",&n) != EOF){
        for (int i = 0; i < n; i++)scanf("%d", &a[i]);//1 3 2 9 4 7 2 2
        scanf("%d",&v); //输入要查找的数
        QuickSort(a,0,n);
        //qsort(a,n,sizeof(a[0]),cmp); // 排序之后是1 2 2 2 3 4 7 9
        printf("%d\n",mylower_bound(a,0,n,v)); //输出 1
        printf("%d\n",myupper_bound(a,0,n,v)); //输出 3 + 1
	}
	return 0;
}
/*
测试数据:
8
1 3 2 9 4 7 2 2
2
*/
