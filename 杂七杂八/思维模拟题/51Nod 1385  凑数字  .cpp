//��Ŀ���ӣ�http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1385
//��Ŀ���⣺���Ǹ��� һ������n������ Ҫ���ٸ�����( �� )������� 1 - n ����
//����˼·: ��һ����Ҫ����˼ά + ���� ������ֻҪ����λ����������ͬ���ߴﵽ10�Ĵη��������ż�1������������Ĺ���

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
char s[11000];

int main()
{
    scanf("%s",s);
    int len = strlen(s);
    int ans = (len-1)*10;
    int flag = 0;
    for(int i = 1; s[i] ; i++)
    {
        if(s[i] > s[0]){
            flag = 0;
            break;
        }
        else if(s[i] == s[0]) continue;
        else {
            flag = 1;
            break;
        }
    }
    printf("%d\n",ans + (s[0] - '0') - flag);
    return 0;
}
