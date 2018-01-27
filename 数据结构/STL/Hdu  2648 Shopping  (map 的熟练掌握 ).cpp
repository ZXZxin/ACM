//题目链接 : http://acm.hdu.edu.cn/showproblem.php?pid=2648
//题目大意 : 题目大意:有很多商店，有样物品在每个商店的价钱都不一样，而且每天这个物品的价钱都会增加，
            //要求一个叫“memory”商店里的这个物品价格在所有商店里排在第几位（价格越低排在越前）
//解题思路 : 这题用hash做会更快一些，这里熟悉一下 map的用法,一开始没有注意到是 价钱会增加 wa了好几次，注意map每次使用时clear一下

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    int n,m,a;
    string s;
    map<string,int>dict;
    while(scanf("%d",&n) != EOF){
        dict.clear();
        for(int i = 0; i < n; i++){
            cin>>s;
            dict[s] = 0;
        }
        scanf("%d",&m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin>>a>>s;
                dict[s] += a;
            }
            map<string,int>::iterator it;
            int sum = 0;
            for(it = dict.begin(); it != dict.end(); it++){
                if(it->second > dict["memory"])sum++;  //注意 map的用法 ->first,->second,以及 直接 dict["memory"]的用法
            }
            printf("%d\n",sum + 1);
        }
    }
    return 0;
}
