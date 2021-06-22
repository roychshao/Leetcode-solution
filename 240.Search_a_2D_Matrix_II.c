#define INT_MIN -2147483648
bool flag = false;

void run(int** matrix, int matrixSize, int* matrixColSize, int target, int x, int y)
{
    if(x < matrixSize && y < *matrixColSize && matrix[x][y] != INT_MIN)
    {
        if(matrix[x][y] == target)
        {
            flag = true;
            return;
        }
        else if(matrix[x][y] < target)
        {
            run(matrix,matrixSize,matrixColSize,target,x+1,y);
            run(matrix,matrixSize,matrixColSize,target,x,y+1);
            matrix[x][y] = INT_MIN;
        }
    }
    return;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    flag = false;
    run(matrix,matrixSize,matrixColSize,target,0,0);
    return flag;
}
