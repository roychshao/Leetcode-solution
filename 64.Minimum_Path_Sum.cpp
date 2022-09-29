#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int Min(int a, int b) {
        return (a < b) ? a : b;
    };

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> step(m, vector<int>(n, 0));
        step[0][0] = grid[0][0];
        for(int i = 1; i < n; ++i) {
            step[0][i] = grid[0][i] + step[0][i-1];
        }
        for(int i = 1; i < m; ++i) {
            step[i][0] = grid[i][0] + step[i-1][0];
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                step[i][j] = grid[i][j] + min(step[i-1][j], step[i][j-1]);
            }
        }
        return step[m-1][n-1];
    };
};
