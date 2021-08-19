
int Valid(char tens, char digits)
{
    int value = 10 * (int)(tens - '0') + (int)(digits - '0');
    return (value > 26 || value < 10) ? false : true;
}

int numDecodings(char * s)
{
    if(s[0] == '0') return 0;
    int dp[101] = { 0 }, len = strlen(s);
    dp[0] = 1;
    for(int i = 1;i <= len;++i)
    {
        if(s[i-1] != '0')
            dp[i] += dp[i-1];
        else
            dp[i] = 0;
        if(i > 1 && Valid(s[i-2], s[i-1]))
            dp[i] += dp[i-2];
    }
    puts(dp);
    return dp[len];
}
