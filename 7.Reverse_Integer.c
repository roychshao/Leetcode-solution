#define INT_MAX 2147483647
#define INT_MIN -2147483648

int reverse(long long x)
{
    int arr[50], idx = 0, neg = 1;
    long long ans = 0;
    if(x < 0)
    {
        neg = -1;
        x *= -1;
    }
    while( x > 0)
    {
        arr[idx++] = (x % 10);
        x /= 10;
    }
    int i = 0;
    while(i < idx)
    {
        ans *= 10;
        ans += arr[i++];
    }
    ans *= neg;
    if(ans > INT_MAX || ans < INT_MIN)  return 0;
    else    return ans;
}
