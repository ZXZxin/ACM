//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=1496
//��Ŀ����: ����Ҫ����  a*x1^2+b*x2^2+c*x3^2+d*x4^2=0  �� ��ĸ��� ���� a,b,c,d��ע�����ǵķ�Χ
//����˼·: ֱ�ӱ����϶���ʱ�������Ŀ�Ľⷨ �� ���ù�ϣ��˼�룬�о���ϣ��˼����ĺ�����!

#include <iostream>
#include <stdio.h>
#include <string.h>

const int M = 2000000;  // 50 * 100^2 * 4
using namespace std;
int Hash[M + 3];  //���ִ������һ��Ҫ����ȫ�ֱ�������Ȼ�������ױ���

int main(){
    //freopen("in.txt","r",stdin);
    int a,b,c,d,sum,s[100+10];
    while(scanf("%d%d%d%d",&a,&b,&c,&d) != EOF){
        if((a>0 && b>0 && c>0 && d>0)||(a<0 && b<0 && c<0 && d<0)){printf("0\n");continue;} //��Ϊx������Զ������
        sum = 0;
        memset(Hash,0,sizeof(Hash));
        for(int i = 1; i <= 100; i++)s[i] = i*i;
        for(int i = 1; i <= 100; i++){   //�ֳ� 2�� ���ȼ��� a*s[i] + b*s[j] Ȼ�󽫶�Ӧ���±�ĸ����浽Hash����
            for(int j = 1; j <= 100; j++){
                Hash[a*s[i] + b*s[j] + M/2]++;  //��ֹ�±��Ǹ��� ���Լ��� (50 * 100^2 * 4)/2
            }
        }
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <= 100; j++){
                sum += Hash[-(c*s[i] + d*s[j]) + M/2];  //���������Ǵ�Ķ�Ӧ��һ����ĸ���
            }
        }
        printf("%d\n",sum*16); //��Ϊ x ��ƽ����������������ƽ����һ����һ��x�ͻ����������ˣ�4��x��Ȼ���� 2^4=16 ���
    }
    return 0;
}
