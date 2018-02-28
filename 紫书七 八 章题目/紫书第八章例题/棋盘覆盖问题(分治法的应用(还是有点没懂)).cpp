//棋盘覆盖问题 : 分治法的应用
//学习博客 : http://blog.csdn.net/q547550831/article/details/51541527
//PS : 还是有点模糊

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

int map[maxn][maxn];
int num; //记录牌的序号

void ChessBoard(int row,int col,int x,int y,int Size){ //传入每一次递归分解的
    if(Size == 1)return ;
    int s = Size/2; // 对半划分成2^(size - 1) * 2^(size - 1)的棋盘
    int t = num++;  // L型牌编号自增
    // 中间点，以此判别(x,y)在哪个子棋盘中
    int cenrow = row + s;
    int cencol = col + s;
    //// 黑色方格在左上子棋盘
    if(x < cenrow && y < cencol){
        ChessBoard(row,col,x,y,s);
    }else {
        map[cenrow-1][cencol-1] = t; // 不在则填充左上子棋盘的右下角
        ChessBoard(row,col,cenrow-1,cencol-1,s); // 然后覆盖其他格子，注意这时(x,y)要看做已填充位置
    }
    //右上角
    if(x < cenrow && y >= cencol){
        ChessBoard(row,cencol,x,y,s);
    }else {
        map[cenrow-1][cencol] = t;
        ChessBoard(row,cencol,cenrow-1,cencol,s);
    }
    //左下角
    if(x >= cenrow && y < cencol){
        ChessBoard(cenrow,col,x,y,s);
    }else {
        map[cenrow][cencol-1] = t;
        ChessBoard(cenrow,col,cenrow,cencol-1,s);
    }
    //右下角
    if(x >= cenrow && y >= cencol){
        ChessBoard(cenrow,cencol,x,y,s);
    }else {
        map[cenrow][cencol] = t;
        ChessBoard(cenrow,cencol,cenrow,cencol,s);
    }
}


int main(){
    freopen("in.txt","r",stdin);
    int Size,x,y;
    while(scanf("%d",&Size) != EOF){
        scanf("%d%d",&x,&y);
        num = 1;
        map[x][y] = 0;
        ChessBoard(0,0,x,y,Size);
        printf("棋盘覆盖的顺序是(0代表的是黑色的棋盘) : \n");
        for(int i = 0; i < Size; i++){
            for(int j = 0; j < Size; j++){
                printf("%d\t",map[i][j]);
            }
            printf("\n\n");
        }
    }
    return 0;
}

/*
测试数据:
2 0 0
4 1 1
8 2 2
*/
