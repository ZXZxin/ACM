//题目链接：https://vjudge.net/contest/77100#problem/E
//题目大意：
          /*一个栈，有5种操作；
            PUSH：向栈中放一个空集合。
            DUP：复制栈顶集合。
            UNION：取栈顶的两个集合，取并集后放回。
            INTERSECT：取栈顶的两个集合，取交集后放回。
            ADD：取栈顶两个集合，将第一个集合作为元素放到第二个集合中，并将第二个集合放回栈。
            每次操作后输出栈定集合中元素的个数。*/
//解题思路：这个题目理解了好久，，把集合映射成ID（每个集合对应着一个ID（看这个集合有没有出现过））并通过ID取集合

#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>//set_onion包含在这个头文件中

using namespace std;

typedef set<int>Set;
map<Set,int>IDcache;//把集合映射成ID
vector<Set>Setcache;//根据ID取集合

int ID(Set x){
    if(IDcache.count(x))return IDcache[x];//如果出现就返回集合的ID
    Setcache.push_back(x);//如果没有就分配一个新的ID
    IDcache[x] = Setcache.size() - 1;
    return Setcache.size() - 1;
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,n;
    cin>>T;
    while(T--){
        stack<int>s;
        cin>>n;
        for(int i = 0; i < n; i++){
            string str;
            cin>>str;
            if(str == "PUSH") s.push(ID(Set()));//Set()是指一个空的Set型结构体
            else if(str == "DUP") s.push(s.top());
            else{
                Set x1 = Setcache[s.top()]; s.pop();//x1表示栈顶元素集合//s.top()代表ID
                Set x2 = Setcache[s.top()]; s.pop();
                Set x;
                if(str == "UNION")set_union(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
                if(str == "INTERSECT")set_intersection(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
                if(str == "ADD"){x = x2; x.insert(ID(x1));}
                s.push(ID(x));
            }
            cout<<Setcache[s.top()].size()<<endl;//Setcache[s.top()]表示栈顶元素集合//注意这里的结构体嵌套
        }
        cout<<"***"<<endl;
    }
    return 0;
}
