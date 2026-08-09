class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> memo (n, vector<vector<int>> (n + 1, vector<int>(2, -1)));
        function<int(int, int, bool)> dp = [&](int i, int m, bool turn) -> int {
            if(i >= n) return 0;
            if(memo[i][m][turn] != -1) return memo[i][m][turn];
            int maxM = min(n - i, 2*m);
            if(turn){
                int currSum = 0, ans = 0;
                for(int k = 1; k <= maxM; k++){
                    currSum += piles[i + k - 1];
                    ans = max(ans, currSum + dp(i + k, max(k, m), !turn));
                }
                memo[i][m][turn] = ans;
            } else {
                int ans = INT_MAX;
                for(int k = 1; k <= maxM; k++){
                    ans = min(ans, dp(i + k, max(k, m), !turn));
                }
                memo[i][m][turn] = ans;
            }
            return memo[i][m][turn];
        };
        return dp(0, 1, true);
    }
};