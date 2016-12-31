#include <leetcode.h>

struct trie {
	char mapto;
	struct trie *next[26];
};

void freeTrie(struct trie *node)
{
	int i;
	for (i = 0; i < 26; i++) {
		if (node->next[i])
			freeTrie(node->next[i]);
		free(node->next[i]);
	}
}

bool wordPattern(char* pattern, char* str)
{
	int i, j, idx;
	bool check = true;
	bool isUsed[26] = {false};
	struct trie *node;
	struct trie root = {0};

	for (i = 0, j = 0, node = NULL; str[i] && pattern[j]; i++) {
		if (str[i] == ' ') {
			if (!node->mapto) {
				if (isUsed[pattern[j] - 'a'] == true) {
					check = false;
					break;
				}
				node->mapto = pattern[j];
				isUsed[pattern[j] - 'a'] = true;
			} else if (node->mapto != pattern[j]) {
				check = false;
				break;
			}
			j++;
			node = NULL;
			continue;
		}

		idx = str[i] - 'a';

		if (!node) {
			node = root.next[idx];
			if (!node) {
				node = calloc(1, sizeof(*node));
				root.next[idx] = node;
			}
			continue;
		}

		if (!node->next[idx])
			node->next[idx] = calloc(1, sizeof(*node));
		node = node->next[idx];
	}

	if (str[i])
		check = false;
	if (check == true && node) {
		if (!node->mapto) {
			if (isUsed[pattern[j] - 'a'] == true)
				check = false;
		} else if (node->mapto != pattern[j])
			check = false;
		j++;
	}
	if (check == true && pattern[j])
		check = false;

	freeTrie(&root);

	return check;
}

void tc_0(void)
{
	char pattern[] = "abba";
	char str[] = "dog cat cat dog";
	printf("true\n");
	printf("%s\n\n", wordPattern(pattern, str) ? "true" : "false");
}

void tc_1(void)
{
	char pattern[] = "abba";
	char str[] = "dog cat";
	printf("false\n");
	printf("%s\n\n", wordPattern(pattern, str) ? "true" : "false");
}

void tc_2(void)
{
	char pattern[] = "ab";
	char str[] = "dog cat cat dog";
	printf("false\n");
	printf("%s\n\n", wordPattern(pattern, str) ? "true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	return 0;
}

