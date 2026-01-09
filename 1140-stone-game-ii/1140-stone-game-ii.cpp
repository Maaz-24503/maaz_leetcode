class Solution {
public:
    // a + b = s
    // x = a - b
    // 2a = x + s
    // a = (x + s) / 2  -->  Final
    int stoneGameII(vector<int>& piles) {
        unordered_map<string, int> memo;
        int n = piles.size();
        function<int(int, int, bool)> dp = [&](int i, int m, bool turn) -> int {
            if(i >= n) return 0;
            string key = to_string(i) + " " + to_string(m) + (turn ? "t" : "f");
            if(memo.find(key) != memo.end()) return memo[key];
            if(turn){
                int ans = INT_MIN, sum = 0;
                for(int x = 0; x < min(2*m, n - i); x++){
                    sum += piles[x + i];
                    ans = max(ans, sum + dp(x + i + 1, max(x + 1, m), !turn));
                }
                return memo[key] = ans;
            } else {
                int ans = INT_MAX, sum = 0;
                for(int x = 0; x < min(2*m, n - i); x++){
                    sum += piles[x + i];
                    ans = min(ans, -sum + dp(x + i + 1, max(x + 1, m), !turn));
                }
                return memo[key] = ans;
            }
        };
        int sum = 0;
        for(int i = 0; i < n; i++) sum += piles[i];
        return (dp(0, 1, true) + sum) / 2;
    }
};