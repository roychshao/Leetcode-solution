// Time Limit Exceeded Solution

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> ans;
            unordered_set<string> map;
            for(int i = 0; i < strs.size(); ++i) {
                
                // 排序字串後比較,相同push_back 反之continue
                vector<string> tmp_str;
                tmp_str.push_back(strs[i]);
                string tmp = strs[i];
                sort(tmp.begin(), tmp.end());

                // 確認沒有重複的字串
                if(map.find(tmp) != map.end())
                    continue;
                map.insert(tmp);

                for(int j = i + 1; j < strs.size(); ++j) {
                    string tmp2 = strs[j];
                    sort(tmp2.begin(), tmp2.end());
                    if(tmp.size() == tmp2.size() && tmp.compare(0, tmp.size(), tmp2) == 0) {
                        tmp_str.push_back(strs[j]);
                    } else continue;
                }
                ans.push_back(tmp_str);
            }
            return ans;
        }
};
