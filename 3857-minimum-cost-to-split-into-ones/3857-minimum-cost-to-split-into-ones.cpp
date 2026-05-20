class Solution {
public:
    int minCost(int n) {
        vector<long long> memo(n + 1, -1);
        function<long long(int)> dp = [&](int i) -> long long {
            if(i == 1) return 0;
            if(memo[i] != -1) return memo[i];
            long long ans = LLONG_MAX;
            for(int k = 1; k <= i / 2; k++){
                int a = k, b = i - k;
                long long f1 = dp(a), f2 = dp(b);
                ans = min(ans, f1 + f2 + (a * b));
            }
            return memo[i] = ans;
        };
        return dp(n);
    }
};