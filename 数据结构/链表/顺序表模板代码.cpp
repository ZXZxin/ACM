//顺序表模板代码

#include<iostream>
using namespace std;
#define MaxSize 25
typedef int DataType;
class SeqList
{
    DataType list[MaxSize];
    int length;
public:
    SeqList()
    {
        length=0;
    }
    void SLCreat(int n);//创建顺序表
    void SLInsert(int i,DataType x);//在顺序表 L 中的第 i 个位置插入数据元素 x
    void SLDelete(int i); //在顺序表 L 中的第 i 个位置删除数据元素
    DataType SLGet(int i); //获取第 i 个位置的元素位置
    DataType SLSum();//求和
    int SLIsEmpty();//判断顺序表是否为空
    void SLPrint();//将顺序表显示在屏幕上
};
//创建顺序表
void SeqList::SLCreat (int n)
{
    DataType x;
    cout<<"请输入数据元素值: ";
    for(int i=0; i<n; i++)
    {
        cin>>x;
        list[i]=x;
        length++;
    }
}
//在顺序表 L 中的 i 位置插入数据元素 x
void SeqList::SLInsert (int i,DataType x)
{
    int k;
    if(length>=MaxSize)
        cout<<"表已满,无法插入!"<<endl;
    else if(i<0||i>length)
        cout<<"参数 i 不合理!"<<endl;
    else
    {
        for(k=length; k>i; k--)
        {
            list[k]=list[k-1];
        }
        list[i]=list[i-1];
        list[i-1]=x;
        length++;
    }
}
//删除第 i 个位置的数据元素
void SeqList::SLDelete (int i)
{
    int k;
    if(!SLIsEmpty())
        cout<<"表已空,无法删除!"<<endl;
    else if(i<0||i>length)
        cout<<"参数 i 不合理!"<<endl;
    else
    {
        for(k=i-1; k<length; k++)
            list[k]=list[k+1];
        length--;
    }
}
//获取第 i 个位置的元素的数值
DataType SeqList::SLGet (int i)
{
    if (i<0||i>length)
    {
        cout<<"参数 i 不合理!"<<endl;
        return 0;
    }
    else
        return list[i-1];
}
//判断顺序表是否为空
int SeqList::SLIsEmpty ()
{
    if(length<=0)return 0;
    else return 1;
}
//将顺序表显示在屏幕上
void SeqList::SLPrint ()
{
    if(!SLIsEmpty())
        cout<<"空表!"<<endl;
    else
        for(int i=0; i<length; i++)
            cout<<list[i]<<" ";
    cout<<endl;
}
//求和
DataType SeqList::SLSum()
{
    int m=0;
    for(int i=0; i<length; i++)
    {
        m=m+list[i];
    }
    return m;
}
int main()
{
    SeqList mylist;
    int i,n,flag=1,select;
    DataType x;
    cout<<" 1.建立顺序表\n";
    cout<<" 2.求第 i 个位置上的数值\n";
    cout<<" 3.在第 i 个位置前上插入数值元素 x\n";
    cout<<" 4.删除第 i 个位置上的数值\n";
    cout<<" 5.该顺序表上各元素之和\n";
    cout<<" 6.输出显示\n";
    cout<<" 7.退出\n";
    cout<<"特别说明:第一次请选择 1,以后就不要选择 1 了!"<<endl;
    while(flag)
    {
        cout<<"请选择: ";
        cin>>select;
        switch(select)
        {
        case 1:
            cout<<"请输入顺序表长度:";
            cin>>n;
            mylist.SLCreat(n);
            cout<<"顺序表为： ";
            mylist.SLPrint();
            break;
        case 2:
            cout<<"请输入位置 i: ";
            cin>>i;
            cout<<"第"<<i<<"个位置上的数值为: "<<mylist.SLGet (i)<<endl;
            break;
        case 3:
            cout<<"请输入要插入元素的位置 i 和数值 x: ";
            cin>>i>>x;
            mylist.SLInsert (i,x);
            mylist.SLPrint ();
            break;
        case 4:
            cout<<"请输入要删除的数值的位置: ";
            cin>>i;
            mylist.SLDelete (i);
            cout<<"删除后的顺序表为: ";
            mylist.SLPrint ();
            break;
        case 5:
            cout<<"求和的值："<<mylist.SLSum()<<endl;
            break;
        case 6:
            cout<<"顺序表为: ";
            mylist.SLPrint ();
            break;
        case 7:
            flag=0;
            break;
        }
    }
    return 0;
}

//插入算法
/*int sq_ins(elemtype list[],int *pn,int i,elemtype x)
{
    int j;
    if (i<0||i>*pn) return(1);
    if(*pn==MAXSIZE) return(2);
    for(j=*pn; j>i; j--)
        list[j]=list[j-1];
    list[i]=x;
    (*pn)++;
    return(0);
}
#define MAXSIZE 100
elemtype list[MAXSIZE];
int n;
main()
{
    int i,n,x;
    scanf(“%d”,&n);
    create_sq_list(n,list);
    scanf(“%d,%d”,&i,&x);
    m=sq_ins(list,&n,i,x);
    if(m==1) printf(“i error”);
    if(m==2) printf(“Overflow”);
    if(m==0) printf(“ins success”);
    for(i=0; i<n; i++)
        printf(“%d”,list[i])
}*/
//删除算法
/*int sq_del(elemtype list[],int *pn,int i)
{
    int j;
    if (i<0||i>*pn) return(1);
    for(j=i+1; j<*pn; j++)
        list[j-1]=list[j];
    (*pn)--;
    return(0);
}*/
