//题目链接：http://172.30.18.236/JudgeOnline/problem.php?cid=1021&pid=0
//题目大意：n点共圆
//解题思路：先由三个点，求出圆心，半径，再判断


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
const int maxn =15;

int n;
int x[maxn],y[maxn];
int a,b,c,d,e,f,X,Y,r;

int main(){
    //freopen("in.txt","r",stdin);
    while(cin>>n){
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }if(n<=3){cout<<"Yes"<<endl;continue;}
    a=2*(x[2]-x[1]);
    b=2*(y[2]-y[1]);
    c=x[2]*x[2]+y[2]*y[2]-x[1]*x[1]-y[1]*y[1];
    d=2*(x[3]-x[2]);
    e=2*(y[3]-y[2]);
    f=x[3]*x[3]+y[3]*y[3]-x[2]*x[2]-y[2]*y[2];
    X=(b*f-e*c)/(b*d-e*a);
    Y=(d*c-a*f)/(b*d-e*a);
    r=(X-x[1])*(X-x[1])+(Y-y[1])*(Y-y[1]);
    int flag=1;
    for(int i=4;i<=n;i++){
        if((x[i]-X)*(x[i]-X)+(y[i]-Y)*(y[i]-Y)!=r){flag = 0;break;}
    }
    if(flag == 1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    }
    return 0;
}
