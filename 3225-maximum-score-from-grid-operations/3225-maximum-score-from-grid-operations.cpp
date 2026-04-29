class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Build prefix sums
        vector<vector<long long>> prefix(n + 1, vector<long long>(m, 0));

        for (int i = 0; i < m; i++) {
            long long sm = 0;
            for (int j = 0; j < n; j++) {
                sm += grid[j][i];
                prefix[j + 1][i] = sm;
            }
        }

        // Memoization map
        map<tuple<int,int,int>, long long> memo;

        function<long long(int, int, int)> dp = [&](int col, int prev, int flag) -> long long {
            if (col >= m) return 0;

            tuple<int, int, int> key = make_tuple(col, prev, flag);
            if (memo.count(key)) return memo[key];

            long long ans = 0;

            for (int i = 0; i <= n; i++) {
                if (prev > i) {
                    long long sm = prefix[prev][col] - prefix[i][col];
                    ans = max(ans, sm + dp(col + 1, i, 1));
                } else if (i > prev && !flag && col > 0) {
                    long long sm_prev = prefix[i][col - 1] - prefix[prev][col - 1];
                    ans = max(ans, sm_prev + dp(col + 1, i, 0));
                } else {
                    ans = max(ans, dp(col + 1, i, 0));
                }
            }

            return memo[key] = ans;
        };

        return dp(0, 0, 1);
    }
};