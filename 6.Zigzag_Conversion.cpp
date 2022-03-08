
class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows == 1)
                return s;
            char map[1000][1000];
            memset(map, NULL, sizeof(map));
            int rowidx = 0, colidx = 0;
            bool down = true;
            for(int i=0; i<s.size(); ++i){
                if(rowidx >= numRows){
                    down = false;
                    rowidx -= 2;
                    colidx++;
                }else if(rowidx < 0){
                    down = true;
                    rowidx += 2;
                    colidx--;
                }
                map[rowidx][colidx] = s[i];
                if(down){
                    rowidx++;
                }else{
                    rowidx--;
                    colidx++;
                }
            }
            string ans;
            for(int i=0; i<numRows; ++i){
                for(int j=0; j<=colidx; ++j){
                    if(map[i][j] != NULL)
                        ans.push_back(map[i][j]);
                }
            }
            return ans;
        }
};
