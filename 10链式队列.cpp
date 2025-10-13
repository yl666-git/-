#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10     //定义队列中元素的最大个数
#define ElemType int

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
} LinkNode;

typedef struct{
    LinkNode *front , *rear;  //队头、队尾指针
} LinkQueue;

//初始化链队列
void InitQueue(LinkQueue &Q){
    //初始化时，front、rear都指向头结点
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front -> next = NULL;
}

//判断队列是否为空
bool IsEmpty(LinkQueue Q){
    if(Q.front == Q.rear)     //也可用 Q.front -> next == NULL
        return true;
    else
        return false;
}

//新元素入队 (表尾进行)
void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode)); //申请一个新结点
    s->data = x;
    s->next = NULL;     //s作为最后一个结点，指针域指向NULL
    Q.rear->next = s;   //新结点插入到当前的rear之后
    Q.rear = s;         //表尾指针指向新的表尾
}


//队头元素出队
bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.front == Q.rear)
        return false;                    //空队
    
    LinkNode *p = Q.front->next;         //p指针指向即将删除的结点 (头结点所指向的结点)
    x = p->data;
    Q.front->next = p->next;             //修改头结点的next指针
    if(Q.rear == p)                      //此次是最后一个结点出队
        Q.rear = Q.front;                //修改rear指针
    free(p);                             //释放结点空间

    return true;
}

