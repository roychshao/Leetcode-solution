int cmp(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

bool canMakeArithmeticProgression(int* arr, int arrSize)
{
    qsort(arr,arrSize,sizeof(int),cmp);
    int diff = arr[1] - arr[0];
    int temp;
    for(int i=2;i<arrSize;++i)
    {
        temp = (arr[i] - arr[i-1]);
        if(diff != temp)
            return false;
    }
    return true;
}
