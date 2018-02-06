//��Ŀ���ӣ�https://vjudge.net/contest/171111#problem/A
//��Ŀ����: ���Ǹ���һ��2 - 79֮����������� 1000 - 100000֮�������Щ������� abcde / efghi = n�������ע��ǰ��0
//����˼·: ���ö�ٵķ�ʽ��һ��Ĳ�ͬ����Ƿ����ö�٣��ص�����������˼��

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 100 + 10;
using namespace std;

bool Ok(int x,int y){  //�ж��ǲ���һ�� 0123456789 ������(û���ظ�������)
    int vis[15];
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < 5; i++){
        vis[x%10]++; vis[y%10]++;
        if(vis[x%10] > 1 || vis[y%10] > 1)return false;
        x /= 10; y /= 10;
    }
    return true;
}

int main(){
    int n,kase = 0;
    while(scanf("%d",&n) != EOF && n != 0){
        if(kase++)printf("\n");//�Ҿ���徵����
        bool flag = false;
        for(int i = 1000; ; i++){
            if(Ok(i,i*n)){
                flag = true;
                printf("%05d / %05d = %d\n",i*n,i,n);
            }
            if(i*n > 98765)break;
        }
        if(!flag)printf("There are no solutions for %d.\n",n);
    }
    return 0;
}


//����ѵĽⷨ (���� sprintf(str,"%05d%05d",i,i*n))���÷�
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int maxn = 100 + 10;
using namespace std;

int main(){
    int n,kase = 0;
    char s[20];
    while(scanf("%d",&n) != EOF && n != 0){
        if(kase++)printf("\n");//�Ҿ���徵����
        int cnt = 0;
        for(int i = 1234;; i++){
            sprintf(s,"%05d%05d",i,i*n);//��������÷�
            if(strlen(s) > 10)break;
            sort(s,s+10);
            bool flag = true;
            for(int i = 0; i < 10; i++) if(s[i] - '0' != i){flag = false;break;}
            if(flag){
                cnt++;
                printf("%05d / %05d = %d\n",i*n,i,n);
            }
        }
        if(!cnt)printf("There are no solutions for %d.\n",n);
    }
    return 0;
}

