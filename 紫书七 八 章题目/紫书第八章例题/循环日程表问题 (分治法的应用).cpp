//循环日程表问题
//分治法的应用
//学习博客:http://blog.csdn.net/q547550831/article/details/51545284

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

int map[maxn][maxn];

// 将2^k*2^k的表格分成2^(k-1)*2^(k-1)的四个子表格
// 每个表格的左上角赋值
// 左上子表格等于右下子表格，右上子表格等于左下子表格
// 右上子表格等于左上子表格加上子表格大小
void circulateSchedule(int row,int col,int Size){
    if(Size == 1)return;
    int Half = Size / 2;
    map[row + Half][col + Half]= map[row][col];
    map[row + Half][col] = map[row][col + Half] = map[row][col] + Half;
    circulateSchedule(row,col,Half); //递归四个子表格
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
