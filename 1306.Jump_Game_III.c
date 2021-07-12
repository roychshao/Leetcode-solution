bool flag;

void dfs(int* arr, int arrSize, int idx)
{
    int val = arr[idx];
    if(val == 0)
        flag = true;
    arr[idx] = -1;
    if((idx + val) < arrSize && arr[idx+val] != -1)
        dfs(arr, arrSize, (idx + val));
    if((idx - val) >= 0 && arr[idx-val] != -1)
        dfs(arr, arrSize, (idx - val));
}

bool canReach(int* arr, int arrSize, int idx)
{
    flag = false;
    dfs(arr, arrSize,idx);
    return flag;
}
