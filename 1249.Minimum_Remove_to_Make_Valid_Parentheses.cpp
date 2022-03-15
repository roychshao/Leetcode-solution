
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int counter = 0;
        // 移除右括號
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                counter++;
            } else if (s[i] == ')' && counter <= 0) {
                s[i] = ' ';
            } else if (s[i] == ')' && counter > 0) {
                counter--;
            }
        }
        // 移除左括號
        for(int i = s.size() - 1; i >= 0; --i) {
            if(counter == 0)
                break;
            else if(s[i] == '(' && counter > 0){
                s[i] = ' ';
                counter --;
            }
        }
        string ans = "";
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != ' ')
                ans.push_back(s[i]);
        }
        return ans;
    }
};
