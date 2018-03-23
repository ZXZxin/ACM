//题目链接 : https://vjudge.net/contest/216415#problem/B
//题目大意 : 就是给你一些矩阵的行数和列数,要你求有多少对可以相乘
//解题思路 : 先排个序,然后找两边相同的相乘
  //注 : 一定要注意c1,c2要用LL(错了好多次,超级绝望,下次不要再犯了)

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int maxn = 1e5 + 10;
using namespace std;
typedef long long LL;

int cmp(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,T;
    int a[maxn],b[maxn];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 0; i < n; i++)scanf("%d%d",&a[i],&b[i]);
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp);
        LL sum = 0;
        int i = 0,j = 0;
        while(true){
            if(i >= n || j >= n)break;
            if(a[i] > b[j] && j < n){ j++; continue; }
            if(a[i] < b[j] && i < n){ i++; continue; }
            LL c1 = 0,c2 = 0;
            while(a[i] == b[j] && i < n){ i++; c1++; }
            while(b[j] == a[i-1] && j < n){ j++; c2++; }
            sum += c1*c2;
        }
       cout<<sum<<endl;
    }
    return 0;
}


//map做的
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;
const int maxn = 1e9 + 10;
typedef long long LL;
map<int,int>a;
map<int,int>b;

int main(){
    int T,n,x,y;
    scanf("%d",&T);
    while(T--){
        a.clear();b.clear();
        scanf("%d",&n);
        for(int i= 0; i < n; i++){
            scanf("%d %d",&x,&y);
            a[x]++;b[y]++;
        }
        LL sum = 0;
        for(map<int,int>::iterator it = b.begin(); it != b.end(); it++){
            LL c1 = a[it->first];
            LL c2 = it->second;
            sum += c1*c2;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
