#define MAX(a,b) (a > b) ? a : b
#define MIN(a,b) (a < b) ? a : b

int left[100000], right[100000];

int maxProfit(int* prices, int pricesSize)
{
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    int minPrice = prices[0], maxPrice, maxProfit = 0;
    for(int i = 1 ;i < pricesSize; ++i)
    {
        maxProfit = MAX(maxProfit, prices[i] - minPrice);
        minPrice = MIN(minPrice, prices[i]);
        left[i] = maxProfit;
    }
    maxProfit = 0, maxPrice = prices[pricesSize-1];
    int totalMax = 0;
    for(int i = pricesSize-1; i >=0; --i)
    {
        maxProfit = MAX(maxProfit, maxPrice - prices[i]);
        maxPrice = MAX(maxPrice, prices[i]);
        right[i] = maxProfit;
        totalMax = MAX(totalMax, left[i] + right[i]);
    }
    return totalMax;
}
