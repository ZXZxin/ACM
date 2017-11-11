//��Ŀ���ӣ�https://vjudge.net/contest/198250#problem/C
/*��Ŀ���⣺
    ����һ��ֻ����C��P���ַ�������ÿ�ο������������һ���ַ�
    ��k������ַ�Ҫ����k-1Ԫ
    ͳ���ַ�����CCPC��������ÿ��һ��CCPC��ͻ���1Ԫ
    ���������*/
/*����˼·��
    �����ֻ�����1�Σ���Ϊ��ÿ��������ֻ���һ��CCPC��Ҳ����׬��1�飬�ɵ�2�ο�ʼ�Ͳ�����˵ò���ʧ
    һ�۷�����������"CCC"��"CPC"��"CCP"����ӣ���+1��ֻ+һ�Σ�
    ������Ȼ���ԣ�����CCCPC���������CCC�м����һ��P�����CCPCPC��ԭ����CCPC��û��
    ���Ի�Ҫ�������Ƿ�Ӱ�쵽֮ǰ�Ѿ��е�CCPC
*/
#include <iostream>
#include <stdio.h>

using namespace std;
const int maxn = 200005+10;
char str[maxn];
bool flag[maxn];

int main(){
    int T,n;
    cin>>T;
    while(T--){
        int temp = 0,sum = 0;
        cin>>n;
        cin>>str;
        for(int i = 0; i < n; i++)flag[i] = false;
        for(int i = 0; i < n - 2; i++){
            if(str[i] == 'C'&&str[i+1] == 'C'&&str[i+2] == 'P'&&str[i+3] == 'C')
                sum++,flag[i] = true;
        }
        for(int i = 0; i < n-2; i++){
            if(flag[i])continue;
            if(str[i] == 'C'&&str[i+1] == 'C'&&str[i+2] == 'C'&&flag[i+1] == false)temp = 1;
            else if(str[i] == 'C'&&str[i+1] == 'P'&&str[i+2] == 'C'&&flag[i-1] == false)temp = 1;
            else if(str[i] == 'C'&&str[i+1] == 'C'&&str[i+2] == 'P')temp = 1;
        }
        cout<<sum + temp<<endl;
    }
    return 0;
}
