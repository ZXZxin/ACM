//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=1014
//��Ŀ���⣺���Ǹ���һ��������ģ�����Լ�ѡ��һ����ʼֵ�����Ǹ��������һЩ���������Щ�����������е�0 - Mod-1�����Good Choice
//����˼·��ֱ��ģ�⣬��һ��set���Ƿ���ڼ���

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
    int n,m;
    set<int>s;
    int a[maxn];
    while(cin>>n>>m){
        s.clear();
        a[0] = 0;
        int i;
        for(i = 1; i < m; i++){
            a[i] = (a[i-1] + n)%m;
            if(a[i] == 0)break; //�˾��ʡ��
        }
        bool flag = true;
        for(int j = 0; j < i; j++)s.insert(a[j]);
        for(int j = 0; j < m; j++)if(!s.count(j)){flag = false;break;}
        printf("%10d%10d",n,m);
        if(flag)cout<<"    Good Choice"<<endl;//ע��ո���4��
        else cout<<"    Bad Choice"<<endl;
        cout<<endl;
    }
    return 0;
}






