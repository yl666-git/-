#define _CRT_SECURE_NO_WARNINGS

//˳����ʵ��--��̬����

#include<stdio.h>
#define MaxSize 10   //��������󳤶� 
typedef struct {
	int data[MaxSize];//�þ�̬��"����"�������Ԫ��
	int length; //˳���ĵ�ǰ����  
}SqList;        //˳�������Ͷ��壨��̬���䷽ʽ�� 

void InitList(SqList& L) {
	for (int i = 0; i < MaxSize; i++) {
		L.data[i] = 0;  //����������Ԫ������ΪĬ�ϳ�ʼֵ

	}
	L.length = 0;
}
int main() {
	SqList L;//����һ��˳���
	InitList(L);//��ʼ��һ��˳���
	for (int i = 0; i < MaxSize; i++) {
		printf("data[%d]=%d\n", i, L.data[i]);
	}
	return 0;
}
