//��Ŀ���� : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4157
//��Ŀ���� : ����ƽ����n���׵�n���ڵ㣬Ҫ��������ԣ�����������߶�û�н��㡣
//����˼· : ���������ϵ�д�� : ÿ���ҳ������µĵ�,���ռ��ǵķ�ʽ,ÿ�����˺͹��������ͬ��ʱ��
             //���������ͬ�ﵽ�����һ����������Ȼ����εݹ����

//�����Ŀֵ��ѧϰ�ĵط� : (1) ��read()������װ�� �ṹ���� ,�Լ����غ�����д��
                         // (2) �ṹ��Ƕ����ע��ĵط� �Լ�sort()���÷�

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

const int maxn = 100 + 10;
using namespace std;

int n;
int ans[maxn * 2]; //��Ŷ�Ӧ�Ĺ�����

struct Point{  //��Ľṹ������
    int x,y;
    Point(){}
    Point(int x,int y):x(x),y(y){}
    double angle(const Point& p)const{  //����ÿ����ĽǶ�
        return atan2(y - p.y,x - p.x);
    }
    bool operator < (const Point & rhs)const {
        return (y < rhs.y)||(y == rhs.y && x < rhs.x);  //��ѡ��ǰ���
    }
    void read(){
        scanf("%d%d",&x,&y);
    }
};


struct Node {
    Point p;
    int id;  //1 ~ n(����)���� n+1 ~ 2n(��)
    double ang;  //�Ƕ�
    bool operator < (const Node & rhs)const {  //���սǶ�����
        return ang < rhs.ang;
    }
    void getAngle(const Node &rhs){  //���������֮������ߺ�ˮƽ֮��ļнǵĽǶ�
        ang = p.angle(rhs.p);
    }
    int type(){  //�����Ǿ��˻��ǹ�
        return id <= n ? 1 : -1;
    }

}p[maxn * 2];


void solve(int l,int r){
    if( l > r)return;
    int pos = l;
    for(int i = l + 1; i <= r; i++){  //�ҳ�����µĵ�
        if(p[i].p < p[pos].p){  //�Ѿ������������  //�������صĹ���Ƚ�
            pos = i;
        }
    }
    swap(p[pos],p[l]);
    for(int i = l + 1; i <= r; i++){//�������ߵĵ�͸���ĽǶ�
        p[i].getAngle(p[l]);
    }
    sort(p+1+l,p+1+r); //���Ƕ�����
    int cnt = p[l].type();
    for(int i = l + 1; i <= r; i++){
        cnt += p[i].type();
        if(cnt == 0){
            ans[p[l].id] = p[i].id; //��ÿ��ѡ�������µĺ����һ��������
            ans[p[i].id] = p[l].id;
            solve(l+1,i-1);  //�ݹ�ʣ�µ�
            solve(i+1,r);
            return ;
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n) != EOF){
        memset(ans,0,sizeof(ans));
        for(int i = 1; i <= 2*n; i++){  //����
            scanf("%d%d",&p[i].p.x,&p[i].p.y);
            //p[i].p.read();
            p[i].id = i;
        }
        solve(1,2*n);
        for(int i = 1; i <= n; i++){
            printf("%d\n",ans[i] - n);
        }
    }
    return 0;
}
