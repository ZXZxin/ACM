//fscanf(stdin,"%d",&a)  stdin 与 fp
//fprintf(stdout,"%d",a)  stdout 与 fp

#include <stdio.h>
#include <stdlib.h>
main()
{
    char s[80],c[80];
    int a,b;
    FILE *in,*out;
    if((in = fopen("in.txt","w"))==NULL){
        puts("can't open file");
        exit(0) ;
    }
    fscanf(stdin,"%s%d",s,&a);         //从键盘输入一串字符和一个数
    fprintf(in,"%s %d",s,a);              //写入到所指的文件中
    fclose(in);
    if((in = fopen("in.txt","r")) == NULL){
        puts("can't open file");
        exit(0);
    }
    if((out = fopen("out.txt","w")) == NULL){
        puts("can't open file");
        exit(0);
    }
    fscanf(in,"%s%d",c,&b);            //从fp指向的文件中读入
    fprintf(stdout,"%s %d",c,b);          //打印到显示屏
    fprintf(out,"%s %d",c,b);
    fclose(in);
}
