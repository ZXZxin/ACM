//��Ŀ���ӣ�https://vjudge.net/contest/77417#problem/B
//��Ŀ���⣬������ͨ����a[i] = fabs(a[i+1] - a[i])����ѭ����������1000�Σ��м��Ƿ����0�����߱��ĳ�������Ӷ�ѭ��
//����˼·���Ƚϼ򵥣�ģ�⼴�ɣ�������set������ʡ��һ���жϵ�ѭ����

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <set>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 10+10;
int a[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        bool flag = false;
        for(int j = 0; j < 1000; j++){
            set<int>s;
            int temp = a[0];
            for(int i = 0; i < n - 1; i++){
                a[i] = fabs(a[i+1] - a[i]);
                s.insert(a[i]);
            }
            a[n-1] = fabs(temp - a[n-1]);
            s.insert(a[n-1]);
            if(s.size() == 1){cout<<"ZERO"<<endl;flag = true;break;}
        }
        if(!flag)cout<<"LOOP"<<endl;
    }
    return 0;
}
