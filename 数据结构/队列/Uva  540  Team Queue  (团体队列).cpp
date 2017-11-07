//题目链接：https://vjudge.net/contest/77100#problem/F
//题目大意：有n个队伍。 对于每个ENQUEUE  x 命令。 如果x所在的队伍已经在队列中， 则x排在队列中它的队伍的尾巴， 否则排在队列的末尾。
           // 可以理解为队列中的队列的味道。DEQUEUE删除团体队列中第一个队列的队头
//解题思路：利用队列模拟


#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <string>
#include <map>

using namespace std;
const int maxn = 1000 + 10;
queue<int>q,q2[maxn];//q是整体的队列，q2是每个团队的队列

int main(){
    //freopen("in.txt","r",stdin);
    int n,kase = 0;
    while(cin>>n&&n){
        cout<<"Scenario #"<<++kase<<endl;
        map<int,int>team;
        int m,x;
        for(int i = 0; i < n; i++){
            cin>>m;
            for(int j = 0; j < m; j++){cin>>x; team[x] = i;}
        }
        while(!q.empty())q.pop();//在这两个地方错了很多遍，，，下次要注意
        for(int i = 0; i < maxn; i++){
            while(!q2[i].empty())q2[i].pop();
        }
        string str;
        while(cin>>str && str != "STOP"){
            if(str == "ENQUEUE"){ cin>>x; if(q2[team[x]].empty())q.push(team[x]); q2[team[x]].push(x); }
            else if(str == "DEQUEUE"){
                int t = q.front();//团体队列的队头的队列的队头出队
                cout<<q2[t].front()<<endl;
                q2[t].pop();
                if(q2[t].empty())q.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}
