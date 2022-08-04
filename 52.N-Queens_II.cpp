#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> rowStr (n, string(n, '.'));
        traverse(0, rowStr, ans);
        return ans.size();
    }

    void traverse(int row, vector<string> &rowStr, vector<vector<string>> &ans) {
        int n = rowStr.size();
        if(row == n) {
            ans.push_back(rowStr);
            return;
        }
        for(int i = 0; i < n; ++i) {
            if(isValid(rowStr, row, i)) {
                rowStr[row][i] = 'Q';
                traverse(row+1, rowStr, ans);
                rowStr[row][i] = '.';
            }
        }
    }

    bool isValid(vector<string>& queens, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (queens[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (queens[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < queens.size(); --i, ++j) {
            if (queens[i][j] == 'Q') return false;
        }
        return true;
    }
};
