#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode *prev;
	struct ListNode *next;
	LTDataType val;
}ListNode;

ListNode* CreateNode();
ListNode* BuyListNode(LTDataType x);
void ListPrint(ListNode *pHead);

void ListPushBack(ListNode *pHead, LTDataType x);
void ListPushFront(ListNode *pHead, LTDataType x);
void ListPopBack(ListNode *pHead);
void ListPopFront(ListNode *pHead);

ListNode* ListFind(ListNode *pHead, LTDataType x);
void ListInsert(ListNode *pos, LTDataType x);
void ListErase(ListNode *pos);