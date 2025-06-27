class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        auto isValid = [&](string &guess) -> bool {
            int count = 0, i = 0;
            for(char &c : s) {
                if(c == guess[i]) {
                    i++;
                    if(i == guess.size()) {
                        i = 0;
                        if(++count == k) return true;
                    }
                }
            }
            return false;
        };
        queue<string> bfs;
        bfs.push("");
        string ans = "";
        while(!bfs.empty()){
            string curr = bfs.front();
            bfs.pop();
            for(char c = 'a'; c <= 'z'; c++){
                string temp = curr + c;
                if(isValid(temp)){
                    ans = temp;
                    bfs.push(ans);
                }
            }
        }
        return ans;
    }
};