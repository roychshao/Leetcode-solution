bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int arr[15] = { 0 }, neg[15] = { 0 };
    int idx = 0, temp = x, i;
    while (temp > 0)
    {
        arr[idx++] = temp % 10;
        temp /= 10;
    }
    int len = idx;
    idx--;
    for (i = 0; idx >= 0; i++, idx--)
        neg[i] = arr[idx];
    for (int j = 0; j < len; ++j)
        if (arr[j] != neg[j])
            return false;
    return true;
}
