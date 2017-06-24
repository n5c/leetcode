#include <leetcode.h>

char** findWords(char** words, int wordsSize, int* returnSize)
{
	int i, j;
	int chk[] = {
		1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2
	};
	int record[3];
	char **returnWords;

	returnWords = malloc(sizeof(*returnWords) * wordsSize);
	*returnSize = 0;
	for (i = 0; i < wordsSize; i++) {
		record[0] = 0;
		record[1] = 0;
		record[2] = 0;

		for (j = 0; words[i][j]; j++)
			record[chk[
				words[i][j] >= 'a' ?
					words[i][j] - 'a' :
					words[i][j] - 'A']] = 1;

		if (record[0] + record[1] + record[2] == 1)
			returnWords[(*returnSize)++] = strdup(words[i]);
	}

	return returnWords;
}

void tc_0(void)
{
	char *words[] = {"Hello","Alaska","Dad","Peace"};
	int wordsSize = sizeof(words)/sizeof(*words);
	int returnSize;
	char **returnWords = findWords(words, wordsSize, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(", ");
		printf("%s", returnWords[i]);
		free(returnWords[i]);
	}
	printf("\n");
	free(returnWords);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

