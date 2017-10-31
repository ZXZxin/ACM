//ջ����е�Ӧ�ã���׺���ʽת��׺���ʽ�Լ���׺���ʽ�ļ���


//����ע�⣺������ʱ��ı䴫ֵ��ע���ˣ�74�д����÷��ţ�Pop��������



#include <stdio.h>
#include <iostream>
using namespace std;

const int maxn = 100;
const int stacksize = 100;
const int queuesize = 100;

typedef char datatype;

typedef struct{
    datatype data[queuesize];
    int front,rear;
}Seqqueue;

typedef struct{
    datatype data[stacksize];
    int top;
}SqStack;


void InitSeqqueue(Seqqueue &q){
    q.front = 0;
    q.rear = 0;
}

bool queueempty(Seqqueue &q){
    return q.rear==q.front;
}

void enqueue(Seqqueue &q,datatype x){
    if((q.rear+1)%queuesize == q.front){
        printf("queue overflow");
    }
    else {
        q.data[q.rear] = x;
        q.rear = (q.rear+1)%queuesize;
    }
}

char dequeue(Seqqueue &q){
    if(q.front == q.rear){
        printf("queue overflow");
        return '#';
    }
    else {
        char c = q.data[q.front];
        q.front = (q.front+1)%queuesize;
        return c;
    }
}
void InitStack(SqStack &s){
    s.top = -1;
}

void Push(SqStack &s,datatype x){
    if (s.top==stacksize-1) {
        printf("stack overflow");
    }
    else{
        s.top++;
        s.data[s.top] = x;
    }
}

void Pop(SqStack &s,datatype &x){
    if (s.top==-1) {
        printf("stack underflow");
    }
    else{
        x = s.data[s.top--];
    }
}

datatype Gettop(SqStack &s){
    if (s.top==-1) {
        printf("stack empty");
    }
    return s.data[s.top];
}

int priority(datatype op){
    switch(op){
    case '(':
    case ')':
    case '#':
        return (0);
    case '+':
    case '-':
        return (1);
    case '*':
    case '/':
        return (2);
    }
}

void ctpostexp(Seqqueue &q){//��׺���ʽת��׺���ʽ
    SqStack os;
    char c,t;
    InitStack(os);
    Push(os,'#');
    do{
        c = getchar();
        switch(c){
        case ' ':break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            enqueue(q,c);break;
        case '(':
            Push(os,c);break;
        case ')':
        case '#':
            do{
                Pop(os,t);
                if(t != '#'&&t != '(')
                enqueue(q,t);
            }while(t != '('&&os.top != -1);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while(priority(c) <= priority(Gettop(os))){
                Pop(os,t);
                enqueue(q,t);
            }
            Push(os,c);
            break;
        }
    }while(c != '#');
}

void print(Seqqueue &q){
    while(!queueempty(q)){
        printf("%c ",dequeue(q));
    }
    printf("\n");
}

bool cal(Seqqueue &q){//�����׺���ʽ
    SqStack ss;
    InitStack(ss);
    char e,d;
    while(!queueempty(q)){
        char ch = dequeue(q);
        if(isdigit(ch)){
            Push(ss,ch);
        }
        else {
            switch(ch){
              case '+':Pop(ss,e);e-='0';Pop(ss,d);d-='0';Push(ss,e+d+'0');break;
              case '-':Pop(ss,e);e-='0';Pop(ss,d);d-='0';Push(ss,d-e+'0');break;
              case '*':Pop(ss,e);e-='0';Pop(ss,d);d-='0';Push(ss,e*d+'0');break;
              case '/':Pop(ss,e);e-='0';Pop(ss,d);d-='0';if(e!=0)Push(ss,d/e+'0');else return false;break;
              default:break;
            }
        }
    }
    int f;
    Pop(ss,d);
    f = d-'0';
    printf("The anwser is = %d\n",f);
    return true;
}

int main(){
    //freopen("in.txt","r",stdin);
    Seqqueue q,p;
    InitSeqqueue(q);
    ctpostexp(q);
    p = q;
    print(q);//�����ʱ��ı�������
    cal(p);
    return 0;
}



//#include <stdio.h>
//#include <iostream>
//using namespace std;
//#define stacksize 100
//#define queuesize 100
///*  ���е���ز������Ը�*/
//typedef char datatype;
//typedef struct {
//    char data[100];
//    int front,rear;
//} seqqueue;       //�����������
///* ����ջ  */
//typedef struct {
//    datatype data[100];
//    int top;
//} seqstack;       //����ջ������
//void initqueue(seqqueue *q)  //��ʼ������
//{
//    q->front=0;
//    q->rear=0;
//}
//int queueempty(seqqueue  *q)  //�пն���
//{
//    return q->rear==q->front;
//}
//void enqueue(seqqueue *q,datatype x)   //�����
//{
//    if ((q->rear+1)%queuesize==q->front)
//            printf("queue overflow");
//    else {
//        q->data[q->rear]=x;
//            q->rear=(q->rear+1)%queuesize;
//        }
//}
//char dequeue(seqqueue *q)
//{
//    if(q->front==q->rear){
//        printf("stack overflow");
//        return '#';
//    }
//    else{
//        char c=q->data[q->front];
//        q->front=(q->front+1)%queuesize;
//        return c;
//    }
//}
//void initstack(seqstack *s)  //��ʼ��ջ
//{
//    s->top=-1;
//}
//void push(seqstack *s,datatype x) //��ջ
//{
//    if (s->top==stacksize-1) {
//        printf("stack overflow");
//    } else {
//        s->top=s->top+1;
//        s->data[s->top]=x;
//    }
//}
//datatype pop(seqstack *s)  //��ջ
//{
//    if (s->top==-1) {
//        printf("stack underflow");
//    } else {
//        return  s->data[s->top--];
//    }
//}
//datatype gettop(seqstack *s)  //ȡջ��Ԫ��
//{
//    if (s->top==-1) {
//        printf("stack empty");
//    } else {
//        return s->data[s->top];
//    }
//}
//
//int priority(datatype op) //����������ȼ�����
//{
//    switch(op)  {
//    case '(':
//    case ')':
//    case '#':
//        return (0);
//    case '-':
//    case '+':
//        return(1);
//    case '*':
//    case '/':
//        return(2);
//    }
//}
//
//void ctpostexp(seqqueue *q)
//{
//    seqstack os;   //�����ջ
//    char c,t;
//    seqstack *s;
//    s=&os;
//    initstack(s);//��ʼ��ջ
//    push(s,'#');      //ѹ��ջ��Ԫ��'#'
//    do { //ɨ����׺���ʽ
//        c=getchar();
//        switch(c)
//        {
//        case ' ':
//            break;//ȥ���ո�
//        case '0':
//        case '1':
//        case '2':
//        case '3':
//        case '4':
//        case '5':
//        case '6':
//        case '7':
//        case '8':
//        case '9':
//            enqueue(q,c);
//            break;
//        case '(':
//            push(s,c);
//            break;
//        case ')':
//        case '#':
//            do {
//                t=pop(s);
//                if (t!='('&&t!='#') {
//                    enqueue(q,t);
//                }
//            } while(t!='('&&s->top!=-1);
//            break;
//        case '+':
//        case '-':
//        case '*':
//        case '/':
//            while(priority(c)<=priority(gettop(s))) {
//                t=pop(s);
//                enqueue(q,t);
//            }
//            push(s,c);
//            break;
//        } //endswitch
//    } while(c!='#');
//}
//
//void print(seqqueue* q)
//{
//    while(!queueempty(q)) { //�����׺���ʽ
//        printf("%2c",dequeue(q));
//    }
//    printf("\n");
//}
//
//void cal(seqqueue* q)
//{
//    seqstack* ans=new seqstack;
//    initstack(ans);
//    while(!queueempty(q)){
//        char ch=dequeue(q);
//        if(ch>='0'&&ch<='9'){
//            push(ans,ch);
//        } else if(ch=='+'||ch=='-'||ch=='*'||ch=='/') {
//            int val1=pop(ans)-'0';
//            int val2=pop(ans)-'0';
//            switch (ch)
//            {
//                case '+':push(ans,(val1+val2)+'0');break;
//                case '-':push(ans,(val2-val1)+'0');break;
//                case '*':push(ans,(val1*val2)+'0');break;
//                case '/':push(ans,(val2/val1)+'0');break;
//                default :break;
//            }
//        }
//    }
//    printf("The answer = %d\n",pop(ans)-'0');
//    delete ans;
//}
//int main()
//{
//    freopen("in.txt","r",stdin);
//    seqqueue *q;
//    seqqueue postq;//������У���ź�׺���ʽ
//    seqqueue p;
//    q=&postq;
//    initqueue(q);//��ʼ������
//    ctpostexp(q);//��׺���ʽת��Ϊ��׺���ʽ
//    p=postq;
//    print(q);
//    postq=p;
//    cal(q);
//    return 0;
//}



