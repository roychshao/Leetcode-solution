/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** ans;
int idx = 0;

bool valid(int len, char* list)
{
    int counter = 0;
    for (int i = 0; i < len; ++i)
    {
        counter += (list[i] == '(') ? 1 : -1;
        if (counter < 0)
            return false;
    }
    if (counter != 0)
        return false;
    return true;
}

void search(char* list, int len, int depth)
{
    if (depth == len)
    {
        if (valid(len, list))
        {
            for (int i = 0; i < len; ++i)
                ans[idx][i] = list[i];
            ans[idx][len] = '\0';
            idx++;
        }
    }
    else
    {
        list[depth] = '(';
        search(list, len, depth + 1);
        list[depth] = ')';
        search(list, len, depth + 1);
    }
}


char** generateParenthesis(int n, int* returnSize)
{
    ans = (char**)malloc(2000 * sizeof(char*));
    for (int i = 0; i < 2000; ++i)
        ans[i] = (char*)malloc((1 + 2 * n) * sizeof(char));
    char list[20];
    idx = 0;
    search(list, (2 * n), 0);
    *returnSize = idx;
    return ans;
}
