class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>> (n, vector<int> (2, -1)));
        function<int(int, int, bool)> dp = [&](int i, int j, bool turn) -> bool {
            if(memo[i][j][turn] != -1) return memo[i][j][turn];
            if(i == j) return turn ? piles[i] : -piles[i];
            if(turn) return memo[i][j][turn] = max(piles[i] + dp(i + 1, j, !turn), piles[j] + dp(i, j - 1, !turn));
            return memo[i][j][turn] = min(-piles[i] + dp(i + 1, j, !turn), -piles[j] + dp(i, j - 1, !turn));
        };
        return dp(0, n - 1, true) > 0;
    }
};