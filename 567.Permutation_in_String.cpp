class Solution {
public:
    bool compare(int* s1, int* ps2) {
        for(int i=0; i<26; ++i){
            if(s1[i] != ps2[i])
                return false;
        }
        return true;
    };
    
    bool checkInclusion(string s1, string s2) {
        bool ans = false;
        if(s1.size() > s2.size())
            return false;
        int *s1map = new int [26];
        for(int i=0; i<s1.size(); ++i)
            s1map[int(s1[i]-'a')]++;
        for(int i=0; i<= s2.size()-s1.size(); ++i){
            int *s2map = new int [26];
            for(int j=i; j<i+s1.size(); ++j)
                s2map[int(s2[j]-'a')]++;
            ans = compare(s1map, s2map);
            if(ans)
                return true;
            delete [] s2map;
        }
        return false;
    };
};
