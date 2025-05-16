class Solution {
private:
    bool differByOneChar(const string& a, const string& b) {
        if (a.size() != b.size()) return false;
        int diffCount = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++diffCount;
                if (diffCount > 1) return false;
            }
        }
        return diffCount == 1;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxIdx = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && differByOneChar(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > dp[maxIdx]) {
                maxIdx = i;
            }
        }

        vector<string> result;
        for (int i = maxIdx; i != -1; i = prev[i]) {
            result.push_back(words[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
