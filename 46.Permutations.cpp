class Solution {
public:
    
    vector<vector<int>> ans;
    
    void traverse(vector<int> nums, int idx) {

        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); ++i) {
            swap(nums[i], nums[idx]);
            traverse(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        traverse(nums, 0);
        return ans;
    }
};
