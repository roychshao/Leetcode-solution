class Solution {
    public:

        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            intervals.push_back(newInterval);
            sort(intervals.begin(),intervals.end());
            vector<vector<int>>ans;

            vector<int> temp=intervals[0];

            for(int i=1;i<intervals.size();i++)
            {
                if(intervals[i][0]<=temp[1])
                {
                    int maxi=max(intervals[i][1],temp[1]);
                    temp[1]=maxi;
                }

                else
                {
                    ans.push_back(temp);
                    temp=intervals[i];
                }
            }

            ans.push_back(temp);
            return ans;
        }
};
