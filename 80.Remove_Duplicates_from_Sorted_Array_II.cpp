class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int numsize = nums.size(), maxval = 10001;
        int duplicatenum = 0, counter = 1, val = -10001;
        for(auto it = nums.begin(); it != nums.end(); it++){
            if(*it != val){
                val = *it, counter = 1;
            }else{
                if(counter == 2)
                    *it = maxval, duplicatenum++;
                else
                    counter++;
            }
        }
        sort(nums.begin(), nums.end());
        return (numsize - duplicatenum);
    }
};
