class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> arr(strs.size());
        function<pair<int, int>(int)> getCount = [&](int i) -> pair<int, int> {
            int ones = 0, zeros = 0;
            for (int j = 0; j < strs[i].size(); j++)
                if (strs[i][j] == '0')
                    zeros++;
                else
                    ones++;
            return {zeros, ones};
        };
        for (int i = 0; i < strs.size(); i++)
            arr[i] = getCount(i);
        vector<vector<vector<int>>> memo(
            strs.size() + 1,
            vector<vector<int>>(
                m + 1, vector<int>(n + 1, -1)
            )
        );
        function<int(int, int, int)> dp = [&] (int i, int p, int q) -> int {
            if(i == strs.size()) return 0;
            if(memo[i][p][q] != -1) return memo[i][p][q];
            int zeros = p + arr[i].first, ones = q + arr[i].second;
            if(zeros <= m && ones <= n) return memo[i][p][q] = max(1 + dp(i + 1, zeros, ones), dp(i + 1, p, q));
            return memo[i][p][q] = dp(i + 1, p, q);
        };
        return dp(0, 0, 0);
    }
};