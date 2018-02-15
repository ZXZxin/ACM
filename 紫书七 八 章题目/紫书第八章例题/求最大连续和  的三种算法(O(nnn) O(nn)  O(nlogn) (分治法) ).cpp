//求最大连续和(一)：O(n*n*n)
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

int main(){
    //freopen("in.txt","r",stdin);
    int n,a[maxn];
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; i++)scanf("%d",&a[i]);
        int maxx = a[0];
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum = 0;
                for(int k = i; k <= j; k++)sum += a[k];
                if(maxx < sum)maxx = sum;
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}

/*
测试数据:
3
2 4 -3
5
2 5 -1 2 -1
*/

//求最大连续和(二) O(n*n): 优化最大连续和的算法: 连续子序列之和 = 两个前缀和之差
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

int main(){
    //freopen("in.txt","r",stdin);
    int n,a[maxn];
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; i++)scanf("%d",&a[i]);
        int s[maxn];
        s[0] = a[0];
        for(int i = 1; i < n; i++)s[i] = s[i-1] + a[i];
        int maxx = a[0];
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                maxx = max(maxx,s[j] - s[i-1]);
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}


//求最大连续和(三) O(n*logn): 分治法: (1)划分问题(2)递归求解(3)合并问题
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

int maxsum(int *A,int x,int y){ //返回A数组[x,y)之间的最大连续和
    int v,L,R,maxx;
    if(y - x == 1)return A[x]; //递归边界
    int m = x + (y-x)/2;
    maxx = max(maxsum(A,x,m),maxsum(A,m,y));  //分治第二步: 递归求解
    v = 0;L = A[m-1];
    for(int i = m-1; i >= x; i--)L = max(L,v += A[i]); //分治第三步:合并(1)：从分界点往左的最大连续和L
    v = 0;R = A[m];
    for(int i = m; i < y; i++)R = max(R,v += A[i]); //分治第三步:合并(2)：从分界点往右的最大连续和R
    return max(maxx,L+R);  //把子问题的解 和 L+R 进行比较
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,a[maxn];
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; i++)scanf("%d",&a[i]);
        printf("%d\n",maxsum(a,0,n));
    }
    return 0;
}

