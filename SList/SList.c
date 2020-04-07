#define _CRT_SECURE_NO_WARNINGS 1
#include "Slist.h"

SListNode* BuySListNode(SLTDataType x)
{
	SListNode *newnode = (SListNode *)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}

void SListPrint(SListNode *plist)
{
	while (plist != NULL)
	{
		printf("%d->", plist->_data);
		plist = plist->_next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode **pplist, SLTDataType x)
{
	SListNode *newnode = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode *cur = *pplist;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}

void SListPopBack(SListNode **pplist)
{
	SListNode *tail = *pplist;
	SListNode *prev = NULL;
	while (tail->_next != NULL)
	{
		prev = tail;
		tail = tail->_next;
	}
	free(tail);
	tail = NULL;
	prev->_next = NULL;
}

void SListPushFront(SListNode **pplist, SLTDataType x)
{
	SListNode *list = *pplist;
	SListNode *newnode = BuySListNode(x);
	if (list == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->_next = list;
		*pplist = newnode;
	}
}

void SListPopFront(SListNode **pplist)
{
	SListNode *node = *pplist;
	if (node == NULL || node->_next == NULL)
	{
		*pplist = NULL;
	}
	else
	{
		SListNode *next = node->_next;
		free(node);
		node = NULL;
		*pplist = next;
	}		
}

SListNode* SListFind(SListNode *plist, SLTDataType x)
{
	while (plist != NULL)
	{
		if (plist->_data == x)
		{
			return plist;
		}
		else
		{
			plist = plist->_next;
		}
	}
	return NULL;
}

void SListInsertAfter(SListNode *pos, SLTDataType x)
{
	assert(pos);
	SListNode *node = BuySListNode(x);
	SListNode *next = pos->_next;
	pos->_next = node;
	node->_next = next;
}

void SListEraseAfter(SListNode *pos)
{
	assert(pos);
	SListNode *next = pos->_next;
	if (next != NULL)
	{
		SListNode *next_next = next->_next;
		pos->_next = next_next;
		free(next);
		next = NULL;
	}
}
