class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans{};
        unordered_map<string,int> m1;
        for(auto word : words) m1[word]++;
        int w = size(words[0]);
        int n = size(words);
        if(size(s) < n*w) return {};
        for(int i = 0 ; i <= size(s) - w*n  ; ++i){
            if(m1[s.substr(i,w)] > 0){
                unordered_map<string,int> m2 = m1;
                int cnt = 1;
                m2[s.substr(i,w)]--;
                for(int j = i+w ; j <= size(s)-w ; j += w){
                    if(m2[s.substr(j,w)] > 0) {cnt++ ; m2[s.substr(j,w)]-- ; }
                    else break;
                }
                if(cnt == n) ans.emplace_back(i);
            }
        }
        return ans;
    }
};
