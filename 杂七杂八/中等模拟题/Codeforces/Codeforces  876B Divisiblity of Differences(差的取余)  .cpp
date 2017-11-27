//��Ŀ���ӣ�http://codeforces.com/problemset/problem/876/B
//��Ŀ���⣺���Ǹ���n,k,m������n�����������ܲ��ܴ�n������ѡk������ʹ����k�����������������Ĳ������m
//����˼·:�ؼ���ʵ����Ҫ���������е�ͬ�࣬�������Ĳ�����m������������m�����

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 100000 + 10;
int main(){
    //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,m;
    int a[maxn];
    vector<int>ans;
    while(cin>>n>>k>>m){
        ans.clear();
        int mod[maxn],sum[maxn];
        memset(sum,0,sizeof(sum));
        for(int i = 0; i < n; i++){
            cin>>a[i];
            mod[i] = a[i];
            mod[i] %= m;
        }
        for(int i = 0; i < n; i++)sum[mod[i]]++;//ͳ��ÿ�������ĸ���
        int maxx= 0,maxi;
        for(int i = 0; i < m; i++){
            if(sum[i] > maxx){maxx = sum[i];maxi = i;}  //��¼��������
        }
        if(maxx < k)cout<<"No"<<endl;
        else{
            cout<<"Yes"<<endl;
            for(int i = 0; i < n; i++){
                if(maxi == mod[i])ans.push_back(a[i]);
                if(ans.size() == k)break;//��k���͹���
            }
            for(int i = 0; i < ans.size() - 1; i++)cout<<ans[i]<<" ";
            cout<<ans[ans.size() - 1]<<endl;
        }
    }
    return 0;
}
