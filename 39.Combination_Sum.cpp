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
            if(candidates[i] > target)
                return;
            else{
                temp.push_back(candidates[i]);
                choose(candidates, target - candidates[i], i);
                temp.pop_back();
            }
        }
    };

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        ans.clear();
        for(int i=0; i<candidates.size(); ++i){
            temp.clear();
            temp.push_back(candidates[i]);
            choose(candidates, target-candidates[i], i);
        }
        return ans;
    };
};
