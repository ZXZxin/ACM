//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=2648
//��Ŀ���⣺�кܶ��̵꣬������Ʒ��ÿ���̵�ļ�Ǯ����һ��������ÿ�������Ʒ�ļ�Ǯ�������ӣ�
            //Ҫ��һ���С�memory���̵���������Ʒ�۸��������̵������ڵڼ�λ���۸�Խ������Խǰ��
//����˼·���������õĹ�ϣ��˼�룬��ÿ���̵����±��Ӧ������Ȼ���� hash���� ����Ӧ��ֵ������Ȼ��Ƚϣ�hash���������!

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

const int maxn = 10000 + 10;
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    int n,m,a;
    string s;
    int Hash[maxn];
    map<string,int>dict;
    while(scanf("%d",&n) != EOF){
        dict.clear();
        int maxx = 0;
        for(int i = 0; i < n; i++){
            cin>>s;
            dict[s] = i;//ÿ���ַ���Ӧһ�� �±�ֵ
            if(s == "memory")maxx = i;
        }
        memset(Hash,0,sizeof(Hash));
        scanf("%d",&m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin>>a>>s;
                Hash[dict[s]] += a;  //��ÿ���ַ����� ��Ӧ�ļ۸� ��Ӧ����
            }
            int sum = 0;
            for(int j = 0; j < n; j++)if(Hash[j] > Hash[maxx])sum++;
            printf("%d\n",sum + 1);
        }
    }
    return 0;
}
