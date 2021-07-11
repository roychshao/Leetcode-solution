class Solution {
public:
    
    typedef struct {
        int place;
        int distance;
        int step;
    }Info;
    
    queue<Info> que;
    
    int jump(vector<int>& nums) 
    {
        int visited[nums.size()];
        while(!que.empty())
            que.pop();
        memset(visited, 0, sizeof(visited));
        que.push({ 0,nums[0],0 });
        visited[0] = 1;
        while (!que.empty())
        {
            Info temp = que.front();
            if (temp.place == (nums.size() - 1))
                return temp.step;
            for (int i = 1; i <= temp.distance; i++)
            {

                if ((temp.place + i) < nums.size() && visited[temp.place + i] == 0)
                {
                    visited[temp.place + i] = 1;
                    que.push({ temp.place + i , nums[temp.place + i] , temp.step + 1 });
                }
            }
            que.pop();
        }
        return -1;
    }
};
