int min(int a, int b, int c)
{
    int tmp = a;
    tmp = (b < tmp) ? b : tmp;
    tmp = (c < tmp) ? c : tmp;
    return tmp;
}

int minDistance(char * word1, char * word2)
{
	int dp[505][505];
	int len1 = strlen(word1), len2 = strlen(word2);
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<=len1;++i)
		dp[i][0] = i;
	for(int i=0;i<=len2;++i)
		dp[0][i] = i;
	for(int i=0;i<len1;++i)
	{
		for(int j=0;j<len2;++j)
		{
			if(word1[i] != word2[j])
				dp[i+1][j+1] = 1 + min(dp[i][j], dp[i+1][j], dp[i][j+1]);
			else
				dp[i+1][j+1] = dp[i][j];
		}
	}
	return dp[len1][len2];
}
