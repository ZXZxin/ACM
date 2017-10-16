#include  <stdio.h>
#include  <stdlib.h>
/**********************************/
/*顺序表的头文件，文件名sequlist.h*/
/**********************************/
#define MAXSIZE 100
typedef int datatype;
typedef struct
{
    datatype a[MAXSIZE];
    int size;
} sequence_list;

/**********************************/
/*函数名称：initseqlist()         */
/*函数功能：初始化顺序表          */
/**********************************/
void initseqlist(sequence_list *L)
{
    L->size=0;
}
/**********************************/
/*函数名称：input()               */
/*函数功能：输入顺序表            */
/**********************************/
void input(sequence_list *L)
{
    datatype x;
    initseqlist(L);
    printf("请输入一组数据，以0做为结束符：\n");
    scanf("%d",&x);
    while (x)
    {
        L->a[L->size++]=x;
        scanf("%d",&x);
    }
}
/**********************************/
/*函数名称：inputfromfile()       */
/*函数功能：从文件输入顺序表      */
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
/*函数名称：print()               */
/*函数功能：输出顺序表            */
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
/*文件名称：lab1-01.c             */
/**********************************/
/*基于sequlist.h中定义的顺序表，编写算法函数reverse(sequence_list *L)，实现顺序表的就地倒置。*/
/*请将本函数补充完整，并进行测试*/
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
    sequence_list L;			/*定义顺序表*/
    input(&L);	        		/*输入测试用例*/
    print(&L);                  /*输出原表*/
    reverse(&L);		            /*顺序表倒置*/
    print(&L);                  /*输出新表*/
}


/**********************************/
/*文件名称：lab1_02.c             */
/**********************************/

/*编写一个算法函数void sprit( sequence_list *L1,sequence_list *L2,sequence_list *L3)，
将顺序表L1中的数据进行分类，奇数存放到存到顺序表L2中，偶数存到顺序表L3中，编写main()进行测试。
*/
/*请将本函数补充完整，并进行测试*/
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
    sequence_list L1,L2,L3;		/*定义三个顺序表*/
    input(&L1);				    /*输入L1*/
    sprit(&L1,&L2,&L3);		    /*对L1进行分类*/
    print(&L1);				    /*输出L1、L2和L3*/
    print(&L2);
    print(&L3);
}




/*已知顺序表L1，L2中数据由小到大有序，请用尽可能快的方法将L1与L2中的数据合并到L3中，使数据在L3中按升序排列。*/
/*请将本函数补充完整，并进行测试*/
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
    input(&L1);				/*输入时请输入有序数据*/
    input(&L2);				/*输入时请输入有序数据*/
    merge(&L1,&L2,&L3);		/*合并数据到L3*/
    print(&L3);				/*输出L3*/
}





/*假设顺序表la与lb分别存放两个整数集合，函数inter(seqlist *la,seqlist *lb,seqlist *lc)
的功能是实现求顺序表la与lb的交集存放到顺序表lc中,请将函数补充完整.  */

/**********************************/
/*文件名称：lab1_04.c                 */
/**********************************/
/*请将本函数补充完整，并进行测试*/
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
    inputfromfile(&la,"1.txt"); 		/*从文件1.txt建立顺序表*/
    inputfromfile(&lb,"2.txt");		/*从文件2.txt建立顺序表*/
    print(&la); 				 	    /*输出la*/
    print(&lb);  				        /*输出lb*/
    inter(&la,&lb,&lc);   		    /*求la与lb的交集存于lc中*/
    print(&lc); 					    /*输出lc*/
    return 0;
}




/*
请编写一个算法函数partion(sequence_list *L)，尽可能快地将顺序表L中的所有奇数调整到表的左边，
所有偶数调整到表的右边，并分析算法的时间复杂度。
*/
/**********************************/
/*文件名称：lab1_05.c                 */
/**********************************/
/*请将本函数补充完整，并进行测试*/
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
    print(&L);  						/*输出表L*/
    partion(&L);
    print(&L);  						/*输出新表*/
    return 0;
}





/*
请编写一个算法函数partion(sequence_list *L)，尽可能快地将顺序表L中的所有奇数调整到表的左边，
所有偶数调整到表的右边，并分析算法的时间复杂度。
*/
/**********************************/
/*文件名称：lab1_05.c                 */
/**********************************/
/*请将本函数补充完整，并进行测试*/
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
    print(&L);  						/*输出表L*/
    partion(&L);
    print(&L);  						/*输出新表*/
    return 0;
}
