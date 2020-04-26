#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType *a;
	size_t top; //栈顶
	size_t capacity;
}Stack;

void StackInit(Stack *pst);
void StackDestory(Stack *pst);
void StackPush(Stack *pst, STDataType x);
void StackPop(Stack *pst);
// 获取栈顶元素
STDataType StackTop(Stack* pst);
//返回1表示空，返回0表示非空
int StackEmpty(Stack *pst);
// 获取栈中有效元素个数
size_t StackSize(Stack *pst);




