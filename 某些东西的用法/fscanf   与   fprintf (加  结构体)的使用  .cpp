//fscanf  与  fprintf()


#include <stdio.h>
#include<stdlib.h>
struct student_type{
    char name[10];
    int num;
    int age;
    char addr[15];
} wang[20];

void display(){
    FILE *fp;
    int  i = 0,SIZE = 0;
    if((fp = fopen("in.txt","rt")) == NULL){
        printf("cannot open file\n");
        return;
    }
    while(fscanf(fp,"%s%d%d%s",wang[i].name,&wang[i].num,&wang[i].age,wang[i].addr)!=EOF){//用文件指针（fp*）从文件输入，而stdin是从键盘输入
        i++;
        SIZE++;
    }
    while(fscanf(stdin,"%s%d%d%s",wang[i].name,&wang[i].num,&wang[i].age,wang[i].addr)!=EOF){//stdin是从键盘输入
        i++;
        SIZE++;
    }
    fclose(fp);
    for(i = 0; i < SIZE; i++)
        printf("%-10s %4d %4d %-15s\n",wang[i].name, wang[i].num,wang[i].age,wang[i].addr);
}

int main(){
    display();
    return 0;
}
