
class Solution {
public:

    bool cmpstr(string str1, string str2){
        int err_cnt = 0;
        for(int i=0; i<str1.size(); ++i){
            if(err_cnt >= 2)
                return false;
            if(str1[i] != str2[i])
                err_cnt++;
        }
        return (err_cnt == 1) ? true : false;
    };
    
    int bfs(string beginWord, string endWord, vector<string>& wordlist){
        vector<bool>list_used(wordlist.size(), false);
        queue<string> que;
        queue<int> cnt;
        while(!que.empty())
            que.pop(), cnt.pop();
        que.push(beginWord);
        cnt.push(1);
        while(!que.empty()){
            string tmp = que.front();
            int cnttmp = cnt.front();
            if(tmp.compare(endWord) == 0)
                return cnttmp;
            for(int i=0; i<wordlist.size(); ++i){
                if(!list_used[i] && cmpstr(tmp, wordlist[i])){
                    que.push(wordlist[i]);
                    cnt.push(cnttmp+1);
                    list_used[i] = true;
                }
            }
            cnt.pop();
            que.pop();
        }
        return 0;
    };

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = bfs(beginWord, endWord, wordList);
        return ans;
    };
};
