class Solution {
public:

    void swap(int a, int b, int c, int d, vector<vector<int>>& mat) {
        int tmp = mat[a][b];
        mat[a][b] = mat[c][d];
        mat[c][d] = tmp;
    }

    void sortTemplate(int i1, int j1, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(;(i1 < m-1 && j1 < n-1); ++i1, ++j1) {
            for(int i2 = i1+1, j2 = j1+1; (i2 < m && j2 < n); ++i2, ++j2) {
                if(mat[i2][j2] < mat[i1][j1])
                    swap(i1, j1, i2, j2, mat);
            }
        }
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // vertical
        for(int k = 0; k < m; ++k) {
            sortTemplate(k, 0, mat);
        }
        // horizontal
        for(int k = 0; k < n; ++k) {
            sortTemplate(1, k, mat);
        }
        return mat;
    }
};
