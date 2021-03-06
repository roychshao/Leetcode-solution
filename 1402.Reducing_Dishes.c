int cmpfunc(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int Sum(int* arr, int pidx, int arrsize)
{
    int val = 0;
    for(int i = pidx,j = 1;i < arrsize;++i,++j)
        val += arr[i]*j;
    return val;
}

int maxSatisfaction(int* arr, int arrsize)
{
    int max, pidx, temp;
    qsort(arr,arrsize,sizeof(int),cmpfunc);
    for(int i = 0;i < arrsize;++i)
    {
        if(arr[i] >= 0)
        {
            pidx = i;
            break;
        }
    }
    while(pidx >= 0)
    {
        temp = Sum(arr, pidx, arrsize);
        max = (max > temp) ? max : temp;
        pidx--;
    }
    return max;
}
