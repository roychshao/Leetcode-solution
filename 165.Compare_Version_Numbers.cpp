class Solution {
public:
    int compareVersion(string v1, string v2) {
        int idx1 = 0, idx2 = 0;
        while(idx1 < v1.size() || idx2 < v2.size()){
            int val1 = 0, val2 = 0;
            // process v1, ignore leading zero and calculate a number between two '.' in val1
            while(idx1 < v1.size() && v1[idx1] != '.'){
                if(v1[idx1] == '0')
                    idx1++;
                else{
                    int cnt = 1;
                    while(idx1 < v1.size() && v1[idx1] != '.'){
                        val1 *= cnt;
                        val1 += int(v1[idx1] - '0');
                        cnt *= 10, idx1++;
                    }
                    break;
                }
            }
            // process v2, ignore leading zero and calculate a number between two '.' in val2
            while(idx2 < v2.size() && v2[idx2] != '.'){
                if(v2[idx2] == '0')
                    idx2++;
                else{
                    int cnt = 1;
                    while(idx2 < v2.size() && v2[idx2] != '.'){
                        val2 *= cnt;
                        val2 += int(v2[idx2] - '0');
                        cnt *= 10, idx2++;
                    }
                    break;
                }
            }
            if(val1 > val2)
                return 1;
            else if(val1 < val2)
                return -1;
            idx1++, idx2++;
        }
        return 0;
    }
};
