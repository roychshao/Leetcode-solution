class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        
        vector <vector <int>> dp (1+slen, vector <int> (1+plen));
        dp[0][0] = 1;
        
        for (int i=0; i<=slen; i++)
            for (int j=1; j<=plen; j++)
            {
                if (i && (s[i-1]==p[j-1] || p[j-1]=='?'))
                    dp[i][j] = dp[i-1][j-1];
                
                else if (p[j-1]=='*')
                    dp[i][j] = (dp[i][j-1] || (i && dp[i-1][j]));
            }
        
        return dp[slen][plen];
    }
};
