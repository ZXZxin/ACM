//题目链接：https://vjudge.net/contest/77100#problem/B
//题目大意：就是木块的移动：
        /*
        move a onto b 代表把a和b上方的木块全部归位，然后把a放到b 上面
        move a over b 代表把a上方的归位，把a放在b所在木块的顶部
        pile a onto b 代表把b上方的归位，然后把a 及上面的木块整体移b上面
        pile a over b 代表把a及上面的木块整体移到b所在木块的顶部
        求移动后的情况
        */
//解题思路：用vector二维数组模拟移动

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 20+10;
int n;
vector<int>block[maxn];

void find_block(int x,int &p,int &h){//找到某块木的位置
    for(p = 0; p < n; p++){//***千万不要写(int p = 0; p < n; p++)出错
        for(h = 0; h < block[p].size(); h++){
            if(x == block[p][h])return;
        }
    }
}

void clear_above(int p,int h){//把第p堆h高度以上的木块全部归位
    for(int i = h + 1; i < block[p].size(); i++){
        int x = block[p][i];
        block[x].push_back(x);
    }
    block[p].resize(h+1);
}

void pile_onto(int p,int h,int p2){
    for(int i = h; i < block[p].size(); i++){
        block[p2].push_back(block[p][i]);
    }
    block[p].resize(h);
}

int main(){
    //freopen("in.txt","r",stdin);
    cin>>n;
    int a,b;
    string s1,s2;
    for(int i = 0; i < n; i++){
        block[i].push_back(i);
    }
    while(cin>>s1){
        if(s1 == "quit")break;
        cin>>a>>s2>>b;
        int pa,pb,ha,hb;
        find_block(a,pa,ha);
        find_block(b,pb,hb);
        if(pa == pb)continue;
        if(s1 == "move" && s2 == "onto"){
            clear_above(pa,ha);
            clear_above(pb,hb);
            pile_onto(pa,ha,pb);
        }
        else if(s1 == "move" && s2 == "over"){
            clear_above(pa,ha);
            pile_onto(pa,ha,pb);
        }
        else if(s1 == "pile" && s2 == "onto"){
            clear_above(pb,hb);
            pile_onto(pa,ha,pb);
        }
        else if(s1 == "pile" && s2 == "over"){
            pile_onto(pa,ha,pb);
        }
//        if(s2 == "onto")clear_above(pb,hb);
//        if(s1 == "move")clear_above(pa,ha);
//        pile_onto(pa,ha,pb);
    }
    for(int i = 0; i < n; i++){
        cout<<i<<":";
        for(int j = 0; j < block[i].size(); j++){
            cout<<" "<<block[i][j];
        }
        cout<<endl;
    }
    return 0;
}
