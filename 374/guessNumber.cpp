// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
	public:
		int guessNumber(int n) {
			int min, max, ret, gnum;
			min = 1;
			max = n;
			do {
				gnum = (((unsigned int)min + (unsigned int)max) / 2);
				ret = guess(gnum);
				if (ret == 1) {
					min = gnum + 1;
				} else if (ret == -1) {
					max = gnum - 1;
				} else {
				}
			} while (ret);

			return gnum;
		}
};

