//栈的应用（1）进制的转换

#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <deque>
#include <stack>

using namespace std;
const int maxn = 100;
//const int STACK_INIT_SIZE = 100;
//const int STACK_INCREMENT = 10;

typedef char SElemType;
typedef bool Status;
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2
#define ERROR 0
#define OK 1
typedef struct SqStack
{
    SElemType *base; /* 在栈构造之前和销毁之后，base 的值为 NULL */
    SElemType *top; /* 栈顶指针 */
    int stacksize; /* 当前已分配的存储空间，以元素为单位 */
} SqStack; /* 顺序栈 */
void InitStack(SqStack *S)
{
    /* 构造一个空栈 S */
    (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    //if(!(*S).base)
       // exit(OVERFLOW); /* 存储分配失败 */
    (*S).top=(*S).base;
    (*S).stacksize=STACK_INIT_SIZE;
}
void DestroyStack(SqStack *S)
{
    /* 销毁栈 S，S 不再存在 */
    free((*S).base);
    (*S).base=NULL;
    (*S).top=NULL;
    (*S).stacksize=0;
}
Status StackEmpty(SqStack S)
{
    /* 若栈 S 为空栈，则返回 TRUE，否则返回 FALSE */
    if(S.top==S.base)
        return true;
    else
        return false;
}
Status GetTop(SqStack S,SElemType *e)
{
    /* 若栈不空，则用 e 返回 S 的栈顶元素，并返回 OK；否则返回 ERROR */
    if(S.top>S.base)
    {
        *e=*(S.top-1);
        return OK;
    }
    else
        return ERROR;
}
void Push(SqStack *S,SElemType e)
{
    /* 插入元素 e 为新的栈顶元素 */
    if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
    {
        (*S).base=(SElemType
                   *)realloc((*S).base,((*S).stacksize+STACK_INCREMENT)*sizeof(SElemType));
//        if(!(*S).base)
//            exit(OVERFLOW); /* 存储分配失败 */
        (*S).top=(*S).base+(*S).stacksize;
        (*S).stacksize+=STACK_INCREMENT;
    }
    *((*S).top)++=e;
}
Status Pop(SqStack *S,SElemType *e)
{
    /* 若栈不空，则删除 S 的栈顶元素，用 e 返回其值，并返回 OK；否则返回 ERROR
    */
    if((*S).top==(*S).base)
        return ERROR;
    *e=*--(*S).top;
    return OK;
}

int main(){
    //freopen("in.txt","r",stdin);
    char str[maxn];
    SqStack s;
    int n,x;
    while(cin>>str){
        InitStack(&s);
        bool flag = true;
        for(int i=0;i<strlen(str);i++){
            if(str[i] == '(')Push(&s,str[i]);
            else {
                if(StackEmpty(s)){flag = false;break;}
                else {
                    char e;
                    Pop(&s,&e);
                }
            }
        }
        if(!StackEmpty(s)||flag == false)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}



//#include <iostream>
//#include <algorithm>
//#include <string.h>
//#include <stdio.h>
//#include <deque>
//#include <stack>
//
//using namespace std;
//const int maxn = 100;
//const int STACK_INIT_SIZE = 100;
//const int STACK_INCREMENT = 50;
//
//typedef char SElemType;
//
//typedef struct{
//    SElemType *base;
//    SElemType *top;
//    int stacksize;
//}SqStack;
//
//bool InitSqStack(SqStack &S){
//    S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
//    if(!S.base) return false;
//    S.top = S.base;
//    S.stacksize = STACK_INIT_SIZE;
//    return true;
//}
//
//bool GetTop(SqStack &S,SElemType &e){
//    if(S.top == S.base) return false;
//    e = *(S.top-1);
//    return true;
//}
//
//bool Push(SqStack &S,SElemType e){
//    if(S.top - S.base >= S.stacksize){
//        S.base = (SElemType *)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(SElemType));
//    if(!S.base)return false;
//    S.top = S.base+S.stacksize;
//    S.stacksize += STACK_INCREMENT;
//    }
//    *S.top = e;
//     S.top++;
//    return true;
//}
//
//bool Pop(SqStack &S,SElemType &e){
//    if(S.base == S.top)return false;
//    e = *(S.top-1);
//    S.top--;
//    //e = *--S.top;
//    return true;
//}
//
//bool IsEmpty(SqStack &S){
//    if(S.base == S.top)return true;
//    return false;
//}
//
//int main(){
//    //freopen("in.txt","r",stdin);
//    char str[maxn];
//    SqStack s;
//    int n,x;
//    while(cin>>str){
//        InitSqStack(s);
//        bool flag = true;
//        for(int i=0;i<strlen(str);i++){
//            if(str[i] == '(')Push(s,str[i]);
//            else {
//                if(IsEmpty(s)){flag = false;break;}
//                else {
//                    char e;
//                    Pop(s,e);
//                }
//            }
//        }
//        if(!IsEmpty(s)||flag == false)cout<<"No"<<endl;
//        else cout<<"Yes"<<endl;
//    }
//    return 0;
//}


