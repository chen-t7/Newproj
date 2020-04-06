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

// ˳����ʼ��
void SeqListInit(SeqList* ps);
// ˳�������
void SeqListDestory(SeqList* ps);
// ˳����ӡ
void SeqListPrint(SeqList* ps);
// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* ps);
// ˳���β��
void SeqListPushBack(SeqList* ps, SLDataType x);
// ˳���βɾ
void SeqListPopBack(SeqList* ps);
// ˳���ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x);
// ˳���ͷɾ
void SeqListPopFront(SeqList* ps);
// ˳������
int SeqListFind(SeqList* ps, SLDataType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);
void SeqListBubbleSort(SeqList* ps);
int SeqListBinaryFind(SeqList* ps, SLDataType x);

