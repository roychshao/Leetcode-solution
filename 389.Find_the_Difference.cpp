class Solution {
public:
    char findTheDifference(string s, string t) {
        int sSum = 0, tSum = 0;
        for(int i=0;i<s.size();++i)
            sSum += int(s[i]);
        for(int j=0;j<t.size();++j)
            tSum += int(t[j]);
        return char(tSum - sSum);
    }
};
