#include <leetcode.h>

bool isSubtree2(struct TreeNode *s, struct TreeNode *t, bool furtherchk)
{
	int chk;
	if (s->val != t->val) {
		if (furtherchk) {
			if (s->left && isSubtree2(s->left, t, true))
				return true;
			if (s->right && isSubtree2(s->right, t, true))
				return true;
		}
		return false;
	}

	if (furtherchk) {
		chk = false;
		if (s->left) {
			if (t->left && isSubtree2(s->left, t->left, false))
				chk = true;
			if (isSubtree2(s->left, t, true))
				return true;
		} else { /* !s->left */
			if (!t->left)
				chk = true;
		}

		if (chk) {
			if (s->right) {
				if (t->right && isSubtree2(s->right, t->right, false))
					return true;
			} else { /* !s->right */
				if (!t->right)
					return true;
			}
		}

		if (s->right && isSubtree2(s->right, t, true))
			return true;

	} else { /* !furtherchk */
		chk = false;
		if (s->left && t->left) {
			if (isSubtree2(s->left, t->left, false))
				chk = true;
		} else if (!s->left && !t->left) {
			chk = true;
		}

		if (chk) {
			if (s->right && t->right) {
				if (isSubtree2(s->right, t->right, false))
					return true;
			} else if (!s->right && !t->right) {
				return true;
			}
		}
	}

	return false;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	return isSubtree2(s, t, true);
}

void tc_0(void)
{
	struct TreeNode s[] = {
		{3, &s[1], &s[2]},
		{4, &s[3], &s[4]},
		{5, NULL, NULL},
		{1, NULL, NULL},
		{2, NULL, NULL},
	};
	struct TreeNode t[] = {
		{4, &t[1], &t[2]},
		{1, NULL, NULL},
		{2, NULL, NULL},
	};
	char *boolstr[] = {"false", "true"};
	printf("true\n%s\n\n",
		boolstr[!!isSubtree(s, t)]);
}

void tc_1(void)
{
	struct TreeNode s[] = {
		{3, &s[1], &s[2]},
		{4, &s[3], &s[4]},
		{5, NULL, NULL},
		{1, &s[5], NULL},
		{2, NULL, NULL},
		{0, NULL, NULL}
	};
	struct TreeNode t[] = {
		{4, &t[1], &t[2]},
		{1, NULL, NULL},
		{2, NULL, NULL},
	};
	char *boolstr[] = {"false", "true"};
	printf("false\n%s\n\n",
		boolstr[!!isSubtree(s, t)]);
}

void tc_2(void)
{
	struct TreeNode s[] = {
		{1, &s[1], NULL},
		{1, NULL, NULL},
	};
	struct TreeNode t[] = {
		{1, NULL, NULL},
	};
	char *boolstr[] = {"false", "true"};
	printf("true\n%s\n\n",
		boolstr[!!isSubtree(s, t)]);
}

void tc_3(void)
{
	struct TreeNode s[] = {
		{1, &s[1], &s[2]},
		{2, NULL, NULL},
		{3, NULL, NULL},
	};
	struct TreeNode t[] = {
		{2, &t[1], NULL},
		{3, NULL, NULL},
	};
	char *boolstr[] = {"false", "true"};
	printf("false\n%s\n\n",
		boolstr[!!isSubtree(s, t)]);
}

void tc_4(void)
{
	struct TreeNode s[] = {
		{1, &s[1], &s[2]},
		{2, NULL, NULL},
		{3, NULL, NULL},
	};
	struct TreeNode t[] = {
		{1, &t[1], NULL},
		{2, NULL, NULL},
	};
	char *boolstr[] = {"false", "true"};
	printf("false\n%s\n\n",
		boolstr[!!isSubtree(s, t)]);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	tc_3();
	tc_4();
	return 0;
}

