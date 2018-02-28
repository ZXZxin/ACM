//ѭ���ճ̱�����
//���η���Ӧ��
//ѧϰ����:http://blog.csdn.net/q547550831/article/details/51545284

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

int map[maxn][maxn];

// ��2^k*2^k�ı��ֳ�2^(k-1)*2^(k-1)���ĸ��ӱ��
// ÿ���������ϽǸ�ֵ
// �����ӱ����������ӱ�������ӱ����������ӱ��
// �����ӱ����������ӱ������ӱ���С
void circulateSchedule(int row,int col,int Size){
    if(Size == 1)return;
    int Half = Size / 2;
    map[row + Half][col + Half]= map[row][col];
    map[row + Half][col] = map[row][col + Half] = map[row][col] + Half;
    circulateSchedule(row,col,Half); //�ݹ��ĸ��ӱ��
    circulateSchedule(row,col+Half,Half);
    circulateSchedule(row+Half,col,Half);
    circulateSchedule(row+Half,col+Half,Half);
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        map[1][1] = 1;
        circulateSchedule(1,1,n);
        for(int i = 1; i <= n; i++){
            for(int j = 2; j <= n; j++){
                printf("%d  ",map[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
