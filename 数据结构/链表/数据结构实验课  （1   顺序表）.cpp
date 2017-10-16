#include  <stdio.h>
#include  <stdlib.h>
/**********************************/
/*˳����ͷ�ļ����ļ���sequlist.h*/
/**********************************/
#define MAXSIZE 100
typedef int datatype;
typedef struct
{
    datatype a[MAXSIZE];
    int size;
} sequence_list;

/**********************************/
/*�������ƣ�initseqlist()         */
/*�������ܣ���ʼ��˳���          */
/**********************************/
void initseqlist(sequence_list *L)
{
    L->size=0;
}
/**********************************/
/*�������ƣ�input()               */
/*�������ܣ�����˳���            */
/**********************************/
void input(sequence_list *L)
{
    datatype x;
    initseqlist(L);
    printf("������һ�����ݣ���0��Ϊ��������\n");
    scanf("%d",&x);
    while (x)
    {
        L->a[L->size++]=x;
        scanf("%d",&x);
    }
}
/**********************************/
/*�������ƣ�inputfromfile()       */
/*�������ܣ����ļ�����˳���      */
/**********************************/
void inputfromfile(sequence_list *L,char *f)
{
    int i,x;
    FILE *fp=fopen(f,"r");
    L->size=0;
    if (fp)
    {
        while ( ! feof(fp))
        {
            fscanf(fp,"%d",&L->a[L->size++]);
        }
        fclose(fp);
    }
}
/**********************************/
/*�������ƣ�print()               */
/*�������ܣ����˳���            */
/**********************************/
void print(sequence_list *L)
{
    int i;
    for (i=0; i<L->size; i++)
    {
        printf("%5d",L->a[i]);
        if ((i+1)%10==0) printf("\n");
    }
    printf("\n");
}



/**********************************/
/*�ļ����ƣ�lab1-01.c             */
/**********************************/
/*����sequlist.h�ж����˳�����д�㷨����reverse(sequence_list *L)��ʵ��˳���ľ͵ص��á�*/
/*�뽫���������������������в���*/
void reverse(sequence_list *L)
{
    for(int i=0; i<(L->size)/2; i++)
    {
        int temp;
        temp=L->a[i];
        L->a[i]=L->a[L->size-i-1];
        L->a[L->size-i-1]=temp;
    }
}
int main()
{
    sequence_list L;			/*����˳���*/
    input(&L);	        		/*�����������*/
    print(&L);                  /*���ԭ��*/
    reverse(&L);		            /*˳�����*/
    print(&L);                  /*����±�*/
}


/**********************************/
/*�ļ����ƣ�lab1_02.c             */
/**********************************/

/*��дһ���㷨����void sprit( sequence_list *L1,sequence_list *L2,sequence_list *L3)��
��˳���L1�е����ݽ��з��࣬������ŵ��浽˳���L2�У�ż���浽˳���L3�У���дmain()���в��ԡ�
*/
/*�뽫���������������������в���*/
void sprit(sequence_list *L1,sequence_list *L2,sequence_list *L3)
{
    initseqlist(L2);
    initseqlist(L3);
    int k=0;
    int k1=0;
    for(int i=0; i<L1->size; i++)
    {
        if((L1->a[i])%2!=0)L2->a[L2->size++]=L1->a[i];
        else L3->a[L3->size++]=L1->a[i];
    }
}
int main()
{
    sequence_list L1,L2,L3;		/*��������˳���*/
    input(&L1);				    /*����L1*/
    sprit(&L1,&L2,&L3);		    /*��L1���з���*/
    print(&L1);				    /*���L1��L2��L3*/
    print(&L2);
    print(&L3);
}




/*��֪˳���L1��L2��������С�����������þ����ܿ�ķ�����L1��L2�е����ݺϲ���L3�У�ʹ������L3�а��������С�*/
/*�뽫���������������������в���*/
void merge(sequence_list *L1,sequence_list *L2,sequence_list *L3)
{
    int i=0,j=0,r=0;
    while(L1->size-i&&L2->size-j)
    {
        if(L1->a[i]>L2->a[j])L3->a[r++]=L2->a[j++];
        else L3->a[r++]=L1->a[i++];
    }
    while(i<L1->size)L3->a[r++]=L1->a[i++];
    while(j<L2->size)L3->a[r++]=L2->a[j++];
    L3->size=r;
}
int main()
{
    sequence_list L1,L2,L3;
    input(&L1);				/*����ʱ��������������*/
    input(&L2);				/*����ʱ��������������*/
    merge(&L1,&L2,&L3);		/*�ϲ����ݵ�L3*/
    print(&L3);				/*���L3*/
}





/*����˳���la��lb�ֱ��������������ϣ�����inter(seqlist *la,seqlist *lb,seqlist *lc)
�Ĺ�����ʵ����˳���la��lb�Ľ�����ŵ�˳���lc��,�뽫������������.  */

/**********************************/
/*�ļ����ƣ�lab1_04.c                 */
/**********************************/
/*�뽫���������������������в���*/
void  inter(sequence_list *la,sequence_list *lb,sequence_list *lc)
{
    initseqlist(lc);
    for(int i=0; i<la->size; i++)
    {
        bool flag=true;
        for(int j=0; j<lb->size; j++)
        {
            if(la->a[i]==lb->a[j])
            {
                flag=false;
                continue;
            }
        }
        if(flag==false)lc->a[lc->size++]=la->a[i];
    }
}
int main()
{
    sequence_list la,lb,lc;
    inputfromfile(&la,"1.txt"); 		/*���ļ�1.txt����˳���*/
    inputfromfile(&lb,"2.txt");		/*���ļ�2.txt����˳���*/
    print(&la); 				 	    /*���la*/
    print(&lb);  				        /*���lb*/
    inter(&la,&lb,&lc);   		    /*��la��lb�Ľ�������lc��*/
    print(&lc); 					    /*���lc*/
    return 0;
}




/*
���дһ���㷨����partion(sequence_list *L)�������ܿ�ؽ�˳���L�е��������������������ߣ�
����ż������������ұߣ��������㷨��ʱ�临�Ӷȡ�
*/
/**********************************/
/*�ļ����ƣ�lab1_05.c                 */
/**********************************/
/*�뽫���������������������в���*/
void partion(sequence_list *L)
{
    int len = L->size;
    sequence_list Ltemp1;
    sequence_list Ltemp2;
    initseqlist(&Ltemp1);
    initseqlist(&Ltemp2);
    int i;
    for(i=0; i<len; i++)
    {
        if(L->a[i]%2)
        {
            Ltemp1.a[Ltemp1.size++] = L->a[i];
        }
        else
        {
            Ltemp2.a[Ltemp2.size++] = L->a[i];
        }

    }
    initseqlist(L);
    int len1 = Ltemp1.size;
    int len2 = Ltemp2.size;
    //int k = 0;
    for(i=0; i<len1; i++)
    {
        L->a[L->size++] = Ltemp1.a[i];
    }
    for(i=0; i<len2; i++)
    {
        L->a[L->size++] = Ltemp2.a[i];
    }
}
int main()
{
    sequence_list L;
    inputfromfile(&L,"3.txt");
    print(&L);  						/*�����L*/
    partion(&L);
    print(&L);  						/*����±�*/
    return 0;
}





/*
���дһ���㷨����partion(sequence_list *L)�������ܿ�ؽ�˳���L�е��������������������ߣ�
����ż������������ұߣ��������㷨��ʱ�临�Ӷȡ�
*/
/**********************************/
/*�ļ����ƣ�lab1_05.c                 */
/**********************************/
/*�뽫���������������������в���*/
void partion(sequence_list *L)
{
    for(int i=0; i<L->size-1; i++)
    {
        for(int j=0; j<L->size-1-i; j++)
        {
            if(L->a[j]%2==0&&L->a[j+1]%2!=0)
            {
                int temp;
                temp=L->a[j];
                L->a[j]=L->a[j+1];
                L->a[j+1]=temp;
            }
        }
    }
}
int main()
{
    sequence_list L;
    inputfromfile(&L,"3.txt");
    print(&L);  						/*�����L*/
    partion(&L);
    print(&L);  						/*����±�*/
    return 0;
}
