class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int ans=999999;
        sort(nums.begin(), nums.end());
        for(int i=0;i<len;i++)
        {
            if(ans!=nums[i])
                    ans=nums[i];
            else
                return nums[i];
        }
        return 0;
    }
};
