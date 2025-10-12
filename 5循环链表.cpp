#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 定义数据元素类型

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct DNode{            //定义双链表结点类型
    ElemType data;               //数据域
    struct DNode *prior, *next;  //前驱和后继指针
}DNode, *DLinklist;

//初始化循环单链表
bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode)); //分配一个头结点
    if(L==NULL)                        //内存不足，分配失败
        return false;
    
    L->next = L;   //头结点的next指针指向自己
    return true;
}

//判断循环单链表是否为空（终止条件为p或p->next是否等于头指针）
bool Empty(LinkList L){
    if(L->next == L)
        return true;    //为空
    else
        return false;
}

//判断结点p是否为循环单链表的表尾结点
bool isTail(LinkList L, LNode *p){
    if(p->next == L)
        return true;
    else
        return false;
}

bool InitDLinkList(DLinklist &L){
    L = (DNode *)malloc(sizeof(DNode));
    if(L==NULL)
    return false;
    L->prior = L;
    L->next = L;
}

//初始化循环双链表
void testDLinkList(){
    //初始化循环单链表
    DLinklist L;
    InitDLinkList(L);
    //...
}

//判断循环双链表是否为空
bool Empty(DLinklist L){
    if(L->next == L)
        return true;
    else
        return false;
}

//判断结点p是否为循环双链表的表尾结点
bool isTail(DLinklist L, DNode *p){
    if(p->next == L)
        return true;
    else
        return false;
}



