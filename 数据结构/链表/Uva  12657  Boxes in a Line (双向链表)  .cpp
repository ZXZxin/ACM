//��Ŀ���ӣ�https://vjudge.net/contest/169966#problem/E
//��Ŀ���⣺�����ƶ�����,�ĸ�ָ��ƶ�֮�������������ĺ�
//����˼·�����������ģ���������ע�Ȿ��inv����������÷�������4�Ĳ������Լ�¼�Ƿ��й�4�Ĳ������еĻ�1������2������������
//HINT�������Ŀ�и����ʣ�Ϊʲô����� if(op == 3&&Right[y] == x) swap(x,y);ע�͵��������һ������Ǵ�ģ���ע�ʹ��룩

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 100000+10;
int Left[maxn],Right[maxn];
int n,m;

void init(){
    for(int i = 1; i <= n; i++){Right[i] = (i + 1)%(n + 1); Left[i] = i - 1;}
    Left[0] = n; Right[0] = 1;//����һ��0��Ϊ��֮���ҵ���̽ڵ�
}

void Link(int L,int R){
    Right[L] = R;
    Left[R] = L;
}

int main(){
    //freopen("in.txt","r",stdin);
    int kase = 0;
    while(cin>>n>>m){
        init();
        int x,y,op,inv = 0;
        for(int i = 0;i < m; i++){
            cin>>op;
            if(op == 4)inv = !inv;
            else {
                cin>>x>>y;
                if(op == 3&&Right[y] == x) swap(x,y); //���������Ϊ�˺���ͳһ�Ĳ����������else if(op == 3))//(1)
                if(op != 3&&inv)op = 3 - op;
                if(op == 1&&Left[y] == x)continue ;
                if(op == 2&&Right[y] == x)continue ;
                int LX = Left[x],RX = Right[x],LY = Left[y],RY = Right[y];
                if(op == 1){Link(LX,RX); Link(LY,x); Link(x,y);}
                else if(op == 2){Link(LX,RX); Link(x,RY); Link(y,x);}
                else if(op == 3){
                    if(x == Left[y]){Link(LX,y); Link(y,x); Link(x,RY);}
                    //else if(Right[y] == x){Link(y,RX);Link(y,x);Link(x,LY);}//ʡ��(1)������ע����һ���Ǵ��
                    else{
                        Link(LX,y); Link(y,RX); Link(LY,x); Link(x,RY);
                    }
                }
            }
        }
        int b = 0;          //����һ��0��Ϊ��֮���ҵ���̽ڵ�
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            b = Right[b];
            if(i%2 == 1)ans += b;
        }
        if(inv && n%2 == 0)ans = (long long)n*(n + 1)/2 - ans;//�����ż������,���й�������4�Ĳ�������������ĺͼ�ȥ����ĺ�
        cout<<"Case "<<++kase<<": "<<ans<<endl;
    }
    return 0;
}
