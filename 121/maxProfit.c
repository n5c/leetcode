int maxProfit(int* prices, int pricesSize)
{
	int i, j, p, maxPrice = 0, maxProfit = 0;
	maxPrice = prices[pricesSize - 1];
	for (i = (pricesSize - 2); i >= 0; i--) {
		if (prices[i] > maxPrice) {
			maxPrice = prices[i];
			continue;
		}

		p = maxPrice - prices[i];
		if (p > maxProfit)
			maxProfit = p;
	}

	return maxProfit;
}

