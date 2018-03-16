//题目链接:https://www.patest.cn/contests/gplt/L1-031
//注意浮点数的判断相等,比较大小

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int maxn = 1000 + 10;
using namespace std;
double eps = 1e-6;

int main(){
    freopen("in.txt","r",stdin);
    int n,H,W;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&H,&W);
        double FW = (H-100)*0.9*2;
        if(fabs(W-FW) < FW*0.1 - eps){ // 注意浮点数的判断精度
            cout<<"You are wan mei!"<<endl;
        }else if(fabs(W-FW) >= FW*0.1 && W > FW){
            cout<<"You are tai pang le!"<<endl;
        }else {
            cout<<"You are tai shou le!"<<endl;
        }
    }

    return 0;
}
