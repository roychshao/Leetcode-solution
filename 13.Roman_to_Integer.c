int Rindex(char c, char * s)
{
    for(int i=0;i<7;++i)
    {
        if(c == s[i])
            return i;
    }
    return -1;
}

int romanToInt(char * s)
{
    char Roman[8] = {'I','V','X','L','C','D','M'};
    int Integer[7] = {1,5,10,50,100,500,1000};
    int pre = -1,ans = 0,temp;
    for(int i = strlen(s) - 1;i >= 0;--i)
    {
        temp = Rindex(s[i],Roman);
        if(temp < pre)
            ans -= Integer[temp];
        else
            ans += Integer[temp];
        pre = temp;
    }
    return ans;
}
