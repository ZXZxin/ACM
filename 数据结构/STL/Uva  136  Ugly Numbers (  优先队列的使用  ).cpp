//��Ŀ���ӣ�https://vjudge.net/contest/77100#problem/G
//��Ŀ���⣺�����ǲ��ܱ�����2,3,5���������������������1,2,3,4,5,6,8..���1500������
//����˼·�������ȶ��б�����Щ����2,3,5�ı������ǳ�����ÿ��ȡ�����ȶ�������С����������2,3,5�õ��µĳ��������ж϶������Ƿ��Ѿ����������������

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>

using namespace std;
const int a[3] = {2,3,5};
typedef long long LL;

struct cmp{
    bool operator () (const LL a,const LL b){
        return a > b;//ԽС��Խ�ȳ�����
    }
};//�ṹ��ǵ�����ֺ�

int main(){
    priority_queue<LL,vector<LL>,cmp>q;//cmp���õ����Լ�����Ľṹ��
    set<LL>s;
    s.insert(1);
    q.push(1);
    for(int i = 1; ;i++){
        LL x = q.top();q.pop();
        if(i == 1500){cout<<"The 1500'th ugly number is "<<x<<"."<<endl;break;}
        for(int j = 0; j < 3; j++){
            LL temp = x * a[j];
            if(!s.count(temp)){s.insert(temp);q.push(temp);}
        }
    }
    return 0;
}
