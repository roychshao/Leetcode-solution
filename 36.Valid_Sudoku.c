
bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    for(int i=0;i<boardSize;++i)
    {
        for(int j=0;j<(*boardColSize);++j)
        {
            if(board[i][j] == '.')  continue;
            
            // check the same row
            
            for(int k=j+1;k<(*boardColSize);++k)
                if(board[i][j] == board[i][k])
                    return false;
            
            // check the same column
            
            for(int k=i+1;k<boardSize;++k)
                if(board[i][j] == board[k][j])
                    return false;
            
            // check the same ninesquare
            
            if(i < 3 && j < 3)
            {
                for(int s=0;s<3;++s)
                {
                    for(int t=0;t<3;++t)
                    {
                        if(s == i && t == j)    continue;
                        if(board[i][j] == board[s][t])    return false;
                    }
                }
            }
            else if(i >= 3 && i < 6 && j < 3)
            {
                for(int s=3;s<6;++s)
                {
                    for(int t=0;t<3;++t)
                    {
                        if(s == i && t == j)    continue;
                        if(board[i][j] == board[s][t])    return false;
                    }
                }
            }
            else if(i >= 6 && i < 9 && j < 3)
            {
                for(int s=6;s<9;++s)
                {
                    for(int t=0;t<3;++t)
                    {
                        if(s == i && t == j)    continue;
                        if(board[i][j] == board[s][t])    return false;
                    }
                }
            }
            else if(i < 3 && j >= 3 && j < 6)
            {
                for(int s=0;s<3;++s)
                {
                    for(int t=3;t<6;++t)
                    {
                        if(s == i && t == j)    continue;
                        if(board[i][j] == board[s][t])    return false;
                    }
                }
            }
            else if(i >=3 && i < 6 && j >= 3 && j < 6)
            {
                for(int s=3;s<6;++s)
                {
                    for(int t=3;t<6;++t)
                    {
                        if(s == i && t == j)    continue;
                        if(board[i][j] == board[s][t])    return false;
                    }
                }
            }
            else if(i >= 6 && i < 9 && j >= 3 && j < 6)
            {
                for(int s=6;s<9;++s)
                {
                    for(int t=3;t<6;++t)
                    {
                        if(s == i && t == j)    continue;
                        if(board[i][j] == board[s][t])    return false;
                    }
                }
            }
            else if(i < 3 && j >= 6 && j < 9)
            {
                for(int s=0;s<3;++s)
                {
                    for(int t=6;t<9;++t)
                    {
                        if(s == i && t == j)    continue;
                        if(board[i][j] == board[s][t])    return false;
                    }
                }
            }
            else if(i >= 3 && i < 6 && j >= 6 && j < 9)
            {
                for(int s=3;s<6;++s)
                {
                    for(int t=6;t<9;++t)
                    {
                        if(s == i && t == j)    continue;
                        if(board[i][j] == board[s][t])    return false;
                    }
                }
            }
            else if(i >= 6 && i < 9 && j >= 6 && j < 9)
            {
                for(int s=6;s<9;++s)
                {
                    for(int t=6;t<9;++t)
                    {
                        if(s == i && t == j)    continue;
                        if(board[i][j] == board[s][t])    return false;
                    }
                }
            }
        }
    }
        return true;
}
