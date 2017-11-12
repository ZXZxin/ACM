//题目链接：https://vjudge.net/contest/77100#problem/I
//题目大意：给你几行几列字符串，寻找是否存在两个不同的行r1,r2,和两个不同的列c1,c2使得这两行两列的字符串相等
//解题思路：将字符串截断并映射成ID（很重要的方法），然后把某一行的两个字符放到pair中，并建立map<pair,int>，并枚举两列
            //枚举每一行，看是否出现过，出现过则表示相等，打印


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
        getchar();  //为了换行
        cnt = 0;
        id.clear();
        for(int i = 0; i < n; i++){
            getline(cin,s);
            int lastpos = -1;   //找到每次查找的起点
            for(int j = 0; j < m; j++){
                int p = s.find(',',lastpos + 1);  //从lastpos开始找到逗号截断
                if(p == string::npos)p = s.size();  //如果没有找到则以整个字符串作为
                idct[i][j] = ID(s.substr(lastpos + 1,p - lastpos - 1));  //从lastpos(起始) 到 p截断并将这段字符的编号存入
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
刘汝佳的换行处理
while(getline(cin,s)){
    stringstream ss(s);
    if(!(ss>>n>>m))break;
*/
