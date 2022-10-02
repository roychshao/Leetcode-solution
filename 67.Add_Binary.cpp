#include <string>
#include <algorithm>
#define MIN(a, b) (a < b) ? a : b
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        int l = MIN(m, n);
        int carrier = 0;
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i = 0; i < l; ++i) {
            int result = int(a[i] - '0') + int(b[i] - '0') + carrier;
            switch(result) {
                case 0:
                    ans.push_back('0');
                    carrier = 0;
                    break;
                case 1:
                    ans.push_back('1');
                    carrier = 0;
                    break;
                case 2:
                    ans.push_back('0');
                    carrier = 1;
                    break;
                case 3:
                    ans.push_back('1');
                    carrier = 1;
                    break;
            }
        }
        if(m > l) {
            for(int i = l; i < m; ++i) {
                if(carrier) {
                    int nxtCarrier = (a[i] - '0' + carrier) / 2;
                    ans.push_back('0' + (a[i] - '0' + carrier) % 2);
                    carrier = nxtCarrier;
                } else {
                    ans.push_back(a[i]);
                }
            }
        } else if(n > l) {
            for(int i = l; i < n; ++i) {
                if(carrier) {
                    int nxtCarrier = (b[i] - '0' + carrier) / 2;
                    ans.push_back('0' + (b[i] - '0' + carrier) % 2);
                    carrier = nxtCarrier;
                } else {
                    ans.push_back(b[i]);
                }
            }
        }
        if(carrier)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
