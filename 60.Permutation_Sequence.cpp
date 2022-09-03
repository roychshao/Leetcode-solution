class Solution {
public:

    bool visited[10] = { false };
    
    int extract(int quo) {
        int counter = 0;
        for(int i = 1; i <= 9; ++i) {
            if(visited[i])
                continue;
            else
                counter++;
            if(counter == quo) {
                visited[i] = true;
                return i;
            }
        }
        return 0;
    }

    string getPermutation(int n, int k) {
        string ans = "";
        int hierarchy[10];

        // generate hierarchy array
        
        hierarchy[1] = 1, hierarchy[2] = 2;
        for(int i = 3; i <= 9; ++i) {
            hierarchy[i] = i * hierarchy[i-1];
        }

        for(int i = n - 1; i > 0; --i) {
            int quo = (k / hierarchy[i]) + 1;
            if(k % hierarchy[i] == 0)
                quo--;
            k -= hierarchy[i] * (quo - 1);
            ans += char(extract(quo) + '0');
        }

        // add the last character which is determined

        for(int i = 1; i <= 9; ++i) {
            if(!visited[i]) {
                ans += char(i + '0');
                break;
            } else continue;
        }
        return ans;
    }
};
