class Solution {
public:
    double champagneTower(int poured, int row, int col) {
        double p = double(poured);
        double glasses[105][105];
        memset(glasses, 0.0, sizeof(glasses));
        glasses[0][0] = double(poured);
        for(int i=0; i<=row; ++i){
            for(int j=0; j<=i; ++j){
                double overflow = (glasses[i][j] - 1.0) / 2.0;
                if(overflow > 0){
                    glasses[i+1][j] += overflow;
                    glasses[i+1][j+1] += overflow;
                }
            }
        }
        return (glasses[row][col] > 1) ? 1 : glasses[row][col];
    }
};
