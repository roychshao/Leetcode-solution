#include <vector>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[0] == 0) {
            digits[0] = 1;
            return digits;
        }
        bool allNine = false;
        vector<int> ans;
        for(int i = 0; i < digits.size(); ++i) {
            if(digits[i] != 9)
                break;
            if(i == digits.size() - 1)
                allNine = true;
        }
        if(allNine) {
            ans.push_back(1);
            for(int i = 0; i < digits.size(); ++i) {
                ans.push_back(0);
            }
            return ans;
        } else {
            int carrier = 1;
            for(int i = digits.size() - 1; i >= 0; --i) {
                int nxtCarrier = (digits[i] + carrier) / 10;
                digits[i] = (digits[i] + carrier) % 10;
                if(!nxtCarrier)
                    break;
                carrier = nxtCarrier;
            }
            return digits;
        }
        return digits;
    }
};
