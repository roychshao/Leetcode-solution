class Solution {
public:
    int lengthOfLastWord(string s) {
        for(int i = s.size()-1; i >= 0; --i) {
            if(s[i] == ' ')
                continue;
            int counter = 0;
            for(int j = i; j >= 0; --j) {
                if(s[j] != ' ')
                    counter++;
                else
                    return counter;
            }
            return counter;
        }
        return -1;
    }
};
