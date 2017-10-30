//ջ��Ӧ�ã�3��
//�����׺���ʽ���沨�����ʽ�������������֧��double�����룩
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <deque>
#include <stack>

using namespace std;
const int maxn = 100;
const int STACK_INIT_SIZE = 100;
const int STACK_INCREMENT = 50;

typedef double SElemType;
typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

bool InitStack(SqStack &S){
    S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base) return false;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return true;
}

bool GetTop(SqStack &S,SElemType &e){
    if(S.top == S.base) return false;
    e = *(S.top-1);
    return true;
}

bool Push(SqStack &S,SElemType e){
    if(S.top - S.base >= S.stacksize){
        S.base = (SElemType *)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(SElemType));
    if(!S.base)return false;
    S.top = S.base+S.stacksize;
    S.stacksize += STACK_INCREMENT;
    }
    *S.top = e;
     S.top++;
    return true;
}

bool Pop(SqStack &S,SElemType &e){
    if(S.base == S.top)return false;
    e = *(S.top-1);
    S.top--;
    //e = *--S.top;
    return true;
}

bool IsEmpty(SqStack &S){
    if(S.base == S.top)return true;
    return false;
}

int main(){
    freopen("in.txt","r",stdin);
    char c;
    char str[maxn];
    double e1,e2,e3;
    SqStack s;
    InitStack(s);
    scanf("%c",&c);
    while(c!='#'){
        int i = 0;
        while(isdigit(c)||c == '.'){
            str[i++] = c;
            str[i] = '\0';
            scanf("%c",&c);
            if(c == ' '){
                double d = atof(str);
                Push(s,d);
                break;
            }
        }
        switch(c){
            case '+': Pop(s,e1);Pop(s,e2);Push(s,e1+e2);break;
            case '-': Pop(s,e1);Pop(s,e2);Push(s,e2-e1);break;
            case '*': Pop(s,e1);Pop(s,e2);Push(s,e1*e2);break;
            case '/': Pop(s,e1);Pop(s,e2);if(e1!=0)Push(s,e2/e1);else return -1;break;
        }
        scanf("%c",&c);
    }
    Pop(s,e3);
    printf("%f\n",e3);
    return 0;
}



//
//#include <iostream>
//#include <algorithm>
//#include <string.h>
//#include <stdio.h>
//#include <deque>
////#include <ctype.h>
//#include <stack>
//
//using namespace std;
//const int maxn = 100;
////const int STACK_INIT_SIZE = 100;
////const int STACK_INCREMENT = 10;
//
//typedef double SElemType;
//typedef bool Status;
//#define STACK_INIT_SIZE 10
//#define STACK_INCREMENT 2
//#define ERROR 0
//#define OK 1
//typedef struct SqStack
//{
//    SElemType *base; /* ��ջ����֮ǰ������֮��base ��ֵΪ NULL */
//    SElemType *top; /* ջ��ָ�� */
//    int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
//} SqStack; /* ˳��ջ */
//void InitStack(SqStack *S)
//{
//    /* ����һ����ջ S */
//    (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
//    //if(!(*S).base)
//       // exit(OVERFLOW); /* �洢����ʧ�� */
//    (*S).top=(*S).base;
//    (*S).stacksize=STACK_INIT_SIZE;
//}
//void DestroyStack(SqStack *S)
//{
//    /* ����ջ S��S ���ٴ��� */
//    free((*S).base);
//    (*S).base=NULL;
//    (*S).top=NULL;
//    (*S).stacksize=0;
//}
//Status StackEmpty(SqStack S)
//{
//    /* ��ջ S Ϊ��ջ���򷵻� TRUE�����򷵻� FALSE */
//    if(S.top==S.base)
//        return true;
//    else
//        return false;
//}
//Status GetTop(SqStack S,SElemType *e)
//{
//    /* ��ջ���գ����� e ���� S ��ջ��Ԫ�أ������� OK�����򷵻� ERROR */
//    if(S.top>S.base)
//    {
//        *e=*(S.top-1);
//        return OK;
//    }
//    else
//        return ERROR;
//}
//void Push(SqStack *S,SElemType e)
//{
//    /* ����Ԫ�� e Ϊ�µ�ջ��Ԫ�� */
//    if((*S).top-(*S).base>=(*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
//    {
//        (*S).base=(SElemType*)realloc((*S).base,((*S).stacksize+STACK_INCREMENT)*sizeof(SElemType));
////        if(!(*S).base)
////            exit(OVERFLOW); /* �洢����ʧ�� */
//        (*S).top=(*S).base+(*S).stacksize;
//        (*S).stacksize+=STACK_INCREMENT;
//    }
//    *((*S).top)++=e;
//}
//Status Pop(SqStack *S,SElemType *e)
//{
//    /* ��ջ���գ���ɾ�� S ��ջ��Ԫ�أ��� e ������ֵ�������� OK�����򷵻� ERROR
//    */
//    if((*S).top==(*S).base)
//        return ERROR;
//    *e=*--(*S).top;
//    return OK;
//}
//
//int main(){
//    freopen("in.txt","r",stdin);
//    char c;
//    char str[maxn];
//    double e1,e2,e3;
//    SqStack s;
//    InitStack(&s);
//    int i = 0;
//    scanf("%c",&c);
//    while(c!='#'){
//        while(isdigit(c)||c == '.'){
//            str[i++] = c;
//            str[i] = '\0';
//            scanf("%c",&c);
//            if(c == ' '){
//                double d = atof(str);
//                Push(&s,d);
//                i = 0;
//                break;
//            }
//        }
//        switch(c){
//            case '+': Pop(&s,&e1);Pop(&s,&e2);Push(&s,e1+e2);break;
//            case '-': Pop(&s,&e1);Pop(&s,&e2);Push(&s,e2-e1);break;
//            case '*': Pop(&s,&e1);Pop(&s,&e2);Push(&s,e1*e2);break;
//            case '/': Pop(&s,&e1);Pop(&s,&e2);if(e1!=0)Push(&s,e2/e1);else return -1;break;
//        }
//        scanf("%c",&c);
//    }
//    Pop(&s,&e3);
//    printf("%f\n",e3);
//    return 0;
//}





