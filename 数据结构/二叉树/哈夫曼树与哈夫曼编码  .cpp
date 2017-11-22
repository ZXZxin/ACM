//�������������������

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct{//haffman ���Ľṹ
    unsigned int weight;//Ҷ�ӽ��Ȩֵ
    unsigned int parent; //ָ��˫�ף��ͺ��ӽ���ָ��
    unsigned int lChild;
    unsigned int rChild;
} Node, *HuffmanTree;

typedef char *HuffmanCode;//��̬�������飬�洢����������

//ѡ������parentΪ0����weight��С�Ľ��s1��s2�ķ���ʵ��
//n ΪҶ�ӽ���������s1�� s2����ָ�����ָ��Ҫѡȡ����������Ȩֵ��С�Ľ��
void select(HuffmanTree *huffmanTree, int n, int *s1, int *s2){
    int min;  //��¼��СȨֵ
    //����ȫ����㣬�ҳ����ڵ�
    for(int i = 1; i <= n; i++) if((*huffmanTree)[i].parent == 0){min = i; break;}
    //��������ȫ����㣬�ҳ�Ȩֵ��С�ĵ��ڵ�
    for(int i = 1; i <= n; i++)if((*huffmanTree)[i].parent == 0&&(*huffmanTree)[i].weight < (*huffmanTree)[min].weight) min = i;
    *s1 = min;    //�ҵ�����СȨֵ�Ľ�㣬s1ָ��
    //�ҳ���һ�����ڵ㣬��û�б� s1ָ����ôi ��ֵ�� min������ѭ��
    for(int i = 1; i <= n; i++)  if((*huffmanTree)[i].parent == 0 && i != (*s1)){ min = i;break;}
    for(int i = 1; i <= n; i++)if((*huffmanTree)[i].parent == 0 && i != (*s1)&&(*huffmanTree)[i].weight < (*huffmanTree)[min].weight)min = i;
    *s2 = min;    //s2ָ��ָ��ڶ���Ȩֵ��С��Ҷ�ӽ��
}

//���������������������������㷨���£�w��������֪��n��Ȩֵ
void createHuffmanTree(HuffmanTree *huffmanTree, int w[], int n)
{

    int m = 2 * n - 1;//m Ϊ���������ܹ��Ľ������n ΪҶ�ӽ����
    int s1,s2;//s1 �� s2 Ϊ������ǰ����Ҫѡȡ����СȨֵ�Ľ��
    *huffmanTree = (HuffmanTree)malloc((m + 1) * sizeof(Node));    // �������������Ľ������Ŀռ䣬m+1���������а���һ��ͷ���
    //1--n�Ŵ��Ҷ�ӽ�㣬��ʼ��Ҷ�ӽ�㣬�ṹ��������ʼ��ÿ��Ҷ�ӽ�㣬��ʼ��ʱ����һ�����������Ķ�����
    for(int i = 1; i <= n; i++){
        (*huffmanTree)[i].weight = w[i];//����Ҷ�ӽ���Ȩֵ�� w��n������������
        //��ʼ��Ҷ�ӽ�㣨���������������ĺ��Ӻ�˫�ף�������㣬Ҳ����û�к��Ӻ�˫�ף�==0
        (*huffmanTree)[i].lChild = 0;
        (*huffmanTree)[i].parent = 0;
        (*huffmanTree)[i].rChild = 0;
    }
    for(int i = n + 1; i <= m; i++){    //��Ҷ�ӽ��ĳ�ʼ��
        (*huffmanTree)[i].weight = 0;
        (*huffmanTree)[i].lChild = 0;
        (*huffmanTree)[i].parent = 0;
        (*huffmanTree)[i].rChild = 0;
    }

    printf("\n HuffmanTree: \n");
    for(int i = n + 1; i <= m; i++){    //������Ҷ�ӽ�㣬����������
        //��(*huffmanTree)[1]~(*huffmanTree)[i-1]�ķ�Χ��ѡ������parentΪ0��weight��С�Ľ�㣬����ŷֱ�ֵ��s1��s2
        select(huffmanTree, i-1, &s1, &s2);
        //ѡ��������Ȩֵ��С��Ҷ�ӽ�㣬���һ���µĶ���������Ϊ i ���
        (*huffmanTree)[s1].parent = i;
        (*huffmanTree)[s2].parent = i;
        (*huffmanTree)[i].lChild = s1;
        (*huffmanTree)[i].rChild = s2;
        (*huffmanTree)[i].weight = (*huffmanTree)[s1].weight + (*huffmanTree)[s2].weight; //�µĽ�� i ��Ȩֵ
        printf("%d (%d, %d)\n", (*huffmanTree)[i].weight, (*huffmanTree)[s1].weight, (*huffmanTree)[s2].weight);
    }
    printf("\n");
}

//��������������ϣ��� n ��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������
void creatHuffmanCode(HuffmanTree *huffmanTree, HuffmanCode *huffmanCode, int n){
    int start,p; //�������ʼָ���ָ��ǰ���ĸ��ڵ�
    unsigned int c; //���� n ��Ҷ�ӽ���ָʾ��� c
    huffmanCode=(HuffmanCode *)malloc((n+1) * sizeof(char *)); //����n�������ͷָ��
    char *cd = (char *)malloc(n * sizeof(char));   //������ǰ����Ĺ����ռ�
    cd[n-1] = '\0';  //����������λ��ű��룬���ȴ�ű��������
    for(int i = 1; i <= n; i++){   //��n��Ҷ�ӽ���Ӧ�Ĺ���������
        start = n - 1; //��ʼ��������ʼָ��
        for(c = i, p = (*huffmanTree)[i].parent; p != 0; c = p, p = (*huffmanTree)[p].parent){ //��Ҷ�ӵ�����������
            if( (*huffmanTree)[p].lChild == c)cd[--start] = '0';//���ҵ����˳����������������֧��0
            else cd[--start] = '1'; //�ҷ�֧��1
        }
        huffmanCode[i] = (char *)malloc((n - start) * sizeof(char)); //Ϊ��i���������ռ�
        strcpy(huffmanCode[i], &cd[start]);
    }
    free(cd);
    for(int i = 1; i <= n; i++) printf("HuffmanCode of %3d is %s\n", (*huffmanTree)[i].weight, huffmanCode[i]); //��ӡ��������
    printf("\n");
}

int main(void){
    HuffmanTree HT;
    HuffmanCode HC;
    int *w,n,wei,m;
    printf("\nn = " );
    scanf("%d",&n);
    w = (int *)malloc((n+1)*sizeof(int));
    printf("\ninput the %d element's weight:\n",n);
    for(int i = 1; i <= n; i++){
        printf("%d: ",i);
        fflush(stdin);  //��ջ�����
        scanf("%d",&wei);
        w[i] = wei;
    }
    createHuffmanTree(&HT, w, n);
    creatHuffmanCode(&HT,&HC,n);
    return 0;
}
