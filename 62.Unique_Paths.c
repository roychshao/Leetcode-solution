int uniquePaths(int m, int n)
{
    int dp[100][100];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;++i)
        dp[0][i] = 1;
    for(int i=1;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}
