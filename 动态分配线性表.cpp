#include <stdio.h>
#include <stdlib.h>
#define InitSize 10 //定义表的最大长度

typedef struct //动态分配线性表
{
    int *data;  //用动态分配的"数组"存放数据元素
    int length; //顺序表的当前长度
    int MaxSize; //顺序表的最大长度
} SqList;      //顺序表的类型定义（动态分配方式）

void InitList(SqList &L)
{
    L.data = (int *)malloc(InitSize * sizeof(int)); //为顺序表分配InitSize个存储单元
    if (!L.data)                                   //存储分配失败
        exit(0);
    L.length = 0;      //将顺序表的当前长度设置为0
    L.MaxSize = InitSize; //将顺序表的最大长度设置为InitSize
}

void IncreaseSize(SqList &L, int len) //增加顺序表的存储容量
{
    int *p = L.data; //暂存原顺序表的地址
    L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
    for(int i = 0; i < L.length; i++){
        L.data[i] = p[i]; //将原顺序表的数据元素复制到新顺序表
    }
    L.MaxSize = L.MaxSize + len; //更新顺序表的最大长度
    free(p);                     //释放原顺序表的存储空间
}

int main()
{
    SqList L;       //声明一个顺序表
    InitList(L);   //初始化一个顺序表
    printf("顺序表的最大长度=%d\n", L.MaxSize);
    printf("顺序表的当前长度=%d\n", L.length);
    IncreaseSize(L, 5); //增加顺序表的存储容量
    printf("顺序表的最大长度=%d\n", L.MaxSize);
    return 0;
}