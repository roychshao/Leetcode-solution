/* TLE solution */
#include <iostream>
#include <vector>
using namespace std;

#define MARKED -1

class Solution {
public:
    
    bool getP = false;
    bool getA = false;
    
    bool getPacific(int i, int j) {
        if(i == 0 || j == 0)
            return true;
        return false;
    }
    
    bool getAtlantic(int i, int j, int m, int n) {
        if(i == (m - 1) || j == (n - 1))
            return true;
        return false;
    }
    
    bool traverse(int i, int j, vector<vector<int>>& map) {
        if(getP && getA)
            return true;
        int m = map.size();
        int n = map[0].size();
        int height = map[i][j];
        map[i][j] = MARKED;
        if(getPacific(i, j))
            getP = true;
        if(getAtlantic(i, j, m, n))
            getA = true;
        // rightward
        if((j + 1) < n && height >= map[i][j+1] && map[i][j+1] != MARKED)
            traverse(i, j+1, map);
        // downward
        if((i + 1) < m && height >= map[i+1][j] && map[i+1][j] != MARKED)
            traverse(i+1, j, map);
        // leftward
        if((j - 1) >= 0 && height >= map[i][j-1] && map[i][j-1] != MARKED)
            traverse(i, j-1, map);
        // upward
        if((i - 1) >= 0 && height >= map[i-1][j] && map[i-1][j] != MARKED)
            traverse(i-1, j, map);
        return (getP && getA);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size();
        int n = heights[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                getP = false, getA = false;
                if(traverse(i, j, heights)) {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};
