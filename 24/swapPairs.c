#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

void print_list(struct ListNode *);

struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode *node, **next;

	node = head;
	if (node && node->next) {
		head = node->next;
		node->next = head->next;
		head->next = node;
	} else {
		return head;
	}

	next = &head->next->next;
	while (*next && (*next)->next) {
		node = (*next)->next;
		(*next)->next = node->next;
		node->next = *next;
		*next = node;
		next = &((*next)->next->next);
	}

	return head;
}

void print_list(struct ListNode *head)
{
	struct ListNode *node = head;
	while (node) {
		printf("%d, ", node->val);
		node = node->next;
	}
	printf("\n");
}

void test_case_0(void)
{
	struct ListNode l[7] = {
		{1, &l[1]},
		{2, &l[2]},
		{3, &l[3]},
		{4, &l[4]},
		{5, &l[5]},
		{6, &l[6]},
		{7, NULL}
	};
	print_list(swapPairs(l));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

