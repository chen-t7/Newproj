#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType *a;
	size_t top; //ջ��
	size_t capacity;
}Stack;

void StackInit(Stack *pst);
void StackDestory(Stack *pst);
void StackPush(Stack *pst, STDataType x);
void StackPop(Stack *pst);
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* pst);
//����1��ʾ�գ�����0��ʾ�ǿ�
int StackEmpty(Stack *pst);
// ��ȡջ����ЧԪ�ظ���
size_t StackSize(Stack *pst);




