class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string> subs;
        int n = word.size(), m = patterns.size();
        for(int i = 0; i < n; i++){
            string temp = "";
            for(int j = i; j < n; j++){
                temp += string(1, word[j]);
                subs.insert(temp);
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            if(subs.count(patterns[i])) ans++;
        }
        return ans;
    }
};