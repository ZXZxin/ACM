//FILE�ļ�ָ���ʹ��
//ch = fets(fp)��ʹ��
//putc(ch,fp)��ʹ��
//fopen��fclose��ʹ��

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
        putc(ch,in);//�����ļ���
        putchar(ch);//�������ʾ��
        ch = getchar();
    }
    fclose(in);
    printf("\n\n");
    if((in = fopen(filename,"r")) == NULL){
        printf("cannot open file\n");
        exit(0);
    }
    while((ch = fgetc(in)) != EOF){   //���ļ���ȡһֱ���ļ�����
        putchar(ch);
    }
    fclose(in);
    return 0;
}


