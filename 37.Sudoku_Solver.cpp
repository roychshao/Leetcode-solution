class Solution {
public:
    bool is_safe(char ch,int i,int j,vector<vector<char>> &board){
        // col check
        for(int col=0;col<9;col++){
            if(board[i][col] == ch) return false;
        }
        // row check
        for(int row=0;row<9;row++){
            if(board[row][j] == ch) return false;
        }
        // subgrid check
        int sub_row = i - (i%3), sub_col = j - (j%3);
        for(int k=sub_row;k<sub_row+3;k++){
            for(int l=sub_col;l<sub_col+3;l++){
                if(board[k][l] == ch) return false;
            }
        }
        return true;
    }
    bool solve(int i,int j,vector<vector<char>> &board){
        if(i == 9) return true;
        if(j == 9) return solve(i+1,0,board);
        if(board[i][j] != '.') return solve(i,j+1,board);
        for(char ch='1';ch<='9';ch++){
            if(!is_safe(ch,i,j,board)) continue;
            board[i][j] = ch;
            if(solve(i,j+1,board)) return true;
            board[i][j] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};
