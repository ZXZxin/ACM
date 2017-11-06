//stringstream的使用示范

#include <iostream>
#include <stdio.h>
#include <set>
#include <sstream>

using namespace std;

int main(){
    string line;
    int sum = 0;
    while(getline(cin,line)){//ctrl+Z读取结束(文件结尾)
        int x;
        stringstream ss(line);
        while(ss>>x)sum += x;//这里的x定义的是什么类型就读取什么类型
    }
    cout<<sum<<endl;
    return 0;
}
