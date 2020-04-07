#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode *_next;
}SListNode;

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SListNode **pplist, SLTDataType x);
void SListPopFront(SListNode **pplist);
void SListPushBack(SListNode **pplist, SLTDataType x);
void SListPopBack(SListNode **pplist);
SListNode* SListFind(SListNode *plist, SLTDataType x);
// ��pos�ĺ�����в���
void SListInsertAfter(SListNode *pos, SLTDataType x);
// ��pos��ǰ����в���
void SListEraseAfter(SListNode *pos);
void SListPrint(SListNode *plist);
