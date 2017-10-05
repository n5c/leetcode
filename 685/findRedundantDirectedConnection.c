#include <leetcode.h>

static int chksets[1001];
int* findRedundantDirectedConnection(int** edges, int edgesRowSize, int edgesColSize, int* returnSize)
{
	int i, node, errEdge[2] = {0}, *conn;

	*returnSize = 2;
	conn = calloc(sizeof(*conn), *returnSize);

	memset(chksets, 0, sizeof(*chksets) * (edgesRowSize + 1));

	for (i = 0; i < edgesRowSize; ++i) {
		if (!chksets[edges[i][1]]) {
			node = edges[i][0];
			while (chksets[node]) {
				if ((chksets[node] == edges[i][0]) ||
						(chksets[node] == edges[i][1]))
					break;
				node = chksets[node];
			}
			if (chksets[node] && !conn[0]) {
				conn[0] = edges[i][0];
				conn[1] = edges[i][1];
			}
			chksets[edges[i][1]] = edges[i][0];
		} else {
			conn[0] = edges[i][0];
			conn[1] = edges[i][1];
			errEdge[0] = chksets[edges[i][1]];
			errEdge[1] = edges[i][1];
		}
	}

	node = errEdge[0];
	while (chksets[node]) {
		if (chksets[node] == errEdge[0]) {
			conn[0] = errEdge[0];
			conn[1] = errEdge[1];
			break;
		}
		node = chksets[node];
	}

	return conn;
}

void tc_0(void)
{
	int __edges[][2] = {{2,1},{3,1},{4,2},{1,4}};
	int *edges[] = {__edges[0], __edges[1], __edges[2], __edges[3]};
	int edgesRowSize = sizeof(__edges) / sizeof(*__edges);
	int edgesColSize = sizeof(*__edges) / sizeof(**__edges);
	int returnSize;
	int *conn = findRedundantDirectedConnection(edges, edgesRowSize,
			edgesColSize, &returnSize);
	printf("2,1\n%d,%d\n\n", conn[0], conn[1]);
	free(conn);
}

void tc_1(void)
{
	int __edges[][2] = {{3,4},{4,1},{1,2},{2,3},{5,1}};
	int *edges[] = {__edges[0],__edges[1],__edges[2],__edges[3],__edges[4]};
	int edgesRowSize = sizeof(__edges) / sizeof(*__edges);
	int edgesColSize = sizeof(*__edges) / sizeof(**__edges);
	int returnSize;
	int *conn = findRedundantDirectedConnection(edges, edgesRowSize,
			edgesColSize, &returnSize);
	printf("4,1\n%d,%d\n\n", conn[0], conn[1]);
	free(conn);
}

void tc_2(void)
{
	int __edges[][2] = {{1,2},{1,3},{2,3}};
	int *edges[] = {__edges[0], __edges[1], __edges[2]};
	int edgesRowSize = sizeof(__edges) / sizeof(*__edges);
	int edgesColSize = sizeof(*__edges) / sizeof(**__edges);
	int returnSize;
	int *conn = findRedundantDirectedConnection(edges, edgesRowSize,
			edgesColSize, &returnSize);
	printf("2,3\n%d,%d\n\n", conn[0], conn[1]);
	free(conn);
}

void tc_3(void)
{
	int __edges[][2] = {{1,2},{2,3},{3,4},{4,1},{1,5}};
	int *edges[] = {__edges[0], __edges[1], __edges[2], __edges[3], __edges[4]};
	int edgesRowSize = sizeof(__edges) / sizeof(*__edges);
	int edgesColSize = sizeof(*__edges) / sizeof(**__edges);
	int returnSize;
	int *conn = findRedundantDirectedConnection(edges, edgesRowSize,
			edgesColSize, &returnSize);
	printf("4,1\n%d,%d\n\n", conn[0], conn[1]);
	free(conn);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	tc_3();
	return 0;
}

