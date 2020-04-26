#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

ListNode* CreateNode()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	pHead->next = pHead;
	pHead->prev = pHead;
	return pHead;
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->val = x;
	return newnode;
}

void ListPrint(ListNode *pHead)
{
	assert(pHead);
	ListNode *cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode *pHead, LTDataType x)
{
	assert(pHead);
	//ListInsert(pHead, x);
	ListNode *newnode = BuyListNode(x);
	ListNode *tail = pHead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = pHead;
	pHead->prev = newnode;

}

void ListPushFront(ListNode *pHead, LTDataType x)
{
	assert(pHead);
	//ListInsert(pHead->next, x);
	ListNode *newnode = BuyListNode(x);
	ListNode *first = pHead->next;
	pHead->next = newnode;
	newnode->prev = pHead;
	newnode->next = first;
	first->prev = newnode;

}

void ListPopBack(ListNode *pHead)
{
	assert(pHead);
	//ListErase(pHead);
	ListNode *tail = pHead->prev;
	tail->prev->next = pHead;
	pHead->prev = tail->prev;
	free(tail);
}

void ListPopFront(ListNode *pHead)
{
	assert(pHead);
	//ListErase(pHead->next->next);
	ListNode *first = pHead->next;
	pHead->next = first->next;
	first->next->prev = pHead;
	free(first);
}

ListNode* ListFind(ListNode *pHead, LTDataType x)
{
	assert(pHead);
	ListNode *cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在pos位置前面插入数据
void ListInsert(ListNode *pos, LTDataType x)
{
	assert(pos);
	ListNode *newnode = BuyListNode(x);
	ListNode *Prev = pos->prev;
	Prev->next = newnode;
	newnode->prev = Prev;
	newnode->next = pos;
	pos->prev = newnode;
}
//在pos位置前面删除数据
void ListErase(ListNode *pos)
{
	assert(pos);
	ListNode *Prev = pos->prev;
	Prev->prev->next = pos;
	pos->prev = Prev->prev;
	free(Prev);
}