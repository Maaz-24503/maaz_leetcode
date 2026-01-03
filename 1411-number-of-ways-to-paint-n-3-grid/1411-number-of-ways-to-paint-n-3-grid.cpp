class Solution {
public:
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(
            n + 1, 
            vector<vector<vector<int>>> (
                4,
                vector<vector<int>>(4, vector<int> (4, -1)
                )
            )
        );
        int MOD = 1e9 + 7;
        function<int(int, int, int, int)> helper = [&](int i, int p1, int p2, int p3) -> int {
            if(i == n) return 1;
            if(dp[i][p1][p2][p3] != -1) return dp[i][p1][p2][p3];
            int ans = 0;
            for (int c1 = 1; c1 <= 3; c1++) {
                if (c1 == p1) {
                    continue;
                }
                for (int c2 = 1; c2 <= 3; c2++) {
                    if (c2 == p2 || c2 == c1) {
                        continue;
                    }
                    for (int c3 = 1; c3 <= 3; c3++) {
                        if (c3 == p3 || c3 == c2) {
                            continue;
                        }
                        ans = (ans + helper(i + 1, c1, c2, c3)) % MOD;
                    }
                }
            }
            return dp[i][p1][p2][p3] = ans;
        };
        return helper(0, 0, 0, 0);
    }
};