class Solution {
public:
    
    void traverse(int i, int j, vector<vector<char>>& grid, int m, int n) {
        grid[i][j] = '2';   // signify the place have run
        // rightward
        if((j + 1) < n && grid[i][j+1] == '1')
            traverse(i, j+1, grid, m, n);
        // downward
        if((i + 1) < m && grid[i+1][j] == '1')
            traverse(i+1, j, grid, m, n);
        // leftward
        if((j - 1) >= 0 && grid[i][j-1] == '1')
            traverse(i, j-1, grid, m, n);
        // upward
        if((i - 1) >= 0 && grid[i-1][j] == '1')
            traverse(i-1, j, grid, m, n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    counter++;
                    traverse(i, j, grid, m, n);
                }
            }
        }
        return counter;
    }
};
