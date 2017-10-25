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
    //cout<<"������������һ����,������0����"<<endl;
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
   //cout<<"������������һ����,������0����"<<endl;
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

linklist delx(linklist head, datatype x){//ɾ����һ��Ϊx��
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
    //���α������Ա�L,�������ָ�뷴ת
    linklist pre,p=head->next,r=p->next;
    p->next=NULL;  //�����һ�����
    while(r!=NULL) {  //rΪ�գ���˵��pΪ���һ�����
        pre=p;  //���μ�������
        p=r;
        r=r->next;
        p->next=pre;  //ָ�뷴ת
    }
    head->next=p;  //�������һ�����
    return head;
}


linklist insert1(linklist head,datatype x){//���Ѿ�����ĵ��������
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


linklist delallx(linklist head,datatype x){//ɾ�����е�x
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
            q = (linklist)malloc(sizeof(node));//����ʡ����һ����������һ��Ҫд��q = p->next(��Ϊ�����Ļ�p�Ͳ�Ҫ���¸��ռ�)
            p->next = q;
            p->next = q->next;
            free(q);
         }
          else p=p->next;
       }
    }
    return head;
}

linklist sort1(linklist head){//����ͷ���ĵ���������
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


linklist mergeAscend(linklist L1,linklist L2)//��������
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


linklist mergeDescend(linklist L1,linklist L2)//��������
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
       pb = L2->next;//��L2�ĵ�һ����ʼѰ�ҿ�����û��
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

//void partion1(linklist head)//����ͷ���ĵ�����head�е�����ֵΪ�����Ľ������������ǰ�棬����ֵΪż���Ľ�����������ĺ��档
//{
//    linklist p,q,s;
//    p = head->next;
//    s = (linklist)malloc(sizeof(node));
//    while(p->next){
//        if(p->next->info%2!=0){
//            q = p->next;//�ȴ���һ����ʱ���
//            s = q;
//            p->next = q->next;//ɾ��
//            q = p->next;//ѭ����һ��
//            s->next = head->next;//����ͷ��
//            head->next = head->next->next;
//        }
//        else {
//            p = p->next;
//        }
//    }
//}

linklist search(linklist head,int k)//�þ����ܿ�ķ������ش�ͷ��㵥�����е�����k�����ĵ�ַ����������ڣ��򷵻�NULL��
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
    cout<<"��ܰ��ʾ�������ڴ�������Ĺ����У����붼��0����:"<<endl<<endl;
    datatype x1,x2,x3;
    cout<<"������һ�����ݣ�����һ��������:"<<endl;
    head1 = creat2();
    cout<<"����֮��ĵ������������ģ�"<<endl;
    print(head1);
    cout<<endl;
    //head2 = creat2();
    cout<<"������һ��Ҫɾ����������������ӵ�������ɾ��: "<<endl;
    cin>>x1;
    head1 = delx(head1,x1);
    print(head1);
    cout<<endl;
    cout<<"��������ת"<<endl;
    head1 = reverse1(head1);
    print(head1);
    cout<<endl;
    cout<<"�������������� ��"<<endl;
    head1 = sort1(head1);
    print(head1);
    cout<<endl;
    cout<<"����һ���������Ѿ�����������в���һ���� :"<<endl;
    cin>>x2;
    insert1(head1,x2);
    print(head1);
    cout<<endl;
    cout<<"������������е�����ȫ���Ƶ�ǰ�棬��ż���Ƶ����� ��"<<endl;
    partion(head1);
    print(head1);
    cout<<endl;
    cout<<"����һ���������������ӵ�����ĵ����������ʼ�����������: "<<endl;
    cin>>x3;
    head2 = search(head1,x3);
    print(head2);
    cout<<endl;
    cout<<"************************(���ǵ�Ư���ָ���)"<<endl;
    cout<<endl;
    cout<<"�ٴ���һ���ֵ�����,�������˳��ʹ�����˳���෴��"<<endl;

    head3 = creat1();
    cout<<"���������������: "<<endl;
    print(head3);
    cout<<endl;

    cout<<"��������������������� ��"<<endl;

    head1 = sort1(head1);
    cout<<"��һ�������������ģ�"<<endl;
    print(head1);
    cout<<"�ڶ���������������: "<<endl;
    sort1(head3);
    print(head3);
    cout<<endl;

    cout<<"����������ϲ��� ���Ϊ��"<<endl;
    head5 = mergeAscend(head1,head3);
    print(head5);
    cout<<"*******************"<<endl;
    cout<<endl;
    cout<<"���������������ݣ����붼��0���������������ǵĽ�����"<<endl;
    head6 = creat1();
    head7 = creat1();
    cout<<"������������ֱ��ǣ�"<<endl;
    print(head6);
    print(head7);
    cout<<"ȡ������������Ľ���Ϊ: "<<endl;
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
    //cout<<"������Ҫ�����ֵ"<<endl;
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












