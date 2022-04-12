class Solution {
public:

    int CountNeighbors(vector<vector<int>> copy, int i, int j) {
        int m = copy.size(), n = copy[i].size();
        int neighborNum = 0;
        // upward
        if((i-1) >= 0 && copy[i-1][j] == 1)
            neighborNum++;
        // right-up diagonal
        if((i-1) >= 0 && (j+1) < n && copy[i-1][j+1] == 1)
            neighborNum++;
        // rightward
        if((j+1) < n && copy[i][j+1] == 1)
            neighborNum++;
        // right-down diagonal
        if((j+1) < n && (i+1) < m && copy[i+1][j+1] == 1)
            neighborNum++;
        // downward
        if((i+1) < m && copy[i+1][j] == 1)
            neighborNum++;
        // left-down diagonal
        if((i+1) < m && (j-1) >= 0 && copy[i+1][j-1] == 1)
            neighborNum++;
        // leftward
        if((j-1) >= 0 && copy[i][j-1] == 1)
            neighborNum++;
        // left-up diagonal
        if((j-1) >= 0 && (i-1) >= 0 && copy[i-1][j-1] == 1)
            neighborNum++;
        return neighborNum;
    };

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy = board;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == 1 && CountNeighbors(copy, i, j) < 2)
                    board[i][j] = 0;
                if(board[i][j] == 1 && CountNeighbors(copy, i, j) > 3)
                    board[i][j] = 0;
                if(board[i][j] == 0 && CountNeighbors(copy, i, j) == 3)
                    board[i][j] = 1;
            }
        }
    };
};
