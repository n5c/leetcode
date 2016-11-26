#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numberOfBoomerangs(int** points, int pointsRowSize, int pointsColSize)
{
	struct dist_st {
		int val;
		int point1;
		int point2;
	};
	int i, j, k, l, distsz, sum;
	struct dist_st *dist;

	distsz = (pointsRowSize * (pointsRowSize - 1) / 2);
	dist = calloc(sizeof(*dist), distsz);

	for (i = 0, k = 0; i < (pointsRowSize - 1); i++) {
		for (j = (i + 1); j < pointsRowSize; j++) {
			dist[k].val = pow((double)(points[i][0] - points[j][0]), (double)2) +
				pow((double)(points[i][1] - points[j][1]), (double)2);
			dist[k].point1 = i;
			dist[k].point2 = j;
			k++;
			if (k >= distsz) {
				printf("oops: %d, %d, %d\n", k, i, j);
				//break;
			}
		}
	}

	int cmp(const void *a, const void *b) {
		const struct dist_st *da = a;
		const struct dist_st *db = b;
		return (da->val - db->val);
	}

	qsort(dist, distsz, sizeof(*dist), cmp);

	sum = 0;
	for (i = 1; i < distsz; i++) {
		if (dist[i].val != dist[i - 1].val)
			continue;
		j = i + 1;
		while ((j < distsz) && (dist[j].val == dist[i].val)) j++;

		for (k = (i - 1); k < (j - 1); k++) {
			for (l = (k + 1); l < j; l++) {
				if ((dist[k].point1 != dist[l].point1) &&
						(dist[k].point1 != dist[l].point2) &&
						(dist[k].point2 != dist[l].point1) &&
						(dist[k].point2 != dist[l].point2))
					continue;
				/* printf("%d: %d, %d == %d: %d, %d\n",
				 *                     k, dist[k].point1, dist[k].point2,
				 *                                         l, dist[l].point1, dist[l].point2); */
				sum += 2;
			}
		}
		i = j;
	}

	free(dist);

	return sum;
}

void test_case_0()
{
	int _points[][2] = {
		{0,0}, {1,0}, {2,0}
	};
	int *points[] = {
		_points[0],
		_points[1],
		_points[2]
	};
	int pointsRowSize = sizeof(points)/sizeof(*points);
	int pointsColSize = sizeof(**points) * 2;

	printf("2\n");
	printf("%d\n\n", numberOfBoomerangs(points, pointsRowSize, pointsColSize));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

