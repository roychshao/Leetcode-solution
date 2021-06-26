#define MIN(a,b) (a < b) ? a : b;

int maxArea(int* height, int heightSize)
{
    int head = 0, tail = heightSize - 1;
    int left = 0, right = heightSize - 1;
    int water = 0;
    while(head < tail)
    {
        int h = MIN(height[head],height[tail]);
        int w = h * (tail - head);
        if(w > water)   water = w;
        while(height[head] <= h && head < tail)    head++;
        while(height[tail] <= h && head < tail)    tail--;
    }
    return water;
}
