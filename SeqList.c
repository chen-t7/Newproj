#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SeqList *ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_size = ps->_capatity = 0;
}

void SeqListCheckCapacity(SeqList *ps)
{
	assert(ps);
	int newcapacity = ps->_capatity == 0 ? 4 : ps->_capatity * 2;
	ps->_a = realloc(ps->_a, newcapacity*sizeof(SLDataType));
	ps->_capatity = newcapacity;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capatity = ps->_size = 0;
}

void SeqListPrint(SeqList *ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList *ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->_a[ps->_size++] = x;
}

void SeqListPopBack(SeqList *ps)
{
	assert(ps && ps->_size > 0);
	ps->_size--;
}

void SeqListPushFront(SeqList *ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	int pos = ps->_size - 1;
	for (; pos >= 0; pos--)
	{
		ps->_a[pos + 1] = ps->_a[pos];
	}
	ps->_a[0] = x;
	ps->_size++;
}

void SeqListPopFront(SeqList *ps)
{
	assert(ps);
	/*for (size_t i = 1; i < ps->_size; i++)
	{
		ps->_a[i - 1] = ps->_a[i];
	}*/
	for (size_t i = 0; i < ps->_size - 1; i++)
	{
	ps->_a[i] = ps->_a[i + 1];
	}
	ps->_size--;
}

int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
	{
		if (ps->_a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	size_t end = ps->_size + 1;
	for (; end > pos; end--)
	{
		ps->_a[end] = ps->_a[end - 1];
	}
	ps->_a[pos] = x;
	ps->_size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	size_t i = pos;
	for (; i < ps->_size; ++i)
	{
		ps->_a[i] = ps->_a[i + 1];
	}
	ps->_size--;
}

void SeqListBubbleSort(SeqList* ps)
{
	assert(ps);
	//¿ØÖÆÌËÊý
	for (size_t end = ps->_size - 1; end > 0; --end)
	{
		int exchange = 1;
		for (size_t i = 0; i < end; ++i)
		{
			if (ps->_a[i] > ps->_a[i + 1])
			{
				SLDataType tmp = ps->_a[i];
				ps->_a[i] = ps->_a[i + 1];
				ps->_a[i + 1] = tmp;
				exchange = 0;
			}
		}
		if (exchange == 1)
		{
			break;
		}
	}
}

int SeqListBinaryFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	size_t begin = 0, end = ps->_size - 1;
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		if (x == ps->_a[mid])
		{
			return mid;
		}
		else if (x > ps->_a[mid])
		{
			begin = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return -1;
}
