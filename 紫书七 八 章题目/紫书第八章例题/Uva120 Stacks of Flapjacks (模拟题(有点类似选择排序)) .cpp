//��Ŀ���� : https://vjudge.net/contest/173113#problem/A
//��Ŀ���� : ���Ǹ���һ����,Ҫ�㾭��һϵ�еķ�ת,��ʹ�ô��ϵ��´�С��������,�������
        //  ��ת�Ĺ������ĳ��������ϵ�ȫ����ת����,�����������,�������3,1
/*8 7 2
  4 6 5
  6 4 8
  7 8 4
  5 5 6
  2 2 7
*/
//����˼· : ���µ�������ѡ����,����������,���Ȱ�ʣ�µ������Ƶ����
            //Ȼ�����ƶ���ѡ��������Ǹ�λ��,�е�ѡ�������˼��
/*
    8 2 7 4 6 5 4 2
    4 5 5 6 4 2 2 4
    6 7 2 2 2 4 5 5
    7 6 6 5 5 6 6 6
    5 4 4 7 7 7 7 7
    2 8 8 8 8 8 8 8
����: 1 4 2 5 3 4 5
*/
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
const int maxn = 100 + 10;

bool is_Sort(int *a,int n){
    for(int i = 0; i < n-1; i++)if(a[i] > a[i+1])return false;
    return true;
}

int main(){
    int a[maxn],n;
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        int n = 0;
        while(ss>>a[n])n++;
        int ans[maxn],len = 0; //��¼���
        for(int i = n-1; i >= 0; i--){
            if(is_Sort(a,n))break;
            int maxi = i,maxx = a[i],tmp;
            for(int j = i; j >= 0; j--)if(a[j] > maxx) { maxi = j; maxx = a[j]; }
            if(maxi == i)continue;
            if(maxi == 0){
                for(int k = 0; k < (i+1)/2 ;k++){tmp = a[k]; a[k] = a[i-k]; a[i-k] = tmp;}
                ans[len++] = n-i;
            }else {
                for(int k = 0; k < (maxi+1)/2; k++){tmp = a[k]; a[k] = a[maxi-k]; a[maxi-k] = tmp;}
                ans[len++] = n-maxi;
                for(int k = 0; k < (i+1)/2 ;k++){tmp = a[k]; a[k] = a[i-k]; a[i-k] = tmp;}
                ans[len++] = n-i;
            }
        }
        cout<<s<<endl;
        if(len != 0){
            for(int i = 0; i < len; i++)printf("%d ",ans[i]);
            printf("0\n");
        }else printf("0\n");
    }
    return 0;
}

