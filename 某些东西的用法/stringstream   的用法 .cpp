//stringstream��ʹ��ʾ��

#include <iostream>
#include <stdio.h>
#include <set>
#include <sstream>

using namespace std;

int main(){
    string line;
    int sum = 0;
    while(getline(cin,line)){//ctrl+Z��ȡ����(�ļ���β)
        int x;
        stringstream ss(line);
        while(ss>>x)sum += x;//�����x�������ʲô���;Ͷ�ȡʲô����
    }
    cout<<sum<<endl;
    return 0;
}
