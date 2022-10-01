#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:

    // This is a DFA solution (確定性有限自動機)
    // reference: https://leetcode.com/problems/valid-number/discuss/2406796/C%2B%2B-or-DFA-or-Simple-to-understand

    bool isNumber(string s) {
        // 依照自動機的狀態圖建構二維關係陣列
        // F[0][2] = 4表示在狀態0時遇到input為2時會轉變到狀態4
        vector<vector<int>> F = vector<vector<int>>(8,vector<int>(6,-1));
        F[0][1] = 1;
        F[0][2] = 4;
        F[0][0] = 2;
        
        F[1][2] = 4;
        F[1][0] = 2;
        
        F[2][0] = 2;
        F[2][3] = 5;
        F[2][2] = 3;
        F[2][4] = 8;
        
        F[3][0] = 3;
        F[3][3] = 5;
        F[3][4] = 8;
        
        F[4][0] = 3;
        
        F[5][1] = 6;
        F[5][0] = 7;
        
        F[6][0] = 7;
        
        F[7][0] = 7;
        F[7][4] = 8;
       
        // 利用unordered_map來快速將符號對應到特定的input
        unordered_map<char,int> act;
        
        int i = (int) '0';
        for(int j = i; j < i+10; j++){
            act[(char) j] = 0;
        }
        act['+'] = 1;
        act['-'] = 1;
        act['.'] = 2;
        act['E'] = 3;
        act['e'] = 3;
        
        int cur = 0;
        for(int i = 0; i < s.length(); i++){
            auto it = act.find(s[i]);
            // 遇到無效的輸入,直接返回false
            if(it == act.end()){
                return false;
            }
            // cur表示當前狀態
            // 這裡更新當前狀態
            cur = F[cur][it->second];
            // 無效的狀態,直接返回false
            if(cur == -1){
                return false;
            }
        }
        // 當前狀態結束後是否為合理結束的狀態
        return (F[cur][4] == 8);
    }
};
