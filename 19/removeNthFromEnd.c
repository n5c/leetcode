#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	int count = 1;
	struct ListNode *node, *rem_node, *prev_node;

	node = rem_node = head;
	while (count <= n) {
		node = node->next;
		count++;
	}

	prev_node = NULL;
	while (node) {
		node = node->next;
		prev_node = rem_node;
		rem_node = rem_node->next;
	}

	if (!prev_node) {
		head = head->next;
	} else {
		prev_node->next = rem_node->next;
	}

	return head;
}

void test_case_0()
{
	struct ListNode l[6] = {
		{3,  &l[1]},
		{7,  &l[2]},
		{9,  &l[3]},
		{12, &l[4]},
		{15, &l[5]},
		{17, NULL},
	};
	struct ListNode *node;
	node = removeNthFromEnd(l, 3);
	printf("[");
	while (node) {
		printf("%d,", node->val);
		node = node->next;
	}
	printf("]\n");
}

void test_case_1()
{
	struct ListNode l[1] = {
		{2, NULL},
	};
	struct ListNode *node;
	node = removeNthFromEnd(l, 1);
	printf("[");
	while (node) {
		printf("%d,", node->val);
		node = node->next;
	}
	printf("]\n");
}

void test_case_2()
{
	struct ListNode l[6] = {
		{5,  &l[1]},
		{5,  &l[2]},
		{6,  &l[3]},
		{12, &l[4]},
		{15, &l[5]},
		{17, NULL},
	};
	struct ListNode *node;
	node = removeNthFromEnd(l, 6);
	printf("[");
	while (node) {
		printf("%d,", node->val);
		node = node->next;
	}
	printf("]\n");
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	test_case_2();
	return 0;
}
