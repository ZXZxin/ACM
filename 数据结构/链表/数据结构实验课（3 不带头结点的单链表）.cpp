#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

typedef int datatype;

typedef struct link_node {
    datatype info;
    struct link_node *next;
}node;

typedef node *linklist;


linklist creat1(){
    linklist head,s;
    datatype x;
    head = (linklist)malloc(sizeof(node));
    head->next = NULL;
    //cout<<"请输入正整数一组数,输入以0结束"<<endl;
    cin>>x;
    while(x!=0){
        s = (linklist)malloc(sizeof(node));
        s->info = x;
        s->next = head->next;
        head->next = s;
        cin>>x;
    }
    return head;
}

linklist creat2(){
   linklist head,p,r;
   datatype x;
   head = r =(linklist)malloc(sizeof(node));
   head->next = NULL;
   //cout<<"请输入正整数一组数,输入以0结束"<<endl;
   cin>>x;
   while(x!=0){
    p = (linklist)malloc(sizeof(node));
    p->info = x;
    r->next = p;
    r = p;
    cin>>x;
   }
    r->next = NULL;
    return head;
}


void print(linklist head){
    linklist p;
    //cout<<"List is "<<endl;
    p = head->next;
    while( p!=NULL){
        cout<<p->info<<" ";
        p=p->next;
    }
    cout<<endl;
}

void deletes(linklist head){
    linklist p;
    p = head;
    while(p){
        head = p->next;
        free(p);
        p = head;
    }
}

linklist delx(linklist head, datatype x){//删掉第一个为x的
    linklist p,q;
    p = head->next;
    if(p->info == x){
        head = p->next;
        free(p);
        p = head;
    }
    while(p->next->info!=x)p=p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

linklist reverse1(linklist head){
    //依次遍历线性表L,并将结点指针反转
    linklist pre,p=head->next,r=p->next;
    p->next=NULL;  //处理第一个结点
    while(r!=NULL) {  //r为空，则说明p为最后一个结点
        pre=p;  //依次继续遍历
        p=r;
        r=r->next;
        p->next=pre;  //指针反转
    }
    head->next=p;  //处理最后一个结点
    return head;
}


linklist insert1(linklist head,datatype x){//给已经排序的单链表插入
    linklist p,q = NULL;
    p = head->next;
    q= (linklist)malloc(sizeof(node ));
    if(p->info>x){q->info = x;q->next = p;head->next = q;return head;}
    while(p->next){
       if(p->next->info>x)break;
        p=p->next;
    }
    if(!p->next){ q->info = x; q->next = NULL;p->next = q;return head;}
    q->info = x;
    q->next = p->next;
    p->next = q;
    return head;
}


linklist delallx(linklist head,datatype x){//删掉所有的x
    linklist p,q;
    while(head->next){
        if(head->next->info==x){
            p = head->next;
            head->next = head->next->next;
            free(p);
        }
        else break;
    }
    if(head->next){
       p=head->next;
       while(p->next){
         if(p->next->info==x){
            q = (linklist)malloc(sizeof(node));//可以省略这一步，但是下一步要写成q = p->next(因为这样的话p就不要重新赋空间)
            p->next = q;
            p->next = q->next;
            free(q);
         }
          else p=p->next;
       }
    }
    return head;
}

linklist sort1(linklist head){//给带头结点的单链表排序
    int temp;
    linklist p,pre;
    pre = p = head->next;
    while(pre){
        p = pre->next;
        while(p){
            if(pre->info>p->info){
                temp = pre->info;
                pre->info = p->info;
                p->info = temp;
            }
            p = p->next;
        }
        pre = pre->next;
    }
    return head;
}


linklist mergeAscend(linklist L1,linklist L2)//升序排列
{
    linklist L3,pc;
    L3 = (linklist)malloc(sizeof(node));
    linklist pa = L1->next;
    linklist pb = L2->next;
    pc = L3;
    while(pa&&pb){
        if(pa->info <= pb->info){
            pc->next = pa;pc = pa;pa = pa->next;
        }
        else {pc->next = pb;pc = pb;pb = pb->next;}
    }
    pc->next = pa?pa:pb;
    free(pb);
    return L3;
}


linklist mergeDescend(linklist L1,linklist L2)//降序排列
{
    linklist L3;
    L3 = mergeAscend(L1,L2);
    reverse1(L3);
    return L3;
}

linklist  interSection(linklist L1, linklist L2)
{
    linklist L3,pc,s;
    linklist pa = L1->next;
    linklist pb = L2->next;
    L3 = (linklist)malloc(sizeof(node));
    L3->next = NULL;
    pc = L3;
    while(pa){
       pb = L2->next;//从L2的第一个开始寻找看看有没有
       while(pb){
         if(pb->info==pa->info){pc->next = pa;pc = pa;pa = pa->next;break;}//s = (linklist)malloc(sizeof(node));s->info = pa->info; pc->next = s;pc = s;break;}
         pb = pb->next;
       }
    pa = pa->next;
    }
    pc->next = NULL;
    return L3;
}


void partion(linklist head)
{
    linklist p,s,pre;
    pre=head;
    p=head->next;
    while(p){
        if(p->info%2!=0){
            s=p;
            pre->next=p->next;
            p = pre->next;
            s->next=NULL;
            s->next=head->next;
            head->next=s;
        }
        else{
            pre=p;
            p=p->next;
        }
    }
}

//void partion1(linklist head)//将带头结点的单链表head中的所有值为奇数的结点调整到链表的前面，所有值为偶数的结点调整到链表的后面。
//{
//    linklist p,q,s;
//    p = head->next;
//    s = (linklist)malloc(sizeof(node));
//    while(p->next){
//        if(p->next->info%2!=0){
//            q = p->next;//先创建一个临时结点
//            s = q;
//            p->next = q->next;//删除
//            q = p->next;//循环下一次
//            s->next = head->next;//放置头部
//            head->next = head->next->next;
//        }
//        else {
//            p = p->next;
//        }
//    }
//}

linklist search(linklist head,int k)//用尽可能快的方法返回带头结点单链表中倒数第k个结点的地址，如果不存在，则返回NULL。
{
    linklist p,q,r;
    int num = 0;
    p = head->next;
    if(head == NULL )return NULL;
    while(p->next){p=p->next;num++;}
    if(num < k )return NULL;
    int i = 0;
    q = head->next;
    while(i<num-k){
        i++;
        q = q->next;
    }
    return q;
}

int main(){
    //freopen("in.txt","r",stdin);
    linklist head1,head2,head3,head4,head5,head6,head7;
    cout<<"温馨提示：以下在创建链表的过程中，输入都以0结束:"<<endl<<endl;
    datatype x1,x2,x3;
    cout<<"请输入一组数据，创建一个单链表:"<<endl;
    head1 = creat2();
    cout<<"创建之后的单链表是这样的："<<endl;
    print(head1);
    cout<<endl;
    //head2 = creat2();
    cout<<"请输入一个要删除的数，把这个数从单链表中删除: "<<endl;
    cin>>x1;
    head1 = delx(head1,x1);
    print(head1);
    cout<<endl;
    cout<<"将单链表反转"<<endl;
    head1 = reverse1(head1);
    print(head1);
    cout<<endl;
    cout<<"将链表排序如下 ；"<<endl;
    head1 = sort1(head1);
    print(head1);
    cout<<endl;
    cout<<"输入一个数，在已经排序的链表中插入一个数 :"<<endl;
    cin>>x2;
    insert1(head1,x2);
    print(head1);
    cout<<endl;
    cout<<"将这个单链表中的奇数全部移到前面，将偶数移到后面 ："<<endl;
    partion(head1);
    print(head1);
    cout<<endl;
    cout<<"输入一个数，这个数代表从单链表的倒数这个数开始，输出单链表: "<<endl;
    cin>>x3;
    head2 = search(head1,x3);
    print(head2);
    cout<<endl;
    cout<<"************************(我是的漂亮分割线)"<<endl;
    cout<<endl;
    cout<<"再创建一个兄弟链表,且输入的顺序和创建的顺序相反："<<endl;

    head3 = creat1();
    cout<<"这个链表是这样的: "<<endl;
    print(head3);
    cout<<endl;

    cout<<"把上面两个链表都排序并输出 ："<<endl;

    head1 = sort1(head1);
    cout<<"第一个链表是这样的："<<endl;
    print(head1);
    cout<<"第二个链表是这样的: "<<endl;
    sort1(head3);
    print(head3);
    cout<<endl;

    cout<<"将两个链表合并： 输出为："<<endl;
    head5 = mergeAscend(head1,head3);
    print(head5);
    cout<<"*******************"<<endl;
    cout<<endl;
    cout<<"请再输入两组数据，输入都以0结束，现在求他们的交集："<<endl;
    head6 = creat1();
    head7 = creat1();
    cout<<"这两个单链表分别是："<<endl;
    print(head6);
    print(head7);
    cout<<"取这两个单链表的交集为: "<<endl;
    head4 = interSection(head6,head7);
    print(head4);

    cout<<endl;

    cout<<endl<<endl<<endl;


    //head2 = sort1(head2);
    //head3 = mergeDescend(head1,head2);
    //print(head3);
    //head3 = interSection(head1,head2);
    //print(head3);
    //print(head1);

    //cin>>x1;

    //head = delallx(head2,x1);
     //print(head2);

    //print(head2);
    //cout<<"请输入要插入的值"<<endl;
    //cin>>x2;
    //head2 = insert1(head2,x2);
    //print(head2);
    //partion(head1);
//    head2 = search(head1,5);
//    print(head1);
//    partion(head1);
//    print(head1);


    return 0;
}












