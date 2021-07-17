
int maxProfit(int* prices, int pricesSize)
{
    int i = 0;
    int peak = prices[0], valley = prices[0];
    int maxprofit = 0;
    while(i < pricesSize - 1)
    {
        //  find valley
        while(i < pricesSize - 1 && prices[i] >= prices[i+1])
            i++;
        valley = prices[i];
        //  find peak
        while(i < pricesSize - 1 && prices[i] <= prices[i+1])
            i++;
        peak = prices[i];
        //  maxprofit += peak - valley
        maxprofit += (peak - valley);
    }
    return maxprofit;
}
