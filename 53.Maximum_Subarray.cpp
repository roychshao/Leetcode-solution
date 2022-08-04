#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    
    // [-2,1,-3,4,-1,2,1,-5,4]
    
    int maxSubArray(vector<int>& nums) {
        int maxVal = 0, tmpSum = 0;
        int head = 0, tail = 0;
        while(tail < nums.size()) {
            /*
            cout << "maxVal: " << maxVal << endl;
            cout << "tmpSum: " << tmpSum << endl;
            cout << "head: " << head << endl;
            cout << "tail: " << tail << endl;
            cout << "---------" << endl;
            */
            if((tmpSum + nums[tail]) > 0) {
                if((tmpSum + nums[tail]) > maxVal) {
                    maxVal = tmpSum + nums[tail];
                }
                tmpSum += nums[tail];
                tail++;
            } else {
                tail++;
                head = tail;
                tmpSum = 0;
            }
        }
        
        // prevent id there is not positive number in array
        
        if(maxVal == 0) {
            maxVal = -10001;
            for(int i = 0; i < nums.size(); ++i) {
                maxVal = (nums[i] > maxVal) ? nums[i] : maxVal;
            }
        }
        return maxVal;
    }
};
