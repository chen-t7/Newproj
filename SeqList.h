#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType *_a;
	size_t _size;
	size_t _capatity;
}SeqList;

// 顺序表初始化
void SeqListInit(SeqList* ps);
// 顺序表销毁
void SeqListDestory(SeqList* ps);
// 顺序表打印
void SeqListPrint(SeqList* ps);
// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* ps);
// 顺序表尾插
void SeqListPushBack(SeqList* ps, SLDataType x);
// 顺序表尾删
void SeqListPopBack(SeqList* ps);
// 顺序表头插
void SeqListPushFront(SeqList* ps, SLDataType x);
// 顺序表头删
void SeqListPopFront(SeqList* ps);
// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);
void SeqListBubbleSort(SeqList* ps);
int SeqListBinaryFind(SeqList* ps, SLDataType x);

