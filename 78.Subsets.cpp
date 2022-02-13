#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet(1<<nums.size());
        int idx = 0;
        int status = 0;
        int upperbound = 1 << nums.size();
        for(int i = 0; i < powerSet.size(); ++i){
            idx = 0;
            int sts = status;   // just a copy of status
            while(sts > 0){
                if(sts % 2 == 1){
                    powerSet[i].push_back(nums[idx]);
                }
                sts /= 2;
                idx++;
            }
            status++;
        }
        return powerSet;
    };
};
