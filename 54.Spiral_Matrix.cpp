class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /* 
            direction:
            0: right
            1: down
            2: left
            3: up
        */ 
        int direction = 0;
        vector<int> ans;
        int i = 0, j = 0;
        const int m = matrix.size(), n = matrix[0].size();
        int marked = 1000;
        int counter = 0;
        bool endCounter = false;
        //cout << m << " - " << n << endl;
        while(counter < (m*n)) {
            //cout << i << " " << j << endl;
            if(matrix[i][j] != marked) {
                ans.push_back(matrix[i][j]);
                matrix[i][j] = marked;
            }
            if(counter == (m*n)-1) {
                endCounter = true;
            }
            direction %= 4;
            switch(direction) {
                case 0:
                    if((j + 1) < n && matrix[i][j+1] != marked)
                        j++;
                    else {
                        if(endCounter)
                            return ans;
                        direction++;
                        continue;
                    }
                    break;
                case 1:
                    if((i + 1) < m && matrix[i+1][j] != marked)
                        i++;
                    else {
                        if(endCounter)
                            return ans;
                        direction++;
                        continue;
                    }
                    break;
                case 2:
                    if((j - 1) >= 0 && matrix[i][j-1] != marked)
                        j--;
                    else {
                        if(endCounter)
                            return ans;
                        direction++;
                        continue;
                    }
                    break;
                case 3:
                    if((i - 1) >= 0 && matrix[i-1][j] != marked)
                        i--;
                    else {
                        if(endCounter)
                            return ans;
                        direction++;
                        continue;
                    }
                    break;
            }
            counter++;
        }
        return ans;
    }
};
