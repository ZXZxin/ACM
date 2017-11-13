//题目链接：https://vjudge.net/contest/77417#problem/D
//题目大意：就是看输入的每一组(a,b)是否在输入的数据中存在(b,a),如果都存在，则输出YES，否则输出NO
//解题思路：使用map是最简单的，熟悉map的使用以及first,second的访问

#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;
map<pair<int,int>,int>dict;
map<pair<int,int>,int>::iterator it;

bool Judge(){
    for(it = dict.begin(); it != dict.end(); it++){
        if(it->second)return false;//可以直接用it->访问map中的元素，first是map中的第一个元素，second是map中的第二个元素
    }
    return true;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,a,b;
    while(cin>>n&&n){
        dict.clear();
        for(int i = 0; i < n; i++){
            cin>>a>>b;
            a < b ? ++dict[make_pair(a,b)] : --dict[make_pair(b,a)];
        }
        if(Judge())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
