class Solution {
public:

    vector<int> singleMultiply(int digit1, int digit2, int carrier) {
        vector<int> result;
        int newCarrier = 0;
        int multiplyResult = (digit1 * digit2) + carrier;
        result.push_back(multiplyResult % 10);
        result.push_back(multiplyResult / 10);
        return result;
    }

    string multiply(string num1, string num2) {
        int counter = 0;
        vector<vector<int>> num3(210, vector<int>(0));
        for(int i = num1.size()-1; i >= 0; --i, ++counter) {
            for(int j = 0; j < counter; ++j) {
                num3[counter].push_back(0);
            }
            int carrier = 0;
            for(int j = num2.size()-1; j >= 0; --j) {
                int digit1 = (int)(num1[i] - '0');
                int digit2 = (int)(num2[j] - '0');
                vector<int> result = singleMultiply(digit1, digit2, carrier);
                carrier = result[1];    // record carrier
                num3[counter].push_back(result[0]);   // record multiply result
            }
            if(carrier != 0)
                num3[counter].push_back(carrier);
        }
        vector<int> tmp;
        int carrier = 0;
        for(int j = 0; j < num3[counter-1].size(); ++j) {
            int sum = 0;
            for(int i = 0; i < 210; ++i) {
                for(int k = 0; k < (num3[counter-1].size() - num3[i].size()); ++k) {
                    num3[i].push_back(0);
                }
                sum += num3[i][j];
            }
            sum += carrier;
            carrier = sum / 10;
            sum %= 10;
            tmp.push_back(sum);
        }
        if(carrier != 0)
            tmp.push_back(carrier);
        reverse(tmp.begin(), tmp.end());
        string ans;
        if(tmp[0] == 0) {
            ans = "0";
            return ans;
        }
        for(auto it:tmp) {
            ans.push_back((char)(it + 48));
        }
        return ans;
    }
};
