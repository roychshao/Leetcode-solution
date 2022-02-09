class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int pairnum = 0;
        bool *check = new bool [20000005];
        memset(check, false, sizeof(check));
        for(auto it1 = nums.begin(); it1 != nums.end(); ++it1){
            for(auto it2 = nums.begin(); it2 != nums.end(); ++it2){
                if(it1 == it2)
                    continue;
                if(*it1 + k == *it2 && !check[*it1 + 10000001])
                    pairnum++, check[*it1 + 10000001] = true;
            }
        }
        return pairnum;
    }
};
