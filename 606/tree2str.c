#include <leetcode.h>

char *tree2str2(struct TreeNode *t, int *len)
{
	int _len, llen, rlen;
	char *str, fmt[40], mfmt[16], lfmt[16], rfmt[16], *lstr, *rstr;

	if (!t || !len) {
		str = malloc(sizeof(*str) * 1);
		str[0] = 0;
		return str;
	}

	*len = snprintf(mfmt, 16, "%d", t->val);

	llen = 0;
	lstr = NULL;
	if (t->left)
		lstr = tree2str2(t->left, &llen);

	rlen = 0;
	rstr = NULL;
	if (t->right)
		rstr = tree2str2(t->right, &rlen);

	lfmt[0] = 0;
	if (lstr || rstr) {
		*len += llen + 2;
		lfmt[0] = '(';
		lfmt[1] = '%';
		lfmt[2] = 's';
		lfmt[3] = ')';
		lfmt[4] = 0;
	} else {
		lfmt[0] = '%';
		lfmt[1] = 's';
		lfmt[2] = 0;
	}

	rfmt[0] = 0;
	if (rstr) {
		*len += rlen + 2;
		rfmt[0] = '(';
		rfmt[1] = '%';
		rfmt[2] = 's';
		rfmt[3] = ')';
		rfmt[4] = 0;
	}

	(*len)++;
	str = malloc(sizeof(*str) * *len);

	snprintf(fmt, 40, "%s%s%s", mfmt, lfmt, rfmt);
	snprintf(str, *len, fmt, lstr ? lstr : "", rstr ? rstr : "");

	if (lstr)
		free(lstr);
	if (rstr)
		free(rstr);

	return str;
}

char* tree2str(struct TreeNode* t) {
	int len;
	return tree2str2(t, &len);
}

void tc_0(void)
{
	struct TreeNode t[] = {
		{1,&t[1],&t[2]},
		{2,&t[3],NULL},
		{3,NULL,NULL},
		{4,NULL,NULL},
	};
	char *str = tree2str(&t[0]);
	printf("%s\n", str);
	free(str);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

