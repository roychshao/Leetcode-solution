class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i+=2){
            if(nums[i] != nums[i-1])
                return nums[i-1];
        }
        return nums.back();
    }
};

/* another smart solution use XOR gate
 * because each element with frequency 2 after twice XOR with become 0
 * so we can just traverse every element and do XOR
 * then those elements with frequency 2 will be filtered and remains our ans
 * 
 * int singleNumber(vector<int>& nums) {
 *     int ans = 0;
 *     for(auto it:nums)
 *         ans ^= it;
 *     return ans;
 * }
 */ 
