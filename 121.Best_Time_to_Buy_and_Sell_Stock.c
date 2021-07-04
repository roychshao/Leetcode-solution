#define MAX(a,b) (a>b)?a:b

int maxProfit(int* prices, int pricesSize)
{
    int maxprofit = 0, temp = prices[0];
    for(int i=1;i<pricesSize;++i)
    {
        if(prices[i] > temp)
            maxprofit = MAX(maxprofit , (prices[i] - temp));
        else
            temp = prices[i];
    }
    return maxprofit;
}
