//��Ŀ���� : http://acm.hdu.edu.cn/showproblem.php?pid=2648
//��Ŀ���� : ��Ŀ����:�кܶ��̵꣬������Ʒ��ÿ���̵�ļ�Ǯ����һ��������ÿ�������Ʒ�ļ�Ǯ�������ӣ�
            //Ҫ��һ���С�memory���̵���������Ʒ�۸��������̵������ڵڼ�λ���۸�Խ������Խǰ��
//����˼· : ������hash�������һЩ��������Ϥһ�� map���÷�,һ��ʼû��ע�⵽�� ��Ǯ������ wa�˺ü��Σ�ע��mapÿ��ʹ��ʱclearһ��

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    int n,m,a;
    string s;
    map<string,int>dict;
    while(scanf("%d",&n) != EOF){
        dict.clear();
        for(int i = 0; i < n; i++){
            cin>>s;
            dict[s] = 0;
        }
        scanf("%d",&m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin>>a>>s;
                dict[s] += a;
            }
            map<string,int>::iterator it;
            int sum = 0;
            for(it = dict.begin(); it != dict.end(); it++){
                if(it->second > dict["memory"])sum++;  //ע�� map���÷� ->first,->second,�Լ� ֱ�� dict["memory"]���÷�
            }
            printf("%d\n",sum + 1);
        }
    }
    return 0;
}
