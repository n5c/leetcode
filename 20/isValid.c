#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

int isValid(char* s) {
	int valid = 1;
	struct ListNode *head, *node;

	head = NULL;
	while (*s) {
		if ((*s == '(') || (*s == '{') || (*s == '[')) {
			node = malloc(sizeof(struct ListNode));
			node->val = *s;
			node->next = head;
			head = node;
		} else if ((*s == ')') || (*s == '}') || (*s == ']')) {
			if (!head || (head->val != ((*s == ')') ? '(' :
						    (*s == '}') ? '{' :
						    (*s == ']') ? '[' : 0))) {
				valid = 0;
				break;
			} else {
				node = head;
				head = head->next;
				free(node);
			}
		}
		s++;
	}

	if (head) {
		valid = 0;
		while (head) {
			node = head;
			head = head->next;
			free(node);
		}
	}

	return valid;
}

void test_case_0(void)
{
	printf("%d\n", isValid("([])"));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

