int dp[1000][1000];

int judge(char* s, int j, int i)
{
    if (i == j)
    {
        dp[i][j] = 1;
        return 1;
    }
    if (j == (i - 1))
    {
        if (s[j] == s[i])
        {
            dp[i][j] = 1;
            return 1;
        }
        else
            return 0;
    }
    if (dp[i - 1][j + 1] == 1 && s[i] == s[j])
    {
        dp[i][j] = 1;
        return 1;
    }
    else
        return 0;
}

char * longestPalindrome(char* s)
{
    int len = strlen(s);
    int left = 0, right = 0, maxlen = 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            //  if s[j] ~ s[i] is palindrome.
            if (judge(s, j, i))
            {
                if ((i - j) > maxlen)
                {
                    maxlen = (i - j);
                    left = j, right = i;
                }
            }
        }
    }
    char *ans = (char*)malloc((maxlen+2)*sizeof(char));
    for(int i=left,j=0;i<=right;i++,j++)
        ans[j] = s[i];
    ans[maxlen+1] = '\0';
    return ans;
}
