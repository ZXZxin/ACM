//string ��find ������ʹ��

#include <string>
#include <iostream>
using namespace std;
int main()
{
    string s("1a2b3c4d5e6f7g8h9i1a2b3c4d5e6f7g8ha9i"); //string ���͸�����
    string::size_type position;       //Ҳ������int position//find������������ size_type
    position = s.find("ha9i");        //find ���� ����"ha9i"��s �е��±�λ��
    if (position != s.npos)           //���û�ҵ�������һ���ر�ı�־c++����npos��ʾ��������nposȡֵ��4294967295��
        cout << "position is : " << position << endl;
    else
        cout << "Not found the flag"<<endl;


    position=s.find("b",5);          //���ַ���s �±�5��ʼ�������ַ���b ,����b ��s �е��±�
    cout<<"s.find(b,5) is : "<<position<<endl;


    string flag = "a";
    position = s.find_first_of(flag);    //����flag�״���s���״γ��ֵĵط�
    cout<<"The string flag first show at "<<position<<endl;


    //����s ��flag ���ֵ�����λ�á�
    int i=1;
    while((position = s.find_first_of(flag,position)) != string::npos)
    {
        //position=s.find_first_of(flag,position);
        cout<<"position  "<<i<<" : "<<position<<endl;
        position++;
        i++;
    }


    //����flag ����s ��һ����ƥ���λ��
    flag="acb12389efgxyz789";
    position = flag.find_first_not_of (s);
    cout<<"flag.find_first_not_of (s) :"<<position<<endl;


    //������ң�flag ��s �������ֵ�λ��
    flag = "3";
    position=s.rfind (flag);
    cout<<"s.rfind (flag) :"<<position<<endl;
return 0;
}
