class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto it:s) {
            if(it == '(' || it == '[' || it == '{') {
                stk.push(it);
            } else {
                if(stk.empty())
                    return false;
                if(it == ')' && stk.top() == '(') {
                    stk.pop();
                    continue;
                } else if(it == ']' && stk.top() == '[') {
                    stk.pop();
                    continue;
                } else if(it == '}' && stk.top() == '{') {
                    stk.pop();
                    continue;
                } else
                    return false;
            }
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};
