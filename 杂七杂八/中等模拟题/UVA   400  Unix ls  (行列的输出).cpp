//��Ŀ���ӣ�https://vjudge.net/contest/77100#problem/H
//��Ŀ���⣺����n���ַ�����Ҫ�㰴���ֵ��������е�˳�����������Ҫ��������60-���ַ��У�ȡ������ַ��������һ�����ĳ���M
            //�������һ�У�ÿһ��ռM+2���У����һ��ռM��
//����˼·���ؼ����ڼ��������У��Լ������������

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

const int maxn = 100+10;

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    while(cin>>n){
        int a[maxn];
        string s[maxn];
        int max_lenght = 0;
        for(int i = 0; i < n; i++){
            cin>>s[i];
            max_lenght = max(max_lenght,(int)s[i].length());
        }
        sort(s,s+n);
        int cols = (60 - max_lenght)/(max_lenght+2) + 1;//����
        int rows = (n - 1)/cols + 1; //����
        for(int i = 0; i < 60; i++)cout<<"-";cout<<endl;
        for(int i = 0; i < rows; i++){  //��������
            for(int j = 0; j < cols; j++){   //ÿ�����
                if((i + rows*j) < n) cout<<s[i + rows*j];  //�ؼ�
                if(j == cols - 1){   //���һ��
                    for(int k = 0; k < max_lenght - s[i+rows*j].length(); k++)cout<<' ';
                }
                else {
                    for(int k = 0; k < max_lenght + 2 - s[i+rows*j].length(); k++)cout<<' ';
                }
            }
            cout<<endl;  //���һ��֮����
        }
    }
    return 0;
}
