#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> step(m, vector<int>(n, 0));
        step[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        for(int i = 1; i < n; ++i) {
            step[0][i] = (obstacleGrid[0][i] == 0) ? step[0][i-1] : 0;
        }
        for(int i = 1; i < m; ++i) {
            step[i][0] = (obstacleGrid[i][0] == 0) ? step[i-1][0] : 0;
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(obstacleGrid[i][j] == 1) {
                    step[i][j] = 0;
                    continue;
                }
                step[i][j] = step[i-1][j] + step[i][j-1];
            }
        }
        return step[m-1][n-1];
    }
};
