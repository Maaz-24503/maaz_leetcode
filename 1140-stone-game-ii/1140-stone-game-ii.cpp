class Solution {
public:
    // a + b = s
    // x = a - b
    // 2a = x + s
    // a = (x + s) / 2  -->  Final
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        vector<vector<vector<int>>> memo(
            n + 1,
            vector<vector<int>>(n + 1, vector<int>(2, INT_MIN))
        );

        function<int(int, int, bool)> dp = [&](int i, int m, bool turn) -> int {
            if (i >= n) return 0;
            if (memo[i][m][turn] != INT_MIN) return memo[i][m][turn];

            if (turn) {
                int ans = INT_MIN, sum = 0;
                for (int x = 0; x < min(2 * m, n - i); x++) {
                    sum += piles[x + i];
                    ans = max(ans, sum + dp(x + i + 1, max(x + 1, m), !turn));
                }
                return memo[i][m][turn] = ans;
            } else {
                int ans = INT_MAX, sum = 0;
                for (int x = 0; x < min(2 * m, n - i); x++) {
                    sum += piles[x + i];
                    ans = min(ans, -sum + dp(x + i + 1, max(x + 1, m), !turn));
                }
                return memo[i][m][turn] = ans;
            }
        };

        int sum = 0;
        for (int i = 0; i < n; i++) sum += piles[i];
        return (dp(0, 1, true) + sum) / 2;
    }
};
