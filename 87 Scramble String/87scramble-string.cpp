class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if(s1 == s2) return true;
        if(n == 1) return false;
        if(s1.length() != s2.length()) return false;
        string key = s1 + " " + s2;
        if(memo.find(key) != memo.end()) return memo[key];
        for(int i = 1; i < n; i++){
            // cout<<key<<endl;
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i))){
                memo[key] = true;
                return memo[key];
            }
            if(isScramble(s1.substr(0,i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0,n-i))){
                memo[key] = true;
                return memo[key];
            }
        }
        memo[key] = false;
        return memo[key];
    }
};
