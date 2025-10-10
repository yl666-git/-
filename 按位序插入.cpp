#include<stdio.h>
#include<stdlib.h>

typedef int ElemType; // 定义数据元素类型

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//在p结点之后插入元素e
bool InsertNextNode(LNode *p, ElemType e){
    if(p==NULL){
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    //某些情况下分配失败，比如内存不足
    if(s==NULL)
        return false;
    s->data = e;          //用结点s保存数据元素e 
    s->next = p->next;
    p->next = s;          //将结点s连到p之后

    return true;
}                         //平均时间复杂度 = O(1)

//在p结点之前插入元素e
bool InsertPriorNode(LNode *p, ElemType e){
    if(p==NULL){
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    //某些情况下分配失败，比如内存不足
    if(s==NULL)
        return false;
    s->data = p->data;    //用结点s保存p结点的数据元素 
    p->data = e;          //将e赋值给p结点的数据域
    s->next = p->next;    
    p->next = s;          //将结点s连到p之后

    return true;
}

//有了后插操作，那么在第i个位置上插入指定元素e的代码可以改成：
bool ListInsert(LinkList &L, int i, ElemType e){  
    if(i<1)
        return false;
    
    LNode *p;       //指针p指向当前扫描到的结点 
    int j=0;        //当前p指向的是第几个结点
    p = L;          //L指向头结点，头结点是第0个结点（不存数据）

    //循环找到第i-1个结点
    while(p!=NULL && j<i-1){     //如果i>lengh, p最后4鸟会等于NULL
        p = p->next;             //p指向下一个结点
        j++;
    }

    return InsertNextNode(p, e);
}

//删除第i个位置上的元素，并用e返回其值
bool ListDelete(LinkList &L, int i, ElemType &e){
    if(i<1)
        return false;
    
    LNode *p;       //指针p指向当前扫描到的结点 
    int j=0;        //当前p指向的是第几个结点
    p = L;          //L指向头结点，头结点是第0个结点（不存数据）

    //循环找到第i-1个结点
    while(p!=NULL && j<i-1){     //如果i>lengh, p最后4鸟会等于NULL
        p = p->next;             //p指向下一个结点
        j++;
    }

    if(p==NULL || p->next==NULL) //第i个结点不存在
        return false;

    LNode *q = p->next;          //q指向被删除的结点
    e = q->data;                 //用e返回被删除结点的数据元素
    p->next = q->next;           //将q结点从链表中断开
    free(q);                     //释放被删除结点的存储空间

    return true;
}

//删除指定结点p（不是尾结点）
bool DeleteNode(LNode *p){
    if(p==NULL)
        return false;
    
    LNode *q = p->next;      //令q指向*p的后继结点
    p->data = p->next->data; //让p和后继结点交换数据域
    p->next = q->next;       //将*q结点从链中“断开”
    free(q);
    return true;
}

LNode* GetElem(LinkList L, int i){
   if (i < 0) return NULL; // i值不合法
  LNode *p = L; // p指向头结点
  int j = 0;
  while(p !=NULL&&j<i){
    p = p->next;
    j++;
  }
  return p; // p指向第i个结点，或NULL
   
}

//按值查找，找到返回该结点的地址，否则返回NULL
LNode * LocateElem(LinkList L,ElemType e){
    LNode * p = L->next;
    while (p!=NULL&&p->data!=e)
    {
        p = p->next;
    }
    return p;  
}

//求表长
int Length(LinkList L){
    int len=0;       //统计表长
    LNode *p = L;
    while(p->next != NULL){
        p = p->next;
        len++;
    }
    return len;
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){       //逆向建立单链表
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));     //建立头结点
    L->next = NULL;                          //初始为空链表,这步不能少！

    scanf("%d", &x);                         //输入要插入的结点的值
    while(x!=9999){                          //输入9999表结束
        s = (LNode *)malloc(sizeof(LNode));  //创建新结点
        s->data = x;
        s->next = L->next;
        L->next = s;                         //将新结点插入表中，L为头指针
        scanf("%d", &x);   
    }
    return L;
   
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
    LNode *s, *r;      //r为指向尾部的结点
    int x;
    L = (LinkList)malloc(sizeof(LNode)); //建立头结点
    L->next = NULL;                      //初始为空链表,这步不能少！
    r = L;                               //让r指向头结点

    scanf("%d", &x);                     //输入要插入的结点的值
    while(x!=9999){                      //输入9999表结束
        s = (LNode *)malloc(sizeof(LNode)); //创建新结点
        s->data = x;
        r->next = s;                     //将新结点插入表尾，r为尾指针
        r = s;                            //让r指向新的尾结点
        scanf("%d", &x);   
    }
    r->next = NULL;                     //尾结点next域置空
    return L;
}

//单链表逆置
LNode *Inverse(LNode *L)
{
	LNode *p, *q;
	p = L->next;     //p指针指向第一个结点
	L->next = NULL;  //头结点指向NULL

	while (p != NULL){
		q = p;
		p = p->next;
		q->next = L->next;  
		L->next = q;
	}
	return L;
}



