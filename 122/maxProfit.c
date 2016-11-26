int maxProfit(int* prices, int pricesSize)
{
	int i, j;
	int p, maxProfit;

	for (i = 1, p = prices[0], maxProfit = 0;
			i < pricesSize; i++) {
		if (prices[i - 1] > prices[i]) {
			maxProfit += prices[i - 1] - p;
			p = prices[i];
		}
	}

	maxProfit += prices[i - 1] - p;

	return maxProfit;
}
