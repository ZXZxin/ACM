//fscanf(stdin,"%d",&a)  stdin �� fp
//fprintf(stdout,"%d",a)  stdout �� fp

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
    fscanf(stdin,"%s%d",s,&a);         //�Ӽ�������һ���ַ���һ����
    fprintf(in,"%s %d",s,a);              //д�뵽��ָ���ļ���
    fclose(in);
    if((in = fopen("in.txt","r")) == NULL){
        puts("can't open file");
        exit(0);
    }
    if((out = fopen("out.txt","w")) == NULL){
        puts("can't open file");
        exit(0);
    }
    fscanf(in,"%s%d",c,&b);            //��fpָ����ļ��ж���
    fprintf(stdout,"%s %d",c,b);          //��ӡ����ʾ��
    fprintf(out,"%s %d",c,b);
    fclose(in);
}
