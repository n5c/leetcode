#include <leetcode.h>

static int chk[2001];
static int chkGroup[1001];
int* findRedundantConnection(int** edges, int edgesRowSize, int edgesColSize,
		int* returnSize)
{
	int i, j, newGroup;
	int *conn;

	*returnSize = 2;
	conn = malloc(sizeof(*conn) * 2);
	memset(chk, 0, sizeof(chk));
	newGroup = 1;
	for (i = 0; i < edgesRowSize; i++) {
		if (chk[edges[i][0]] && chk[edges[i][1]]) {
			if (chkGroup[chk[edges[i][0]]] == chkGroup[chk[edges[i][1]]]) {
				conn[0] = edges[i][0];
				conn[1] = edges[i][1];
			} else {
				int tmp1, tmp2;
				if (chkGroup[chk[edges[i][0]]] < chkGroup[chk[edges[i][1]]]) {
					tmp1 = chkGroup[chk[edges[i][0]]];
					tmp2 = chkGroup[chk[edges[i][1]]];
				} else {
					tmp1 = chkGroup[chk[edges[i][1]]];
					tmp2 = chkGroup[chk[edges[i][0]]];
				}
				for (j = 0; j < newGroup; j++) {
					if (chkGroup[j] != tmp2)
						continue;
					chkGroup[j] = tmp1;
				}
			}
		} else if (!chk[edges[i][0]] && chk[edges[i][1]]) {
			chk[edges[i][0]] = chk[edges[i][1]];
		} else if (!chk[edges[i][1]] && chk[edges[i][0]]) {
			chk[edges[i][1]] = chk[edges[i][0]];
		} else /* new */ {
			chk[edges[i][0]] = newGroup;
			chk[edges[i][1]] = newGroup;
			chkGroup[newGroup] = newGroup;
			newGroup++;
		}
	}
	return conn;
}

void tc_0(void)
{
	int _edges[][2] = {{1,2},{1,3},{2,3}};
	int *edges[] = {_edges[0], _edges[1], _edges[2]};
	int edgesRowSize = sizeof(edges) / sizeof(*edges);
	int edgesColSize = 2;
	int returnSize;
	int *conn = findRedundantConnection(edges, edgesRowSize,
			edgesColSize, &returnSize);
	printf("2,3\n%d,%d\n\n", conn[0], conn[1]);
	free(conn);
}

void tc_1(void)
{
	int _edges[][2] = {{1,2},{1,3},{3,1}};
	int *edges[] = {_edges[0], _edges[1], _edges[2]};
	int edgesRowSize = sizeof(edges) / sizeof(*edges);
	int edgesColSize = 2;
	int returnSize;
	int *conn = findRedundantConnection(edges, edgesRowSize,
			edgesColSize, &returnSize);
	printf("3,1\n%d,%d\n\n", conn[0], conn[1]);
	free(conn);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

