//��Ŀ���ӣ�https://vjudge.net/contest/77417#problem/C
//��Ŀ���⣺����ģ����У�����n��һ���ƴ�1��n������õ�һ���ƣ�Ȼ��ѵڶ��ŷŵ���β,ֱ��ֻʣһ���ƣ�����õ����ƺ�ʣ�����
//����˼·������ģ�⼴��

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    queue<int>q;
    while(cin>>n&&n){
        while(!q.empty())q.pop();
        for(int i = 1; i <= n; i++){
            q.push(i);
        }
        if(n < 2){cout<<"Discarded cards:"<<endl; cout<<"Remaining card: "<<q.front()<<endl;continue;}//��������ʽ��ķ�
        cout<<"Discarded cards: ";
        while(q.size() != 2){
            cout<<q.front()<<", ";
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<endl;
        q.pop();
        cout<<"Remaining card: "<<q.front()<<endl;
    }
    return 0;
}
