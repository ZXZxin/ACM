//fp = fopen("in.txt"),"a"(���ļ�ĩβд�뷽ʽ)

#include <stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char ch,*filename = "in.txt";
    if((fp = fopen(filename,"a")) == NULL){
        printf("cannot open file\n");
        exit(0);
    }
    fputc('k',fp); //���ļ�β��д���ַ�k
    fputc('k',fp); //���ļ�β��д���ַ�k
    fputc('k',fp); //���ļ�β��д���ַ�k
    fputc('k',fp); //���ļ�β��д���ַ�k
    fclose(fp);
    return 0;
}
