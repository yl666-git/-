#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10     //定义队列中元素的最大个数
#define ElemType int

typedef struct{
    ElemType data[MaxSize];   //用静态数组存放队列元素
    int front , rear;  //连续的存储空间，大小为——MaxSize*sizeof(ElemType)
} SqQueue;

//初始化队列
void InitQueue(SqQueue &Q){
    //初始化时，队头、队尾指针指向0
    Q.rear = Q.front = 0;
}

void test(){
    SqQueue Q;                //声明一个队列
    InitQueue(Q);
    //...
}

// 判空
bool QueueEmpty(SqQueue Q){
    if(Q.rear == Q.front)    //判空条件后
        return true;
    else 
        return false;
}