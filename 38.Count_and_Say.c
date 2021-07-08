
void turn(char *cur, char *pre)
{
    char last;
    int len = strlen(pre);
    int idx = 0, counter, cidx = 0;
    while(idx < len)
    {
        last = pre[idx];
        counter = 1;
        for(int i=idx+1;i<len;++i)
        {
            if(pre[i] == last)
                counter++;
            else
                break;
        }
        cur[cidx++] = (char)(counter + '0');
        cur[cidx++] = last;
        idx += counter;
    }
}

char * countAndSay(int n)
{
    int counter = 0;
    char *cur = (char*)malloc(4500 * sizeof(char));
    char *pre = (char*)malloc(4500 * sizeof(char));
    memset(cur, 0, sizeof(char)*4500);
    memset(pre, 0, sizeof(char)*4500);
    cur[0] = '1';
    while(counter < n)
    {
        turn(cur, pre);
        memcpy(pre, cur, sizeof(char)*4500);
        memset(cur, 0, sizeof(cur));
        counter++;
    }
    return pre;
}
