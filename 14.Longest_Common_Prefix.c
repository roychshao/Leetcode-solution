

char * longestCommonPrefix(char ** strs, int strsSize)
{
    char *ans = (char*)malloc(500 * sizeof(char));
    char *zero = (char*)malloc(500 * sizeof(char));
    memset(zero, 0 ,sizeof(char) * 500);
    strcpy(ans, strs[0]);
    int i = 1, len, idx;
    while(i < strsSize)
    {
        if(strcmp(ans, zero) == 0)
            return zero;
        len = (strlen(strs[i]) < strlen(ans)) ? strlen(strs[i]) : strlen(ans) ;
        idx = 0;
        for(int j = 0; j < len; ++j)
        {
            if(strs[i][j] == ans[j])
                idx++;
            else
                break;
        }
        memset(ans, 0, sizeof(ans));
        strncat(ans, strs[i], idx);
        i++;
    }
    return ans;
}
