//��feof(in)��ʹ��

#include <stdio.h>//�����Ƶ��ı�
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
    while(!feof(in)) //�����Ƶ��ı������жϽ������൱��ASCII���е�EOF
        fputc(fgetc(in), out);
    fclose(in);
    fclose(out);
}
