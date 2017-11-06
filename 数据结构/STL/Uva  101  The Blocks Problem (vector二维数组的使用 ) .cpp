//��Ŀ���ӣ�https://vjudge.net/contest/77100#problem/B
//��Ŀ���⣺����ľ����ƶ���
        /*
        move a onto b �����a��b�Ϸ���ľ��ȫ����λ��Ȼ���a�ŵ�b ����
        move a over b �����a�Ϸ��Ĺ�λ����a����b����ľ��Ķ���
        pile a onto b �����b�Ϸ��Ĺ�λ��Ȼ���a �������ľ��������b����
        pile a over b �����a�������ľ�������Ƶ�b����ľ��Ķ���
        ���ƶ�������
        */
//����˼·����vector��ά����ģ���ƶ�

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 20+10;
int n;
vector<int>block[maxn];

void find_block(int x,int &p,int &h){//�ҵ�ĳ��ľ��λ��
    for(p = 0; p < n; p++){//***ǧ��Ҫд(int p = 0; p < n; p++)����
        for(h = 0; h < block[p].size(); h++){
            if(x == block[p][h])return;
        }
    }
}

void clear_above(int p,int h){//�ѵ�p��h�߶����ϵ�ľ��ȫ����λ
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
