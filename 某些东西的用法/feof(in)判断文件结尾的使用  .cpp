//！feof(in)的使用

#include <stdio.h>//二进制的文本
#include<stdlib.h>
main()
{
    FILE  *in,  *out;
    char ch,infile[10], outfile[10];
    scanf("%s",infile);
    scanf("%s",outfile);
    if ((in = fopen(infile, "r"))== NULL){
        printf("Cannot open infile.\n");
        exit(0);
    }
    if ((out = fopen(outfile, "w"))== NULL){
        printf("Cannot open outfile.\n");
        exit(0);
    }
    while(!feof(in)) //二进制的文本输入判断结束，相当于ASCII码中的EOF
        fputc(fgetc(in), out);
    fclose(in);
    fclose(out);
}
