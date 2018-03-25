//并查集的模板

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100000 + 10;

int Fa[maxn],Rank[maxn];

void init(){
    for(int i = 0; i < maxn; i++)Fa[i] = i; //注意这里
    for(int i = 0; i < maxn; i++)Rank[i] = 1;
}

int Find(int v){
	return Fa[v] == v ? v : Fa[v] = Find(Fa[v]);
}

void Union(int x, int y){
	int fx = Find(x);
	int fy = Find(y);
	if (fx == fy)return;
	if (Rank[fx] < Rank[fy])
        Fa[fx] = fy;
	else{
		Fa[fy] = fx;
		if (Rank[fx] == Rank[fy])Rank[fy]++;
	}
}

int is_Same(int x,int y){ //检查是不是在同一个集合中
    return (Find(x) == Find(y));
}


int main(){
    init(); //初始化
    //第一个集合
    Union(1,3); //第一个作为父亲
    Union(3,5);
    Union(3,7);
    Union(3,11);
    Union(1,9);

    //第二个集合
    Union(2,4);
    Union(4,6);
    Union(2,10);
    Union(10,8);
    cout<<is_Same(3,5)<<endl; //查找的都是祖先
    cout<<is_Same(3,6)<<endl;
    cout<<Find(Fa[11])<<endl;
    cout<<Find(Fa[6])<<endl;
    return 0;
}

