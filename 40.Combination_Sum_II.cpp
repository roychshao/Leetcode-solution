class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    void choose(vector<int> candidates, int target, int j){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=j; i<candidates.size(); ++i){
            if(i > j && candidates[i] == candidates[i-1])   // i > j because the first element should be considered
                continue;
            if(candidates[i] > target)
                break;
                
            temp.push_back(candidates[i]);
            choose(candidates, target - candidates[i], i+1);
            temp.pop_back();
        }
    };

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        ans.clear();
        choose(candidates, target, 0);
        return ans;
    };
};
