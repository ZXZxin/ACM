//���̸������� : ���η���Ӧ��
//ѧϰ���� : http://blog.csdn.net/q547550831/article/details/51541527
//PS : �����е�ģ��

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

int map[maxn][maxn];
int num; //��¼�Ƶ����

void ChessBoard(int row,int col,int x,int y,int Size){ //����ÿһ�εݹ�ֽ��
    if(Size == 1)return ;
    int s = Size/2; // �԰뻮�ֳ�2^(size - 1) * 2^(size - 1)������
    int t = num++;  // L���Ʊ������
    // �м�㣬�Դ��б�(x,y)���ĸ���������
    int cenrow = row + s;
    int cencol = col + s;
    //// ��ɫ����������������
    if(x < cenrow && y < cencol){
        ChessBoard(row,col,x,y,s);
    }else {
        map[cenrow-1][cencol-1] = t; // ������������������̵����½�
        ChessBoard(row,col,cenrow-1,cencol-1,s); // Ȼ�󸲸��������ӣ�ע����ʱ(x,y)Ҫ���������λ��
    }
    //���Ͻ�
    if(x < cenrow && y >= cencol){
        ChessBoard(row,cencol,x,y,s);
    }else {
        map[cenrow-1][cencol] = t;
        ChessBoard(row,cencol,cenrow-1,cencol,s);
    }
    //���½�
    if(x >= cenrow && y < cencol){
        ChessBoard(cenrow,col,x,y,s);
    }else {
        map[cenrow][cencol-1] = t;
        ChessBoard(cenrow,col,cenrow,cencol-1,s);
    }
    //���½�
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
        printf("���̸��ǵ�˳����(0������Ǻ�ɫ������) : \n");
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
��������:
2 0 0
4 1 1
8 2 2
*/
