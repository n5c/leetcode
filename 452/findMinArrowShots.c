#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findMinArrowShots(int** points, int pointsRowSize, int pointsColSize)
{
	int i, j, balls, shots;
	struct pos_st {
		int pos;
		int lr; /* left or right */
		int idx;
	};

	struct pos_st *pos = malloc(sizeof(*pos) * pointsRowSize * 2);

	for (i = 0, j = 0; i < pointsRowSize; i++) {
		pos[j].pos = points[i][0];
		pos[j].lr = 0;
		pos[j].idx = i;
		pos[j + 1].pos = points[i][1];
		pos[j + 1].lr = 1;
		pos[j + 1].idx = i;
		j += 2;
	}

	int cmp(const void *a, const void *b) {
		const struct pos_st *pa = a;
		const struct pos_st *pb = b;
		if (pa->pos == pb->pos)
			return (pa->lr - pb->lr);
		return (pa->pos - pb->pos);
	}

	qsort(pos, (pointsRowSize * 2), sizeof(*pos), cmp);

	/* for (i = 0; i < (pointsRowSize * 2); i++) {
	 *         printf("%d: %d: %d\n", pos[i].idx, pos[i].lr, pos[i].pos);
	 *             } */

	pointsRowSize <<= 1;
	shots = 0;
	balls = 0;
	for (i = 0; i < pointsRowSize; i++) {
		if (pos[i].lr == 0) {
			//printf("%d: %d\n", pos[i].idx, pos[i].lr);
			if (!balls) {
				//printf("shots\n");
				balls++;
				shots++;
			}
			points[pos[i].idx][0] = shots;
			points[pos[i].idx][1] = -1;
		} else {
			//printf("%d: %d\n", pos[i].idx, pos[i].lr);
			if ((points[pos[i].idx][0] > points[pos[i].idx][1]) &&
					(shots == points[pos[i].idx][0])) {
				//printf("balls reset\n");
				balls = 0;
			}
		}
	}

	free(pos);

	return shots;
}


int main(int argc, char *argv[])
{
	int points[][2] = {
		{10,16},{2,8},{1,6},{7,12},{13,14},{13,17},{13,19}
	};
	int *_points[] = {
		points[0],
		points[1],
		points[2],
		points[3],
		points[4],
		points[5],
		points[6],
		points[7]
	};
	int pointsRowSize = sizeof(points)/(sizeof(int)*2);
	int pointsColSize = 2;
	printf("%d\n", findMinArrowShots(_points, pointsRowSize, pointsColSize));

	return 0;
}
