#include <stdio.h>
#include <string.h>

int head, tail;

int check(char* str, int len, int i)
{
    head = i - 1, tail = i + 1;
    if (head < 0 && str[i] == str[tail]) return 2;
    else if(head < 0 && str[i] != str[tail])
    {
        head = tail = i;
        return 1;
    }
    if (tail >= len && str[i] == str[head])  return 2;
    else if( tail >= len && str[i] != str[head])
    {
        tail = head = i;
        return 1;
    }
    if (str[head] != str[tail])
    {
        if (str[head] == str[i])
        {
            head--;
        }
        else if (str[tail] == str[i])
        {
            tail++;
        }
        else
        {
            head = tail;
            return 1;
        }
    }
    while (str[head] == str[tail] && head >= 0 && tail < len)
    {
        head--, tail++;
    }
    head++, tail--;
    return (tail - head + 1);
}


int main()
{
    char str[1000];
    int temp = 0, ans = 0;
    int left = 0, right = 0;
    fgets(str, 1000, stdin);
    int len = strlen(str) - 1;
    for (int i = 0; i < len; ++i)
    {
        temp = check(str, len, i);
        if (temp > ans)
        {
            ans = temp;
            left = head, right = tail;
        }
    }
    for (int i = left; i <= right; ++i)
    {
        printf("%c", str[i]);
    }
    return 0;
}
