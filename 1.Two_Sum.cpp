class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int i=0,find = 0;
    vector<int>  ans;
    for(i=0;i<nums.size();++i)
    {
        for(int j=i+1;j<nums.size();++j)
        {
            if((nums[i] + nums[j]) == target)
            {
                find = 1;
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
        if(find)    break;
    }
    return ans;
    }
};
