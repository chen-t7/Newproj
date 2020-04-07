#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void SListTest1()
{
	SListNode *list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPrint(list);

	SListPopFront(&list);
	SListPrint(list);
	SListPopFront(&list);
	SListPrint(list);
	SListPopFront(&list);
	SListPrint(list);
	SListPopFront(&list);
	SListPrint(list); 
	SListPopFront(&list);
	SListPrint(list);

	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPushFront(&list, 5);
	SListPrint(list);

	SListPopBack(&list);
	SListPrint(list);
	SListPopBack(&list);
	SListPrint(list);
	SListPopBack(&list);
	SListPrint(list); 
	SListPopBack(&list);
	SListPrint(list); 
    SListPopBack(&list);
	SListPrint(list);
}

void SListTest2()
{
	SListNode *list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPrint(list);

	SListNode *node = SListFind(list, 3);
	if (node != NULL)
	{
		node->_data = 30;
	}
	SListPrint(list);

	SListNode *pos = SListFind(list, 30);
	SListInsertAfter(pos, 7);
	SListPrint(list);

	SListEraseAfter(pos);
	SListPrint(list);
	SListEraseAfter(pos);
	SListPrint(list);
}

int main()
{
	SListTest2();
	return 0;
}