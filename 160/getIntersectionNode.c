#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode *next;
 };

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	struct ListNode *nodeA, *nodeB;
	int lenA, lenB;

	nodeA = headA;
	lenA = 0;
	while (nodeA && nodeA->next) {
		lenA++;
		nodeA = nodeA->next;
	}

	nodeB = headB;
	lenB = 0;
	while (nodeB && nodeB->next) {
		lenB++;
		nodeB = nodeB->next;
	}

	if (nodeA != nodeB)
		return NULL;

	nodeA = headA;
	nodeB = headB;
	while (nodeA && nodeB) {
		if (lenA > lenB) {
			lenA--;
			nodeA = nodeA->next;
		} else if (lenA < lenB) {
			lenB--;
			nodeB = nodeB->next;
		} else {
			break;
		}
	}

	while (nodeA && nodeB) {
		if (nodeA == nodeB)
			return nodeA;
		nodeA = nodeA->next;
		nodeB = nodeB->next;
	}

	return NULL;
}

void test_case_0(void)
{
	struct ListNode lA[] = {
		{1, &lA[1]},
		{2, &lA[2]},
		{3, &lA[3]},
		{4, &lA[4]},
		{5, NULL},
	};
	struct ListNode lB[] = {
		{6, &lB[1]},
		{7, &lB[2]},
		{8, &lB[3]},
		{9, &lA[4]},
	};
	struct ListNode *node;

	printf("5:\n");
	node = getIntersectionNode(lA, lB);
	printf("%d\n\n", (node ? node->val : 0));
}

void test_case_1(void)
{
	struct ListNode lA[] = {
		{1, &lA[1]},
		{2, &lA[2]},
		{3, &lA[3]},
		{4, &lA[4]},
		{5, NULL},
	};
	struct ListNode lB[] = {
		{6, &lB[1]},
		{7, &lB[2]},
		{8, &lB[3]},
		{9, &lA[0]},
	};
	struct ListNode *node;

	printf("1:\n");
	node = getIntersectionNode(lA, lB);
	printf("%d\n\n", (node ? node->val : 0));
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	return 0;
}

