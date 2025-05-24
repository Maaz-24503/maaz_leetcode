class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        function<bool(string, char)> has = [&](string s, char c){
            for(int i = 0; i<s.size(); i++) if(s[i] == c) return true;
            return false;
        };
        int n = words.size();
        vector<int> ans;
        for(int i = 0; i<n; i++)
            if(has(words[i], x))
                ans.push_back(i);
        return ans;
    }
};