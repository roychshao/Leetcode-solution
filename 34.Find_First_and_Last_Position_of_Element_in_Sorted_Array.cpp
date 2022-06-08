class Solution {
public:

    vector<int> ans;
   
    void binarySearch(vector<int>& nums, int target, int head, int tail) {
        if (head == tail)
            return;
        int mid = (head + tail) / 2;
        if (nums[mid] == target) {
            int h_idx = mid, t_idx = mid;
            while(h_idx > 0 && nums[h_idx-1] == target)
                h_idx--;
            ans.push_back(h_idx);
            while(t_idx < nums.size() - 1 && nums[t_idx+1] == target)
                t_idx++;
            ans.push_back(t_idx);
        }
        else if (nums[mid] < target)
            binarySearch(nums, target, mid+1, tail);
        else
            binarySearch(nums, target, head, mid);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        ans.clear();
        binarySearch(nums, target, 0, nums.size());
        if (ans.size() == 0)
            ans.push_back(-1), ans.push_back(-1);
        return ans;
    }
};
