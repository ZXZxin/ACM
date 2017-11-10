//计算方法实验：矩阵相乘以及文件输入输出

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
const int M = 2;
const int N = 2;
const int L = 2;

int a[M][L],b[L][N],c[M][N];

int main(){
    FILE *in,*out;
    if((in = fopen("in.txt","r")) == NULL){cout<<"Cannot open the file"<<endl;exit(0);}
    if((out = fopen("out.txt","w")) == NULL){cout<<"Cannot open the file"<<endl;exit(0);}
    for(int i = 0; i < M; i++){
        for(int j = 0; j < L; j++){
            //cin>>a[i][j];
            fscanf(in,"%d",&a[i][j]);
        }
    }
    for(int i = 0; i < L; i++){
        for(int j = 0; j < N; j++){
            //cin>>b[i][j];
            fscanf(in,"%d",&b[i][j]);
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            c[i][j] = 0;
            for(int k = 0; k < L; k++)c[i][j] += a[i][k] * b[k][j];
            cout<<c[i][j]<<" ";
            fprintf(out,"%d ",c[i][j]);
        }
        cout<<endl;
        fprintf(out,"\n");
    }
    return 0;
}
