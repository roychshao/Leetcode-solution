#define MIN(A,B) ((A) <= (B) ? (A) : (B))
int trap(int* height, int heightSize)
{
    int right[30000],left[30000];
    int sum = 0;
    int temp = 0;
    for(int i=0;i<heightSize;++i)
    {
        if(height[i] > temp)
            temp = height[i];
        right[i] = temp;
    }
    temp = 0;
    for(int i=heightSize-1;i>=0;--i)
    {
        if(height[i] > temp)
            temp = height[i];
        left[i] = temp;
    }
    for(int i=0;i<heightSize;++i)
        sum += (MIN(right[i],left[i]) - height[i]);
    return sum;
}
