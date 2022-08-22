class Solution {
public:
    bool isPowerOfFour(int n) {
        long long val = 1;
        while(true) {
            if(val == n)
                return true;
            else if(val < n)
                val *= 4;
            else if(val > n)
                return false;
        }
    }
};
