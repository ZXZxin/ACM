//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=2648
//题目大意：有很多商店，有样物品在每个商店的价钱都不一样，而且每天这个物品的价钱都会增加，
            //要求一个叫“memory”商店里的这个物品价格在所有商店里排在第几位（价格越低排在越前）
//解题思路：这里是用的哈希的思想，将每个商店用下标对应起来，然后用 hash函数 将相应的值存起来然后比较，hash是真的神奇!

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

const int maxn = 10000 + 10;
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    int n,m,a;
    string s;
    int Hash[maxn];
    map<string,int>dict;
    while(scanf("%d",&n) != EOF){
        dict.clear();
        int maxx = 0;
        for(int i = 0; i < n; i++){
            cin>>s;
            dict[s] = i;//每个字符对应一个 下标值
            if(s == "memory")maxx = i;
        }
        memset(Hash,0,sizeof(Hash));
        scanf("%d",&m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin>>a>>s;
                Hash[dict[s]] += a;  //将每个字符串的 对应的价格 对应起来
            }
            int sum = 0;
            for(int j = 0; j < n; j++)if(Hash[j] > Hash[maxx])sum++;
            printf("%d\n",sum + 1);
        }
    }
    return 0;
}
