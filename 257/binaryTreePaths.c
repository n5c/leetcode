#include <leetcode.h>

char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
	struct TreeNode *node;
	struct TreeNode **stack;
	char **btp;
	int i, j, stackSize;

	j = 0;
	btp = NULL;
	*returnSize = 0;
	if (!root)
		return NULL;

	i = 0;
	stackSize = 10;
	stack = malloc(sizeof(*stack) * stackSize);
	node = root;
	while (i >= 0) {
		if (i >= stackSize) {
			stackSize += 10;
			stack = realloc(stack, sizeof(*stack) * stackSize);
		}
		stack[i++] = node;

		if (node->left) {
			node = node->left;
		} else if (node->right) {
			node = node->right;
		} else {
			int k, slen, slen1, si;
			char s[16];
			if (!*returnSize) {
				*returnSize = 10;
				btp = malloc(sizeof(*btp) * *returnSize);
			} else if (j >= *returnSize) {
				*returnSize += 10;
				btp = realloc(btp, sizeof(*btp) * *returnSize);
			}

			slen = 16;
			btp[j] = malloc(sizeof(**btp) * slen);
			snprintf(btp[j], slen, "%d", stack[0]->val);

			for (k = 1, si = strlen(btp[j]); k < i; k++) {
				snprintf(s, 16, "->%d", stack[k]->val);
				slen1 = strlen(s);
				if (si + slen1 >= slen) {
					slen += slen1 + 16;
					btp[j] = realloc(btp[j], sizeof(**btp) * slen);
				}
				strcat(&btp[j][si], s);
				btp[j][si + slen1] = 0;
				si += slen1;
			}

			for (k = i - 2; k >= 0; k--) {
				if (stack[k]->right && stack[k]->right != stack[k + 1]) {
					node = stack[k]->right;
					k = k + 1;
					break;
				}
			}
			i = k;
			j++;
		}
	}

	free(stack);

	*returnSize = j;
	return btp;
}

void print(char **btp, int size)
{
	for (int i = 0; i < size; i++)
		printf("%s\n", btp[i]);
	printf("\n");
}

void tc_0(void)
{
	struct TreeNode t[] = {
		{1,&t[1],&t[2]},
		{2,NULL, &t[3]},
		{3,NULL, NULL},
		{5,NULL, NULL}
	};
	int size;
	char **btp;
	btp = binaryTreePaths(t, &size);
	print(btp, size);
	for (int i = 0; i < size; i++)
		free(btp[i]);
	free(btp);
}

void tc_1(void)
{
	struct TreeNode t[] = {
		{1,&t[1],&t[2]},
		{2,NULL, &t[3]},
		{3,&t[4],&t[5]},
		{5,&t[6], NULL},
		{6,&t[7], NULL},
		{7,&t[8], &t[9]},
		{8,&t[10],&t[11]},
		{9,NULL, &t[12]},
		{10,&t[13], NULL},
		{11,NULL, &t[14]},
		{12,NULL, &t[15]},
		{13,&t[16],&t[17]},
		{14,&t[18], NULL},
		{15,NULL, NULL},
		{16,NULL, NULL},
		{17,&t[19], NULL},
		{18,NULL, NULL},
		{19,NULL, NULL},
		{20,NULL, NULL},
		{21,&t[20], NULL},
		{22,&t[21], NULL},
		{23,&t[22], NULL},
		{24,&t[23], NULL},
		{25,NULL, NULL}
	};
	int size;
	char **btp;
	btp = binaryTreePaths(t, &size);
	print(btp, size);
	for (int i = 0; i < size; i++)
		free(btp[i]);
	free(btp);
}

int main(int argc, char *argv[])
{
	//tc_0();
	tc_1();
	return 0;
}

