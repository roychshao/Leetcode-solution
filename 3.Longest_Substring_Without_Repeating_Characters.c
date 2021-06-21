int lengthOfLongestSubstring(char * s)
{
    int check[200], len = strlen(s);
    int maxlen = 0, i,j;
    memset(check,0,sizeof(check));
    for(i=0;i<len;++i)
    {
        check[s[i] - ' '] = 1;
        for(j=i+1;j<len;++j)
        {
            if(check[s[j] - ' '])
                break;
            else
                check[s[j] - ' '] = 1;
        }
        maxlen = ((j-i)>maxlen) ? (j-i) : maxlen;
        memset(check,0,sizeof(check));
    }
    return maxlen;
}
