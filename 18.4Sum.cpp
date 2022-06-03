class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& v, int &k) {

            int n=v.size();    
            vector<vector<int>> ans;

            if(n<4) return ans;

            sort(v.begin(), v.end());
            for (int z = 0; z < n-3;z++)
            {
                if(z==0||v[z-1]!=v[z])
                {
                    for (int y = z + 1; y < n - 2;y++)
                    {
                        if(y==z+1||v[y]!=v[y-1])
                        {
                            int i = y + 1,j=n-1;
                            int target=k-v[z]-v[y];

                            if(v[i]+v[i+1]>target) break;
                            if(v[j]+v[j-1]<target) continue;

                            while(i<j)
                            {

                                if(target==v[i]+v[j])
                                {
                                    ans.push_back({v[z], v[y], v[i], v[j]});
                                    i++;
                                    j--;
                                    while(i<n&&v[i]==v[i-1])
                                        i++;
                                    while(j>0&&v[j]==v[j+1])
                                        j--;
                                }
                                else if(v[i]+v[j]>target)
                                {
                                    j--;
                                }
                                else
                                    i++;
                            }
                        }
                    }
                }

            }
            return ans;

        }
};
