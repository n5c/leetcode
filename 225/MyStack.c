#include <leetcode.h>

struct MyQueue {
	int *data;
	int size;
	int front;
	int rear;
	int wrap;
};

typedef struct {
	struct MyQueue *q, *q2;
} MyStack;

static void _push_back(struct MyQueue *q, int x)
{
	if (q->wrap && q->front == q->rear)
		return;
	q->data[(q->rear)++] = x;
	if (q->rear >= q->size) {
		q->rear = 0;
		q->wrap = 1;
	}
}

static int _pop_front(struct MyQueue *q)
{
	int x = q->data[q->front++];
	if (q->front >= q->size) {
		q->front = 0;
		q->wrap = 0;
	}
	return x;
}

static int _peek_front(struct MyQueue *q)
{
	return q->data[q->front];
}

static int _size(struct MyQueue *q)
{
	int size = q->rear - q->front;
	if (q->wrap)
		size += q->size;
	return size;
}

static bool _isempty(struct MyQueue *q)
{
	return (!q->wrap && q->front == q->rear);
}

static struct MyQueue *_create(int size)
{
	struct MyQueue *q = malloc(sizeof(*q));
	q->data = malloc(sizeof(*(q->data)) * size);
	q->size = size;
	q->front = 0;
	q->rear = 0;
	q->wrap = 0;
	return q;
}

static void _free(struct MyQueue *q)
{
	free(q->data);
	free(q);
}

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
	MyStack *stk = malloc(sizeof(*stk));
	stk->q = _create(maxSize);
	stk->q2 = _create(maxSize);
	return stk;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	_push_back(obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int x;
	while (_size(obj->q) > 1)
		_push_back(obj->q2, _pop_front(obj->q));
	x = _pop_front(obj->q);
	while (_size(obj->q2))
		_push_back(obj->q, _pop_front(obj->q2));
	return x;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	int x;
	while (_size(obj->q) > 1)
		_push_back(obj->q2, _pop_front(obj->q));
	x = _pop_front(obj->q);
	while (_size(obj->q2))
		_push_back(obj->q, _pop_front(obj->q2));
	_push_back(obj->q, x);
	return x;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return _isempty(obj->q);
}

void myStackFree(MyStack* obj) {
	_free(obj->q);
	_free(obj->q2);
	free(obj);
}

void tc_0(void)
{
	MyStack *stk;
	stk = myStackCreate(7);
	myStackPush(stk, 11);
	myStackPush(stk, 22);
	myStackPush(stk, 33);
	myStackPush(stk, 44);
	myStackPush(stk, 55);
	myStackPush(stk, 66);
	myStackPush(stk, 77);
	myStackPush(stk, 88);
	while (!myStackEmpty(stk)) {
		printf("top: %d\n", myStackTop(stk));
		printf("pop: %d\n", myStackPop(stk));
	}
	myStackPush(stk, 99);
	myStackPush(stk, 1010);
	myStackPush(stk, 1111);
	printf("top: 1111: %d\n", myStackTop(stk));
	myStackFree(stk);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

