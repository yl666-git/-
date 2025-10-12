#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10         //定义栈中元素的最大个数

typedef int ElemType;     //定义栈中元素的数据类型

typedef struct{
    ElemType data[MaxSize];       //静态数组存放栈中元素
    int top;                      //栈顶元素
}SqStack;

//初始化栈
void InitStack(SqStack &S){
    S.top = -1;                   //初始化栈顶指针
}

//判断栈是否为空
bool StackEmpty(SqStack S){
    if(S.top == -1)
        return true;
    else
        return false;
}

//新元素进栈
bool Push(SqStack &S, ElemType x){
    if(S.top == MaxSize - 1)        //栈满
        return false;
    
    S.top = S.top + 1;    //指针先加1
    S.data[S.top] = x;    //新元素入栈

    /*
    S.data[++S.top] = x;
    */
    return true;
}

//栈顶元素出栈
bool Pop(SqStack &S, ElemType &x){
    if(S.top == -1)                 //栈空
        return false;
    
    x = S.data[S.top];             //用x返回栈顶元素的值
    S.top = S.top - 1;             //栈顶指针减1

    /*
    x = S.data[S.top--];
    */
    return true;
}

//取栈顶元素
bool GetTop(SqStack S, ElemType &x){
    if(S.top == -1)                 //栈空
        return false;
    
    x = S.data[S.top];             //用x返回栈顶元素的值
    return true;
}

int main(){
    SqStack S;        //声明一个栈
    ElemType x;      //临时变量
    InitStack(S);    //初始化栈
    printf("栈是否为空？%d(1:空 0:否) 栈顶指针=%d\n", StackEmpty(S), S.top);
    
    for(int i=1;i<=5;i++){
        Push(S, i);   //元素进栈
    }
    printf("栈是否为空？%d(1:空 0:否) 栈顶指针=%d\n", StackEmpty(S), S.top);

    GetTop(S, x);   //取栈顶元素
    printf("栈顶元素=%d 栈顶指针=%d\n", x, S.top);

    while(!StackEmpty(S)){
        Pop(S, x);   //元素出栈
        printf("出栈元素=%d 栈顶指针=%d\n", x, S.top);
    }
    printf("栈是否为空？%d(1:空 0:否) 栈顶指针=%d\n", StackEmpty(S), S.top);

    return 0;
}
