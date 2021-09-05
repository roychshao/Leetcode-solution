void traversal(char** grid, int gridSize, int* gridColSize, int i, int j)
{
    grid[i][j] = '2';
    if(i+1 < gridSize && grid[i+1][j] == '1')
        traversal(grid, gridSize, gridColSize, i+1, j);
    if(i-1 >= 0 && grid[i-1][j] == '1')
        traversal(grid, gridSize, gridColSize, i-1, j);
    if(j+1 < (*gridColSize) && grid[i][j+1] == '1')
        traversal(grid, gridSize, gridColSize, i, j+1);
    if(j-1 >= 0 && grid[i][j-1] == '1')
        traversal(grid, gridSize, gridColSize, i, j-1);
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int ans = 0;
    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0;j < (*gridColSize); ++j)
        {
            if(grid[i][j] == '1')
            {
                traversal(grid, gridSize, gridColSize, i, j);
                ans++;
            }
        }
    }
    return ans;
}
