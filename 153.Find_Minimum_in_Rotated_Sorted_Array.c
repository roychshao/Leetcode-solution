
int findMin(int* nums, int numsSize)
{
    int i;
    for(i = 0;i < numsSize-1; ++i)
        if(nums[i+1] < nums[i])
            return nums[i+1];
    return nums[0];
}
