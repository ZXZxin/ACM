//fp = fopen("in.txt"),"a"(在文件末尾写入方式)

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
    fputc('k',fp); //在文件尾部写入字符k
    fputc('k',fp); //在文件尾部写入字符k
    fputc('k',fp); //在文件尾部写入字符k
    fputc('k',fp); //在文件尾部写入字符k
    fclose(fp);
    return 0;
}
