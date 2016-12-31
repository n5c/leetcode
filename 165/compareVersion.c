#include <leetcode.h>

int compareVersion(char* version1, char* version2)
{
	int i1, i2, j1, j2, diff;

	i1 = 0;
	i2 = 0;
	while (version1[i1] && version2[i2]) {
		j1 = i1;
		j2 = i2;
		while (version1[i1] && version1[i1] != '.' && version1[i1] == '0')
			version1++;
		while (version1[i1] && version1[i1] != '.') i1++;
		while (version2[i2] && version2[i2] != '.' && version2[i2] == '0')
			version2++;
		while (version2[i2] && version2[i2] != '.') i2++;

		diff = i1 - i2;
		if (diff)
			break;

		while (j1 < i1) {
			diff = version1[j1] - version2[j1];
			if (diff)
				break;
			j1++;
		}

		if (diff)
			break;

		if (!version1[i1] || !version2[i2])
			break;

		i1++;
		i2++;
	}

	if (diff > 0)
		diff = 1;
	else if (diff < 0)
		diff = -1;
	else {
		if (version1[i1]) {
			i1++;
			while (version1[i1] && (version1[i1] == '.' ||
						version1[i1] == '0')) version1++;
			if (version1[i1])
				diff = 1;
		} else if (version2[i2]) {
			i2++;
			while (version2[i2] && (version2[i2] == '.' ||
						version2[i2] == '0')) version2++;
			if (version2[i2])
				diff = -1;
		}
	}

	return diff;
}

void tc_0(void)
{
	char version1[] = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
	char version2[] = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
	printf("0\n");
	printf("%d\n\n", compareVersion(version1, version2));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

