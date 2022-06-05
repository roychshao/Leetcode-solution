class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> tmp;
        for(auto it:nums) {
            if(it != val)
                tmp.push_back(it);
        }
        for(int i = 0; i < tmp.size(); ++i) {
            nums[i] = tmp[i];
        }
        return tmp.size();
    }
};
