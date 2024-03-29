class Solution {
    public:
        string simplifyPath(string path) {

            stack<string> stk;

            istringstream iss(path);
            string token;

            while (getline(iss, token, '/')) {
                if (stk.empty() && token == "..")
                    continue;
                else if (token != "") {
                    if (stk.empty() && token == "..")
                        continue;
                    if (!stk.empty()) {
                        if (token == ".")
                            continue;
                        if (token == "..")
                            stk.pop();
                    }
                    if (token != "." && token != "..")
                        stk.push(token);
                }
            }
            stack<string> rv_stk;
            while (!stk.empty()) {
                rv_stk.push(stk.top());
                stk.pop();
            }
            string res = "";
            while (!rv_stk.empty()) {
                res += "/";
                res += rv_stk.top();
                rv_stk.pop();
            }
            if (res == "") res = "/";
            return res;
        }
};
