class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b){
            return a.size() < b.size();
        });
        int n = words.size();
        vector<unordered_set<string>> possible(n);
        for(int i = 0; i < n; i++){
            if(words[i].size() > 1){
                possible[i].insert(words[i].substr(1));
                possible[i].insert(words[i].substr(0, words[i].size() - 1));
            }
            for(int j = 1; j < words[i].size() - 1; j++){
                possible[i].insert(words[i].substr(0, j) + words[i].substr(j + 1));
            }
        }
        vector<int> dp(n, 1);
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(words[j].size() > words[i].size() + 1) break;
                if(possible[j].find(words[i]) != possible[j].end()) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};