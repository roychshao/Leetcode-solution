class Solution {

    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == word.charAt(0)) {
                    char[][] tmp = board.clone();
                    if (dfs(tmp, i, j, 1, word))
                        return true;
                }
            }
        }
        return false;
    }

    public boolean dfs(char[][] board, int i, int j, int k, String word) {
        if (k == word.length())
            return true;
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length)
            return false;
        if ((i + 1) < board.length && board[i + 1][j] == word.charAt(k)) {
            char tmp = board[i][j];
            board[i][j] = ' ';
            if (dfs(board, i + 1, j, k + 1, word)) {
                return true;
            } else {
                board[i][j] = tmp;
            }
        }
        if ((j + 1) < board[0].length && board[i][j + 1] == word.charAt(k)) {
            char tmp = board[i][j];
            board[i][j] = ' ';
            if (dfs(board, i, j + 1, k + 1, word)) {
                return true;
            } else {
                board[i][j] = tmp;
            }
        }
        if ((i - 1) >= 0 && board[i - 1][j] == word.charAt(k)) {
            char tmp = board[i][j];
            board[i][j] = ' ';
            if (dfs(board, i - 1, j, k + 1, word)) {
                return true;
            } else {
                board[i][j] = tmp;
            }
        }
        if ((j - 1) >= 0 && board[i][j - 1] == word.charAt(k)) {
            char tmp = board[i][j];
            board[i][j] = ' ';
            if (dfs(board, i, j - 1, k + 1, word)) {
                return true;
            } else {
                board[i][j] = tmp;
            }
        }
        // print(board);
        return false;
    }

    public void print(char[][] board) {
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                System.out.print(board[i][j] + " ");
            }
            System.out.print("\n");
        }
        System.out.print("\n");
    }
}

/*
* CAA
* AAA
* BCD
*/
