//题目链接: http://poj.org/problem?id=1804
//题目大意: 就是给你一组数,要你求逆序数对的个数
//解题思路: 直接上 刘汝佳第八章的 归并排序的代码
           //注意 逆序数就是 i < j && f[i] > f[j] 分治求解 (1)划分成尽量相等的两半,(2)递归求解:统计i和j均在左边或者均在右边的逆序数对个数
           //"合并问题": 统计i 在 左边,j在右边的逆序对个数
           //注意合并时: 就是复制完右边的 之后 ,左边 [p,m)之间的数会比右边的大 还没有进入T数组的f(i)>f(j)
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 1000 + 10;
int cnt; //统计逆序数

void Merge(int *A,int x,int y,int *T){ //T为临时空间
    if(y - x > 1){
        int m = x + (y-x)/2;  //划分
        int p = x, q = m, i = x;
        Merge(A,x,m,T); //递归求解
        Merge(A,m,y,T);
        while(p < m || q < y){
            if( q >= y || (p < m && A[p] <= A[q]))T[i++] = A[p++];
            else {
                T[i++] = A[q++];
                cnt += m - p; //计算逆序数, 就是复制完右边的 之后 ,左边 [p,m)之间的数会比右边的大(f(i))
            }
        }
        for(i = x; i < y; i++)A[i] = T[i]; //注意左右区间
    }
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n,kase = 0,T,a[maxn],b[maxn]; //b数组用来保存排序后的结果
	scanf("%d",&T);
	while(T--){
        scanf("%d", &n);
        cnt = 0;
        for (int i = 0; i < n; i++)scanf("%d", &a[i]);
        Merge(a,0,n,b);
        //for (int i = 0; i < n; i++)printf("%d ",a[i]);
        //printf("\n");
        //printf("逆序数对的个数是 : %d\n",cnt);
        printf("Scenario #%d:\n%d\n\n",++kase,cnt);
	}
	return 0;
}
