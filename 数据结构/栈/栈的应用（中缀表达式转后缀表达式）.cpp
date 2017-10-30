//栈的应用（4）
//中缀表达式转后缀表达式


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

typedef char SElemType;
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
    //freopen("in.txt","r",stdin);
    char c,e;
    SqStack s;
    InitStack(s);
    scanf("%c",&c);
    while(c!='#'){
        int i = 0;
        while(isdigit(c)){
            printf("%c",c);
            scanf("%c",&c);
            if(!isdigit(c)){
                printf(" ");
            }
        }
        if(')' == c){
            Pop(s,e);
            while('(' != e){
                printf("%c ",e);
                Pop(s,e);
            }
        }
        else if('+' == c|| '-' == c){
            if(IsEmpty(s)){Push(s,c);}
            else {
                do{
                    Pop(s,e);
                    if('(' == e){
                        Push(s,e);
                    }
                    else {
                        printf("%c ",e);
                    }

                }while(!IsEmpty(s)&&'(' != e);
                Push(s,c);
            }
        }
        else if('*' == c||'/' == c||'(' == c){
            Push(s,c);
        }
        else if('#' == c)break;
        else {cout<<"输入错误"<<endl;return -1;}
        scanf("%c ",&c);
    }
    while(!IsEmpty(s)){
        Pop(s,e);
        printf("%c ",e);
    }
    return 0;
}

//测试数据：1+(2-3)*4+10/5#

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
//typedef char SElemType;
//typedef bool Status;
//#define STACK_INIT_SIZE 10
//#define STACK_INCREMENT 2
//#define ERROR 0
//#define OK 1
//typedef struct SqStack
//{
//    SElemType *base; /* 在栈构造之前和销毁之后，base 的值为 NULL */
//    SElemType *top; /* 栈顶指针 */
//    int stacksize; /* 当前已分配的存储空间，以元素为单位 */
//} SqStack; /* 顺序栈 */
//void InitStack(SqStack *S)
//{
//    /* 构造一个空栈 S */
//    (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
//    //if(!(*S).base)
//       // exit(OVERFLOW); /* 存储分配失败 */
//    (*S).top=(*S).base;
//    (*S).stacksize=STACK_INIT_SIZE;
//}
//void DestroyStack(SqStack *S)
//{
//    /* 销毁栈 S，S 不再存在 */
//    free((*S).base);
//    (*S).base=NULL;
//    (*S).top=NULL;
//    (*S).stacksize=0;
//}
//Status StackEmpty(SqStack S)
//{
//    /* 若栈 S 为空栈，则返回 TRUE，否则返回 FALSE */
//    if(S.top==S.base)
//        return true;
//    else
//        return false;
//}
//Status GetTop(SqStack S,SElemType *e)
//{
//    /* 若栈不空，则用 e 返回 S 的栈顶元素，并返回 OK；否则返回 ERROR */
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
//    /* 插入元素 e 为新的栈顶元素 */
//    if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
//    {
//        (*S).base=(SElemType*)realloc((*S).base,((*S).stacksize+STACK_INCREMENT)*sizeof(SElemType));
////        if(!(*S).base)
////            exit(OVERFLOW); /* 存储分配失败 */
//        (*S).top=(*S).base+(*S).stacksize;
//        (*S).stacksize+=STACK_INCREMENT;
//    }
//    *((*S).top)++=e;
//}
//Status Pop(SqStack *S,SElemType *e)
//{
//    /* 若栈不空，则删除 S 的栈顶元素，用 e 返回其值，并返回 OK；否则返回 ERROR
//    */
//    if((*S).top==(*S).base)
//        return ERROR;
//    *e=*--(*S).top;
//    return OK;
//}
//
//int main(){
//    freopen("in.txt","r",stdin);
//    char c,e;
//    SqStack s;
//    InitStack(&s);
//    scanf("%c",&c);
//    while(c!='#'){
//        int i = 0;
//        while(isdigit(c)){
//            printf("%c",c);
//            scanf("%c",&c);
//            if(!isdigit(c)){
//                printf(" ");
//            }
//        }
//        if(')' == c){
//            Pop(&s,&e);
//            while('(' != e){
//                printf("%c ",e);
//                Pop(&s,&e);
//            }
//        }
//        else if('+' == c|| '-' == c){
//            if(StackEmpty(s)){Push(&s,c);}
//            else {
//                do{
//                    Pop(&s,&e);
//                    if('(' == e){
//                        Push(&s,e);
//                    }
//                    else {
//                        printf("%c ",e);
//                    }
//
//                }while(!StackEmpty(s)&&'(' != e);
//                Push(&s,c);
//            }
//        }
//        else if('*' == c||'/' == c||'(' == c){
//            Push(&s,c);
//        }
//        else if('#' == c)break;
//        else {cout<<"输入错误"<<endl;return -1;}
//        scanf("%c ",&c);
//    }
//    while(!StackEmpty(s)){
//        Pop(&s,&e);
//        printf("%c ",e);
//    }
//    return 0;
//}





