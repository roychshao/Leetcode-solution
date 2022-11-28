#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:

        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> ans;
            for(int i = 0; i < words.size(); ++i) {
                int len = words[i].size();
                int j = i + 1;
                // 判斷可以拿幾個詞
                while(j < words.size() && len + 1 + words[j].size() <= maxWidth) {
                    len += 1 + words[j].size();
                    j++;
                }

                int cnt = j - i;    // counter表示能拿的字詞數量
                string s = words[i];
                // 如果只有一個詞,在後面補滿空格
                if(cnt == 1 || j == words.size()) {
                    for(int k = i + 1; k < j; ++k) {
                        s += " " + words[k];
                    }
                    s.insert(s.end(), maxWidth - s.size(), ' ');
                } else {
                    // 計算空格長度
                    int len_sp = (maxWidth - len + cnt - 1) / (cnt - 1);
                    for(int k = i + 1, l = 0; k < j; k++, l++) {
                        s.insert(s.end(), len_sp, ' ');
                        if(l < (maxWidth - len + cnt - 1) % (cnt - 1))
                            s += ' ';
                        s += words[k];
                    }
                }
                ans.push_back(s);
                i = j - 1;
            }
            return ans;
        }
};
