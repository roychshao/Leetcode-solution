class Solution {
public:
    
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        for(; i > 0; --i) {
            if(nums[i] > nums[i-1])
                break;
        }
        if(i == 0)
            reverse(nums.begin(), nums.end());
        else {
            int j = i;
            while(j < nums.size() && nums[j] > nums[i-1]) {
                //cout << j << endl;
                j++;
            }
            j--;
            swap(nums, i-1, j);
            reverse(nums.begin()+i, nums.end());
        }
    }
};
