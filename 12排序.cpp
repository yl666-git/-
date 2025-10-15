#include <stdio.h>
#include <stdlib.h>

//交换
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//冒泡排序
void BubbleSort(int A[], int n){   //从0开始存放
    for(int i=0; i<n-1; i++){
        bool flag = false; // 表示本趟冒泡是否发生交换的标志
        for(int j=n-1; j>i; j--) //一趟冒泡过程
            if(A[j-1]>A[j]){      //若为逆序
                swap(A[j-1],A[j]);  //交换
                flag=true;
            }
        if(flag==false)
            return;       //本趟遍历后没有发生交换，说明表已经有序，可以结束算法
    }
}

//用第一个元素将待排序序列划分为左右两个部分
int Partition(int A[], int low, int high){
    int pivot = A[low];          //用第一个元素作为枢轴
    while(low<high){
        while(low<high && A[high]>=pivot) --high; //high所指元素大于枢轴，high左移
        A[low] = A[high];   //high所指元素小于枢轴，移动到左侧

        while(low<high && A[low]<=pivot)  ++low; //low所指元素小于枢轴，low右移
        A[high] = A[low];   //low所指元素大于枢轴，移动到右侧
    }
    A[low] = pivot ;  //枢轴元素存放到最终位置
    return low;    //返回存放枢轴的最终位置
} 

//快速排序
void QuickSort(int A[], int low, int high){
    if(low<high){   //递归跳出条件
        int pivotpos = Partition(A, low, high);   //划分
        QuickSort(A, low, pivotpos - 1);    //划分左子表
        QuickSort(A, pivotpos + 1, high);   //划分右子表
    }
}


