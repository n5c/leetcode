#include <leetcode.h>

bool isPalindrome(struct ListNode* head)
{
	int count, mid, abandonfirst;
	struct ListNode *node, *prev, *next, *node2;

	if (!head || !head->next)
		return true;

	count = 0;
	node = head;
	while (node) {
		node = node->next;
		count++;
	}

	abandonfirst = ((count & 1) ? 1 : 0);

	mid = ((count + 1) >> 1);
	count = 1;
	prev = head;
	node = head->next;
	prev->next = NULL;
	while (count < mid) {
		next = node->next;
		node->next = prev;
		prev = node;
		node = next;
		count++;
	}

	node2 = node;
	node = prev;
	if (abandonfirst)
		node = prev->next;

	while (node && node2) {
		if (node->val != node2->val)
			break;
		node = node->next;
		node2 = node2->next;
	}

	if (node || node2)
		return false;

	return true;
}

void tc_0(void)
{
	struct ListNode l[] = {
		{1,&l[1]},
		{2,&l[2]},
		{2,&l[3]},
		{1,NULL},
	};
	printf("true\n%s\n",
		isPalindrome(l) ? "true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

