class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i) {
            vector<int> tmp;
            for(int j = 0; j < n; ++j) {
                tmp.push_back(0);
            }
            ans.push_back(tmp);
        }
        int direction = 0, k = 1;
        int i = 0, j = 0;
        while(k <= n*n) {
            ans[i][j] = k;
            if(k == n*n)
                break;
            direction %= 4;
            switch(direction) {
                case 0:
                    if((j + 1) < n && ans[i][j+1] == 0)
                        j++, k++;
                    else
                        direction++;
                    break;
                case 1:
                    if((i + 1) < n && ans[i+1][j] == 0)
                        i++, k++;
                    else
                        direction++;
                    break;
                case 2:
                    if((j - 1) >= 0 && ans[i][j-1] == 0)
                        j--, k++;
                    else
                        direction++;
                    break;
                case 3:
                    if((i - 1) >= 0 && ans[i-1][j] == 0)
                        i--, k++;
                    else
                        direction++;
                    break;
            }
        }
        return ans;
    }
};
