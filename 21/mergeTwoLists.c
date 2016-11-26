#include <stdio.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

/**
 *  Definition for singly-linked list.
 *  struct ListNode {
 *      int val;
 *      struct ListNode *next;
 *  };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *root, *node;

	if (l1 && (!l2 || (l1->val <= l2->val))) {
		root = l1;
		l1 = l1->next;
		root->next = NULL;
	} else if (l2) {
		root = l2;
		l2 = l2->next;
		root->next = NULL;
	} else {
		return NULL;
	}

	node = root;

	while (l1 && l2) {
		if (l1->val <= l2->val) {
			node->next = l1;
			node = node->next;
			l1 = l1->next;
		} else {
			node->next = l2;
			node = node->next;
			l2 = l2->next;
		}
	}

	if (l1)
		node->next = l1;
	else if (l2)
		node->next = l2;

	return root;
}

void test_case_0()
{
	struct ListNode l1[6] = {
		{3,  &l1[1]},
		{7,  &l1[2]},
		{9,  &l1[3]},
		{12, &l1[4]},
		{15, &l1[5]},
		{17, NULL},
	};
	struct ListNode l2[4] = {
		{4,  &l2[1]},
		{4,  &l2[2]},
		{4,  &l2[3]},
		{19, NULL},
	};
	struct ListNode *node;
	node = mergeTwoLists(l1, l2);
	while (node) {
		printf("%d, ", node->val);
		node = node->next;
	}
	printf("\n");
}

void test_case_1()
{
	struct ListNode l1[1] = {
		{2, NULL},
	};
	struct ListNode l2[1] = {
		{1, NULL},
	};
	struct ListNode *node;
	node = mergeTwoLists(l1, l2);
	while (node) {
		printf("%d, ", node->val);
		node = node->next;
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	return 0;
}
