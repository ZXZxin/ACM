//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=1017
//��Ŀ���⣺���������ҵ����ٶ�С��n��������a,b������Ŀ�е�ʽ��
//����˼·�����⣬������һ����������Ҫ�ر�ע�⣬��ע��m����Ϊ0�����һ���������治��Ҫ�������

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <set>
using namespace std;
const int maxn = 100000 + 10;
int main(){
    //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,T;
    cin>>T;
    for(int k = 0; k < T; k++){
        int kase = 0;
        while(cin>>n>>m&&(n||m)){ //ע��m����Ϊ0
            int sum = 0;
            for(int i = 1; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if((i*i+j*j+m)%(i*j) == 0)sum++;
                }
            }
            cout<<"Case "<<++kase<<": "<<sum<<endl;
        }
        if(k != T-1)cout<<endl;  //�ܶ���Ŀ���и�ʽҪ��
    }
    return 0;
}






