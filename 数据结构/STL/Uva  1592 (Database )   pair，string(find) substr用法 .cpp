//��Ŀ���ӣ�https://vjudge.net/contest/77100#problem/I
//��Ŀ���⣺���㼸�м����ַ�����Ѱ���Ƿ����������ͬ����r1,r2,��������ͬ����c1,c2ʹ�����������е��ַ������
//����˼·�����ַ����ضϲ�ӳ���ID������Ҫ�ķ�������Ȼ���ĳһ�е������ַ��ŵ�pair�У�������map<pair,int>����ö������
            //ö��ÿһ�У����Ƿ���ֹ������ֹ����ʾ��ȣ���ӡ


#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>
#include <string.h>
#include <string>

using namespace std;
const int maxr = 10000+10;
const int maxc = 10+5;
map<string,int>id;
int cnt,idct[maxr][maxc];

int ID(const string &s){
    if(!id.count(s))id[s] = ++cnt;
    return id[s];
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,m;
    string s;
    while(cin>>n>>m) {
        getchar();  //Ϊ�˻���
        cnt = 0;
        id.clear();
        for(int i = 0; i < n; i++){
            getline(cin,s);
            int lastpos = -1;   //�ҵ�ÿ�β��ҵ����
            for(int j = 0; j < m; j++){
                int p = s.find(',',lastpos + 1);  //��lastpos��ʼ�ҵ����Žض�
                if(p == string::npos)p = s.size();  //���û���ҵ����������ַ�����Ϊ
                idct[i][j] = ID(s.substr(lastpos + 1,p - lastpos - 1));  //��lastpos(��ʼ) �� p�ضϲ�������ַ��ı�Ŵ���
                lastpos = p;
            }
        }
        bool flag = false;
        for(int c1 = 0; c1 < m; c1++){
            for(int c2 = c1 + 1; c2 < m; c2++){
                map<pair<int,int>,int>d;
                for(int i = 0; i < n; i++){
                    pair<int,int> p = make_pair(idct[i][c1],idct[i][c2]);
                    if(d.count(p)){cout<<"NO"<<endl;cout<<d[p]+1<<" "<<i+1<<endl;cout<<c1+1<<" "<<c2+1<<endl;flag = true;break;}
                    d[p] = i;
                }
                if(flag)break;
            }
            if(flag)break;
        }
        if(flag == false)cout<<"YES"<<endl;
    }
    return 0;
}

/*
����ѵĻ��д���
while(getline(cin,s)){
    stringstream ss(s);
    if(!(ss>>n>>m))break;
*/
