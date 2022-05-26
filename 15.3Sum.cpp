class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        int l = nums.size();
        for(int i = 0; i < l - 1; ++i) {
            int j = i + 1;
            int k = l - 1;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            while(j < k) {
                if((nums[i] + nums[j] + nums[k]) == 0) {
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    ans.push_back(tmp);
                    tmp.clear();
                    k--;
                    while(j < k && (nums[k] == nums[k+1]))
                        k--;
                } else if((nums[i] + nums[j] + nums[k]) > 0)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};
