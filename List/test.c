#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
void ListTest1()
{
	ListNode *pHead = CreateNode();
	ListPushBack(pHead, 1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPushBack(pHead, 4);
	ListPushBack(pHead, 5);
	ListPrint(pHead);

	ListPushFront(pHead, 1);
	ListPushFront(pHead, 2); 
	ListPushFront(pHead, 3);
	ListPushFront(pHead, 4);
	ListPushFront(pHead, 5);
	ListPrint(pHead);

	ListPopBack(pHead);
	ListPopBack(pHead);
	ListPopBack(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);

	/*ListPopFront(pHead);
	ListPopFront(pHead);
	ListPopFront(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);*/

	ListNode *pos = ListFind(pHead, 3);
	ListInsert(pos, 6);
	ListInsert(pos, 6); 
	ListInsert(pos, 6);
	ListPrint(pHead);

	ListErase(pos);
	ListErase(pos);
	ListErase(pos);
	ListPrint(pHead);

}

int main()
{
	ListTest1();
	return 0;
}