//题目链接 : https://www.nowcoder.com/acm/contest/70/B
//主要是把表打出来,然后有点技巧的计算
//考的就是思维

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;
const int maxn = 2050 + 10;
typedef long long LL;

LL L,R;
int len;
LL Lk[maxn];

//4 7     -->  2
//44 47 74 77   -->  4
//444 447 474 477 744 747 774 777  -->  8
void init(){  //打表
    Lk[0] = 4,Lk[1] = 7;
    int s1 = 0,s2;
    for(int i = 1; i <= 9; i++){
        s2 = pow(2,i);
        for(int j = s1; j < s1+s2; j++){
            Lk[len++] = Lk[j]*10+4;
            Lk[len++] = Lk[j]*10+7;
        }
        s1 += s2;
    }
    //for(int i = 0; i < len; i++)printf("%lld\n",Lk[i]);
}
int main(){
    len = 2;
    init(); //打表
    cin>>L>>R;
    LL i = L,pos = L,sum = 0;
    for(int j = 0; j < len;){
        if(Lk[j] >= i){
            i++;
            if(i == R+1){
                sum += (i-pos)*Lk[j];
                break;
            }
        }else{
            sum += (i-pos)*Lk[j];
            pos = i;
            j++;
            if(i == R + 1)break;
        }
    }
    cout<<sum<<endl;
    return 0;
}
