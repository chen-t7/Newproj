#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include "Queue.h"
void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	while (StackEmpty(&st) == 0)
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");
	StackDestory(&st);
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (QueueEmpty(&q) == 0)
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

	printf("\n");
	QueueDestroy(&q);
}

int main()
{
	//TestStack();
	TestQueue();
	return 0;
}