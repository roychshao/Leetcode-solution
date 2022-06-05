class Solution {
public:

    int removeDuplicates(vector<int>& nums) {
        vector<int> tmp;
        tmp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[i-1])
                tmp.push_back(nums[i]);
        }
        for(int i = 1; i < tmp.size(); ++i) {
            nums[i] = tmp[i];
        }
        return tmp.size();
    }
};
