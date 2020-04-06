#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void SeqListTest1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	int ret = SeqListFind(&s, 8);
	printf("%d\n", ret);
}

void SeqListTest2()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	SeqListInsert(&s, 3, 30);
	SeqListPrint(&s);
	SeqListInsert(&s, 0, -1);
	SeqListPrint(&s);

	SeqListErase(&s, 0);
	SeqListPrint(&s);
	SeqListErase(&s, 3);
	SeqListPrint(&s);
}

void SeqListTest3()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 20);
	SeqListPushBack(&s, 54);
	SeqListPushBack(&s, 29);
	SeqListPushBack(&s, 13);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 15);
	SeqListPrint(&s);

	SeqListBubbleSort(&s);
	SeqListPrint(&s);

	int ret1 = SeqListBinaryFind(&s, 4);
	int ret2 = SeqListBinaryFind(&s, 13);
	int ret3 = SeqListBinaryFind(&s, 15);
	int ret4 = SeqListBinaryFind(&s, 20);
	int ret5 = SeqListBinaryFind(&s, 29);
	int ret6 = SeqListBinaryFind(&s, 54);
	int ret7 = SeqListBinaryFind(&s, 9);
	printf("%d %d %d %d %d %d %d\n", ret1, ret2, ret3, ret4, ret5, ret6, ret7);
}
int main()
{
	SeqListTest3();
	return 0;
}