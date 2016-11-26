#include <stdio.h>

#define bool int
#define true 1
#define false 0

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
	struct ListNode *node, *chk;
	int count = 0;

	chk = node = head;
	while (node) {
		if (count & 1)
			chk = chk->next;
		count++;
		node = node->next;
		if (chk == node)
			return true;
	}

	return false;
}

void test_case_0()
{
	struct ListNode l[] = {
		{0, &l[1]},
		{1, &l[2]},
		{2, &l[3]},
		{3, &l[4]},
		{4, &l[5]},
		{5, &l[6]},
		{6, &l[3]},
	};

	printf("1\n");
	printf("%d\n\n", hasCycle(l));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

