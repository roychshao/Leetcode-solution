

void sortColors(int* nums, int n)
{
    int tmp;
    for(int i = n-1; i > 0; i--)
    {
        for(int j = 0; j <= i-1; j++)
        {
            if( nums[j] > nums[j+1])
            {
                tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
    }   
}
