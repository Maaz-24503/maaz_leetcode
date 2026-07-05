class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        board[0][0] = '0';
        board[n - 1][n - 1] = '0';
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (n, {-1, -1}));
        function<pair<int, int>(int, int)> helper = [&](int i, int j) -> pair<int, int> {
            if(i == n - 1 && j == n - 1) return {0, 1};
            if(i > n - 1 || j > n - 1 || board[i][j] == 'X') return {INT_MIN, 0};
            if(dp[i][j].second != -1) return dp[i][j];
            pair<int, int> r = helper(i, j + 1), b = helper(i + 1, j), br = helper(i + 1, j + 1);
            int highest = max({r.first, b.first, br.first});
            if(highest == INT_MIN) return dp[i][j] = {INT_MIN, 0};
            long long ways = 0LL;
            if(r.first == highest) ways += r.second;
            if(b.first == highest) ways += b.second;
            if(br.first == highest) ways += br.second;
            int routes = static_cast<int>(ways % MOD);
            return dp[i][j] = {highest + board[i][j] - '0', routes};
        };
        pair<int, int> ans = helper(0, 0);
        if(!ans.second) return {0, 0};
        return {ans.first, ans.second};
    }
};