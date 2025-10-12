#include<stdio.h>
#include<stdlib.h>



typedef struct Linknode{
    int data;             //数据域
    Linknode *next;       //指针域
}Linknode,*LiStack;   

typedef Linknode *Node;   //结点结构体指针变量
typedef Node List;        //结点结构体头指针变量

//1. 初始化
void InitStack(LiStack &L){   //L为头指针
    L = new Linknode; 
    L->next = NULL;
}

//2.判栈空
bool isEmpty(LiStack &L){
    if(L->next == NULL){
        return true;
    }
    else
        return false;
}

//3. 进栈(：链栈基本上不会出现栈满的情况)
void pushStack(LiStack &L, int x){
    Linknode *s;          //创建存储新元素的结点
    s = new Linknode;
    s->data = x;

    //头插法
    s->next = L->next;
    L->next = s;
}

//4.出栈
bool popStack(LiStack &L, int &x){
    Linknode *s;
    if(L->next == NULL) //栈空不能出栈
        return false;
    
    s = L->next;
    x = s->data;
    L->next = L->next->next;
    delete(s);

    return true;
}



