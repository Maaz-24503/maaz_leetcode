class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        map<vector<int>, int> memo;
        function<int(vector<int>)> dp = [&](vector<int> left) -> int {
            if(memo.count(left)) return memo[left];
            int ans = 0;
            for(int k = 0; k < n; k++) ans += price[k] * left[k];
            for(auto& sp : special) {
                vector<int> nxt = left;
                bool can = true;
                for(int k = 0; k < n; k++) {
                    nxt[k] -= sp[k];
                    if(nxt[k] < 0) { can = false; break; }
                }
                if(can) ans = min(ans, sp[n] + dp(nxt));
            }
            return memo[left] = ans;
        };
        return dp(needs);
    }
};
