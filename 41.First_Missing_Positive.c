int firstMissingPositive(int* nums, int numsSize)
{
    bool check[500001] = { false };
    for(int i=0;i<numsSize;++i)
    {
        if(nums[i] > numsSize || nums[i] <= 0)
            continue;
        check[nums[i]] = true;
    }
    for(int i=1;i<500001;++i)
    {
        if(check[i] == false)
            return i;
    }
    return numsSize+1;
}
