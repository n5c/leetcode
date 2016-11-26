#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct
{
	int maxSize;
	int dataTop;
	int *data;
	int backTop;
	int *back;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize)
{
	queue->maxSize = maxSize;

	queue->dataTop = -1;
	queue->data = malloc(sizeof(int) * maxSize);

	queue->backTop = -1;
	queue->back = malloc(sizeof(int) * maxSize);
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element)
{
	if (queue->dataTop >= queue->maxSize - 1)
		return;
	queue->data[++queue->dataTop] = element;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue)
{
	while (queue->dataTop > 0)
		queue->back[++queue->backTop] = queue->data[queue->dataTop--];
	queue->dataTop--;
	while (queue->backTop >= 0)
		queue->data[++queue->dataTop] = queue->back[queue->backTop--];
}

/* Get the front element */
int queuePeek(Queue *queue)
{
	return queue->data[0];
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue)
{
	return (queue->dataTop <= -1);
}

/* Destroy the queue */
void queueDestroy(Queue *queue)
{
	queue->maxSize = -1;

	queue->dataTop = -1;
	free(queue->data);
	queue->data = NULL;

	queue->backTop = -1;
	free(queue->back);
	queue->back = NULL;
}

void test_case_0()
{
	Queue q;
	queueCreate(&q, 10);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);
	queuePush(&q, 5);
	queuePush(&q, 6);
	queuePush(&q, 7);
	queuePush(&q, 8);
	queuePush(&q, 9);
	queuePush(&q, 10);
	queuePush(&q, 11);
	queuePush(&q, 12);

	while (!queueEmpty(&q)) {
		printf("%d\n", queuePeek(&q));
		queuePop(&q);
	}

	queueDestroy(&q);
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

