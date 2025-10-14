#include <stdio.h>
#include <stdlib.h>


typedef struct ThreadNode{
   int data;
   struct ThreadNode *lchild, *rchild;
   int ltag, rtag;                // 左、右线索标志
}ThreadNode, *ThreadTree;

//全局变量pre, 指向当前访问的结点的前驱
ThreadNode *pre=NULL; // 修正：TreadNode -> ThreadNode

// 声明 visit 函数，以便 InThread 可以调用它
void visit(ThreadNode *q);

void InThread(ThreadTree T){
    if(T!=NULL){
        InThread(T->lchild);    //中序遍历左子树
        visit(T);               //访问根节点
        InThread(T->rchild);    //中序遍历右子树
    }
}

void visit(ThreadNode *q){
   if(q->lchild == NULL){                 // 修正：lchid -> lchild, = -> ==
      q->lchild = pre;
      q->ltag = 1;
   }

   if(pre!=NULL && pre->rchild == NULL){  // 修正：= -> ==
      pre->rchild = q;           //建立前驱结点的后继线索
      pre->rtag = 1;
   }
   pre = q;
}

//中序线索化二叉树T
void CreateInThread(ThreadTree T){
   pre = NULL;                //pre初始为NULL
   if(T!=NULL){              // 修正：移除了 if 后面的分号
      InThread(T);            //中序线索化二叉树
      if(pre->rchild == NULL)
         pre->rtag=1;         //处理遍历的最后一个结点
   }
}


