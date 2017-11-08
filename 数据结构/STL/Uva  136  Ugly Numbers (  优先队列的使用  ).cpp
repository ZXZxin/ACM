//题目链接：https://vjudge.net/contest/77100#problem/G
//题目大意：丑数是不能被除了2,3,5以外的素数整除的数，如1,2,3,4,5,6,8..求第1500个丑数
//解题思路：用优先队列保存这些数，2,3,5的倍数都是丑数，每次取出优先队列中最小的数，乘以2,3,5得到新的丑数（先判断队列中是否已经出现这个丑数），

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>

using namespace std;
const int a[3] = {2,3,5};
typedef long long LL;

struct cmp{
    bool operator () (const LL a,const LL b){
        return a > b;//越小的越先出队列
    }
};//结构体记得这个分号

int main(){
    priority_queue<LL,vector<LL>,cmp>q;//cmp引用的是自己定义的结构体
    set<LL>s;
    s.insert(1);
    q.push(1);
    for(int i = 1; ;i++){
        LL x = q.top();q.pop();
        if(i == 1500){cout<<"The 1500'th ugly number is "<<x<<"."<<endl;break;}
        for(int j = 0; j < 3; j++){
            LL temp = x * a[j];
            if(!s.count(temp)){s.insert(temp);q.push(temp);}
        }
    }
    return 0;
}
