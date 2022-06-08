class Solution {
    public:

        int binarySearch(vector<int>& nums, int target, int head, int tail) {
            if(head == tail)
                return -1;
            int mid = (head + tail) / 2;
            int idx;
            if (nums[mid] == target)
                return mid;
            // 此時無法判斷target是在哪側
            else if (nums[mid] < nums[0] && nums[mid] < target) {
                if (target > nums[0])
                    idx = binarySearch(nums, target, head, mid);
                else if (target < nums[0])
                    idx = binarySearch(nums, target, mid+1, tail);
                else
                    idx = 0;
            }
            // 右側
            else if (nums[mid] < nums[0] && nums[mid] > target) {
                idx = binarySearch(nums, target, head, mid);
            }
            // 右側
            else if (nums[mid] > nums[0] && nums[mid] < target) {
                idx = binarySearch(nums, target, mid+1, tail);
            }
            // 無法判斷在哪側
            else if (nums[mid] > nums[0] && nums[mid] > target) {
                if (target > nums[0])
                    idx = binarySearch(nums, target, head, mid);
                else if (target < nums[0])
                    idx = binarySearch(nums, target, mid+1, tail);
                else
                    idx = 0;
            }
            return idx;
        }

        int search(vector<int>& nums, int target) {
            int ans = binarySearch(nums, target, 0, nums.size());
            return ans;
        }
};
