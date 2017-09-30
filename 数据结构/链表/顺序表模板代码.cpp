//˳���ģ�����

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
    void SLCreat(int n);//����˳���
    void SLInsert(int i,DataType x);//��˳��� L �еĵ� i ��λ�ò�������Ԫ�� x
    void SLDelete(int i); //��˳��� L �еĵ� i ��λ��ɾ������Ԫ��
    DataType SLGet(int i); //��ȡ�� i ��λ�õ�Ԫ��λ��
    DataType SLSum();//���
    int SLIsEmpty();//�ж�˳����Ƿ�Ϊ��
    void SLPrint();//��˳�����ʾ����Ļ��
};
//����˳���
void SeqList::SLCreat (int n)
{
    DataType x;
    cout<<"����������Ԫ��ֵ: ";
    for(int i=0; i<n; i++)
    {
        cin>>x;
        list[i]=x;
        length++;
    }
}
//��˳��� L �е� i λ�ò�������Ԫ�� x
void SeqList::SLInsert (int i,DataType x)
{
    int k;
    if(length>=MaxSize)
        cout<<"������,�޷�����!"<<endl;
    else if(i<0||i>length)
        cout<<"���� i ������!"<<endl;
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
//ɾ���� i ��λ�õ�����Ԫ��
void SeqList::SLDelete (int i)
{
    int k;
    if(!SLIsEmpty())
        cout<<"���ѿ�,�޷�ɾ��!"<<endl;
    else if(i<0||i>length)
        cout<<"���� i ������!"<<endl;
    else
    {
        for(k=i-1; k<length; k++)
            list[k]=list[k+1];
        length--;
    }
}
//��ȡ�� i ��λ�õ�Ԫ�ص���ֵ
DataType SeqList::SLGet (int i)
{
    if (i<0||i>length)
    {
        cout<<"���� i ������!"<<endl;
        return 0;
    }
    else
        return list[i-1];
}
//�ж�˳����Ƿ�Ϊ��
int SeqList::SLIsEmpty ()
{
    if(length<=0)return 0;
    else return 1;
}
//��˳�����ʾ����Ļ��
void SeqList::SLPrint ()
{
    if(!SLIsEmpty())
        cout<<"�ձ�!"<<endl;
    else
        for(int i=0; i<length; i++)
            cout<<list[i]<<" ";
    cout<<endl;
}
//���
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
    cout<<" 1.����˳���\n";
    cout<<" 2.��� i ��λ���ϵ���ֵ\n";
    cout<<" 3.�ڵ� i ��λ��ǰ�ϲ�����ֵԪ�� x\n";
    cout<<" 4.ɾ���� i ��λ���ϵ���ֵ\n";
    cout<<" 5.��˳����ϸ�Ԫ��֮��\n";
    cout<<" 6.�����ʾ\n";
    cout<<" 7.�˳�\n";
    cout<<"�ر�˵��:��һ����ѡ�� 1,�Ժ�Ͳ�Ҫѡ�� 1 ��!"<<endl;
    while(flag)
    {
        cout<<"��ѡ��: ";
        cin>>select;
        switch(select)
        {
        case 1:
            cout<<"������˳�����:";
            cin>>n;
            mylist.SLCreat(n);
            cout<<"˳���Ϊ�� ";
            mylist.SLPrint();
            break;
        case 2:
            cout<<"������λ�� i: ";
            cin>>i;
            cout<<"��"<<i<<"��λ���ϵ���ֵΪ: "<<mylist.SLGet (i)<<endl;
            break;
        case 3:
            cout<<"������Ҫ����Ԫ�ص�λ�� i ����ֵ x: ";
            cin>>i>>x;
            mylist.SLInsert (i,x);
            mylist.SLPrint ();
            break;
        case 4:
            cout<<"������Ҫɾ������ֵ��λ��: ";
            cin>>i;
            mylist.SLDelete (i);
            cout<<"ɾ�����˳���Ϊ: ";
            mylist.SLPrint ();
            break;
        case 5:
            cout<<"��͵�ֵ��"<<mylist.SLSum()<<endl;
            break;
        case 6:
            cout<<"˳���Ϊ: ";
            mylist.SLPrint ();
            break;
        case 7:
            flag=0;
            break;
        }
    }
    return 0;
}

//�����㷨
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
    scanf(��%d��,&n);
    create_sq_list(n,list);
    scanf(��%d,%d��,&i,&x);
    m=sq_ins(list,&n,i,x);
    if(m==1) printf(��i error��);
    if(m==2) printf(��Overflow��);
    if(m==0) printf(��ins success��);
    for(i=0; i<n; i++)
        printf(��%d��,list[i])
}*/
//ɾ���㷨
/*int sq_del(elemtype list[],int *pn,int i)
{
    int j;
    if (i<0||i>*pn) return(1);
    for(j=i+1; j<*pn; j++)
        list[j-1]=list[j];
    (*pn)--;
    return(0);
}*/
