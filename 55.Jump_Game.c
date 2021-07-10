#define MAX(a,b) (a>b)?a:b

bool canJump(int* nums, int numsSize)
{
    int reach = 0;
    for(int i=0;i<numsSize;++i)
    {
        if(reach < i)
            return false;
        reach = MAX(reach, i+nums[i]);
    }
    return true;
}
