//��Ŀ���ӣ�https://vjudge.net/contest/77100#problem/F
//��Ŀ���⣺��n�����顣 ����ÿ��ENQUEUE  x ��� ���x���ڵĶ����Ѿ��ڶ����У� ��x���ڶ��������Ķ����β�ͣ� �������ڶ��е�ĩβ��
           // �������Ϊ�����еĶ��е�ζ����DEQUEUEɾ����������е�һ�����еĶ�ͷ
//����˼·�����ö���ģ��


#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <string>
#include <map>

using namespace std;
const int maxn = 1000 + 10;
queue<int>q,q2[maxn];//q������Ķ��У�q2��ÿ���ŶӵĶ���

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
        while(!q.empty())q.pop();//���������ط����˺ܶ�飬�����´�Ҫע��
        for(int i = 0; i < maxn; i++){
            while(!q2[i].empty())q2[i].pop();
        }
        string str;
        while(cin>>str && str != "STOP"){
            if(str == "ENQUEUE"){ cin>>x; if(q2[team[x]].empty())q.push(team[x]); q2[team[x]].push(x); }
            else if(str == "DEQUEUE"){
                int t = q.front();//������еĶ�ͷ�Ķ��еĶ�ͷ����
                cout<<q2[t].front()<<endl;
                q2[t].pop();
                if(q2[t].empty())q.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}
