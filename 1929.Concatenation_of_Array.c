/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize)
{
    (*returnSize) = 2 * numsSize;
    int* ans = (int*)malloc(sizeof(int) * (2 * numsSize));
    int idx = 0;
    for(idx = 0; idx < numsSize; ++idx)
    {
        ans[idx] = nums[idx];
        ans[idx+numsSize] = nums[idx];
    }
    return ans;
}
