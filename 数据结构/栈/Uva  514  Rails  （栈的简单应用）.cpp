//��Ŀ���ӣ�https://vjudge.net/contest/169966#problem/B
//��Ŀ���⼰����˼·����A->C�ʹ�C->B������Ҫ��˳��(Bվ��˳��)��[5,4,1,2,3]��������ģ���A�е�ԭ˳����[1,2,3,4,5]��1��n��,
            //��ô���������������������BҪ��ĵ�һ������A�еĵ�һ������ôֱ�Ӵ�A->B������
            //���C��ջ������BҪ��ĵ�һ��,��ôC->B,��������ǣ���ôֻ��A->C��
            //������϶���������Ҳ����˵A�����Ѿ�û�������ˣ���˵����Ҫ��˳���ǲ����ܳ��ֵ�
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;
const int maxn = 1000+10;

int n;
int target[maxn];
stack<int>s;

int main(){
    //freopen("in.txt","r",stdin);
    while(cin>>n&&n){
        while(cin>>target[1]&&target[1]!=0){
            for(int i = 2; i <= n; i++){
                cin>>target[i];
            }
            while(!s.empty())s.pop();
            int A = 1;//Aվ�����ݣ�Ĭ��1-n��
            int B = 1;//��������ݣ�Bվ�����ݣ�
            bool flag = true;
            while(B <= n){
                if(target[B] == A){
                    A++;
                    B++;
                }
                else if(!s.empty()&&s.top() == target[B]){
                    s.pop();
                    B++;
                }
                else if(A <= n ){
                    s.push(A++);
                }
                else {flag = false ;break;}
            }
            if(!flag)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
