#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int> a, const vector<int> b) {
    return (a[0] < b[0]);
}

class Solution {
public:

    void swap(vector<int>& a, vector<int>& b) {
        vector<int> tmp = a;
        a = b;
        b = tmp;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        // sort intervals with the smallest start
        sort(intervals.begin(), intervals.end(), cmp);
        // merge intervals
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] <= end) {
                if(intervals[i][1] > end)
                    end = intervals[i][1];
            } else {
                vector<int> tmp;
                tmp.push_back(start);
                tmp.push_back(end);
                ans.push_back(tmp);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> tmp;
        tmp.push_back(start);
        tmp.push_back(end);
        ans.push_back(tmp);
        return ans;
    }
};
