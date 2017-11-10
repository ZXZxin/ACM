//FILE文件指针的使用
//ch = fets(fp)的使用
//putc(ch,fp)的使用
//fopen与fclose的使用

#include <stdio.h>
#include<stdlib.h>
int main()
{
    FILE *in;
    char ch,*filename="in.txt";
    if((in = fopen(filename,"w")) == NULL){
        printf("cannot open file\n");
        exit(0);
    }
    printf("Please input string:");
    ch = getchar();
    while(ch != '#'){
        putc(ch,in);//输入文件中
        putchar(ch);//输出在显示屏
        ch = getchar();
    }
    fclose(in);
    printf("\n\n");
    if((in = fopen(filename,"r")) == NULL){
        printf("cannot open file\n");
        exit(0);
    }
    while((ch = fgetc(in)) != EOF){   //从文件读取一直到文件结束
        putchar(ch);
    }
    fclose(in);
    return 0;
}


