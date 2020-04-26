#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
#include "Queue.h"

void StackInit(Stack *pst)
{
	assert(pst);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

void StackDestory(Stack *pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

void StackPush(Stack *pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		size_t newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		pst->a = (STDataType*)realloc(pst->a, sizeof(STDataType)*newcapacity);
		pst->capacity = newcapacity;
	}

	pst->a[pst->top] = x;
	pst->top++;
}

void StackPop(Stack *pst)
{
	assert(pst && pst->top > 0);
	pst->top--;
}

STDataType StackTop(Stack* pst)
{
	assert(pst);
	return pst->a[pst->top - 1];
}

int StackEmpty(Stack *pst)
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;
}

size_t StackSize(Stack *pst)
{
	assert(pst);
	return pst->top;
}



//╤сап
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->back = pq->front = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode *cur = pq->front;
	while (cur != NULL)
	{
		QueueNode *next = cur->next;
		free(cur);
		cur = next;
	}
	pq->back = pq->front = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode *newnode = (QueueNode *)malloc(sizeof(QueueNode));
	newnode->next = NULL;
	newnode->val = x;
	if (pq->front == NULL)
	{
		pq->back = pq->front = newnode;
	}
	else
	{
		pq->back->next = newnode;
		pq->back = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode *next = pq->front->next;
	free(pq->front);
	pq->front = next;
	if (pq->front == NULL)
	{
		pq->back = NULL;
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->front->val;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->back->val;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode *cur = pq->front;
	int count = 0;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->back == NULL ? 1 : 0;
}

