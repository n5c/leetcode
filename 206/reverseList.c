#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
	/*
	struct ListNode *node;
	if (!head)
		return NULL;
	if (head->next) {
		node = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return node;
	}
	return head;
	*/

	struct ListNode *prev, *curr, *next;

	if (!head)
		return NULL;

	curr = head;
	prev = NULL;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}

void printlist(struct ListNode *head)
{
	while (head) {
		printf("%d", head->val);
		if (head->next)
			printf(",");
		head = head->next;
	}
	printf("\n");
}

void test_case_0(void)
{
	struct ListNode l[] = {
		{1, NULL}
	};
	struct ListNode *node;
	node = reverseList(l);
	printf("1\n");
	printf("expect: 1\n");
	printlist(node);
	printf("\n");
}

void test_case_1(void)
{
	struct ListNode l[] = {
		{1, &l[1]},
		{1, &l[2]},
		{1, &l[3]},
		{1, NULL}
	};
	struct ListNode *node;
	node = reverseList(l);
	printf("1,1,1,1\n");
	printf("expect: 1,1,1,1\n");
	printlist(node);
	printf("\n");
}

void test_case_2(void)
{
	struct ListNode l[] = {
		{1, &l[1]},
		{1, &l[2]},
		{2, &l[3]},
		{3, NULL}
	};
	struct ListNode *node;
	node = reverseList(l);
	printf("1,1,2,3\n");
	printf("expect: 3,2,1,1\n");
	printlist(node);
	printf("\n");
}

void test_case_3(void)
{
	struct ListNode l[] = {
		{1, &l[1]},
		{1, &l[2]},
		{2, &l[3]},
		{3, &l[4]},
		{3, NULL}
	};
	struct ListNode *node;
	node = reverseList(l);
	printf("1,1,2,3,3\n");
	printf("expect: 3,3,2,1,1\n");
	printlist(node);
	printf("\n");
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	test_case_2();
	test_case_3();
	return 0;
}

