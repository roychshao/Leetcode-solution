class Solution {
public:

    void init () {
        // construct map
        string tmp = "";
        map.push_back(tmp); // ignore map[0]
        map.push_back(tmp); // ignore map[1]
        // 2
        tmp = "abc";
        map.push_back(tmp);
        tmp.clear();
        // 3
        tmp = "def";
        map.push_back(tmp);
        tmp.clear();
        // 4
        tmp = "ghi";
        map.push_back(tmp);
        tmp.clear();
        // 5
        tmp = "jkl";
        map.push_back(tmp);
        tmp.clear();
        // 6
        tmp = "mno";
        map.push_back(tmp);
        tmp.clear();
        // 7
        tmp = "pqrs";
        map.push_back(tmp);
        tmp.clear();
        // 8
        tmp = "tuv";
        map.push_back(tmp);
        tmp.clear();
        // 9
        tmp = "wxyz";
        map.push_back(tmp);
        tmp.clear();
    }

    vector<string> map;
    vector<string> ans;

    void traversal (int l, string tmp, string &digits) {
        if(l == digits.size())
            ans.push_back(tmp);
        else {
            for(int i = 0; i < map[digits[l] - '0'].size(); ++i) {
                traversal(l+1, tmp + map[digits[l] - '0'][i], digits); 
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return ans;
        init();
        string tmp = "";
        traversal(0, tmp, digits);
        return ans;
    }
};
