//string 中find 函数的使用

#include <string>
#include <iostream>
using namespace std;
int main()
{
    string s("1a2b3c4d5e6f7g8h9i1a2b3c4d5e6f7g8ha9i"); //string 类型赋常量
    string::size_type position;       //也可以是int position//find函数返回类型 size_type
    position = s.find("ha9i");        //find 函数 返回"ha9i"在s 中的下标位置
    if (position != s.npos)           //如果没找到，返回一个特别的标志c++中用npos表示，我这里npos取值是4294967295，
        cout << "position is : " << position << endl;
    else
        cout << "Not found the flag"<<endl;


    position=s.find("b",5);          //从字符串s 下标5开始，查找字符串b ,返回b 在s 中的下标
    cout<<"s.find(b,5) is : "<<position<<endl;


    string flag = "a";
    position = s.find_first_of(flag);    //返回flag首次在s中首次出现的地方
    cout<<"The string flag first show at "<<position<<endl;


    //查找s 中flag 出现的所有位置。
    int i=1;
    while((position = s.find_first_of(flag,position)) != string::npos)
    {
        //position=s.find_first_of(flag,position);
        cout<<"position  "<<i<<" : "<<position<<endl;
        position++;
        i++;
    }


    //查找flag 中与s 第一个不匹配的位置
    flag="acb12389efgxyz789";
    position = flag.find_first_not_of (s);
    cout<<"flag.find_first_not_of (s) :"<<position<<endl;


    //反向查找，flag 在s 中最后出现的位置
    flag = "3";
    position=s.rfind (flag);
    cout<<"s.rfind (flag) :"<<position<<endl;
return 0;
}
