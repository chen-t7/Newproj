#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

typedef int QDataType;
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode *next;
}QueueNode;

typedef struct Queue
{
	QueueNode *front;
	QueueNode *back;
}Queue;

// ��ʼ������
void QueueInit(Queue* pq);
// ���ٶ���
void QueueDestroy(Queue* pq);
// ��β�����
void QueuePush(Queue* pq, QDataType data);
// ��ͷ������
void QueuePop(Queue* pq);
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq);
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* pq);

