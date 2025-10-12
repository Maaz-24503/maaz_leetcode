class Solution {
public:
    int magicalSum(int M, int K, vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        function<long long(long long, int)> modpow = [&](long long a, int b) {
            long long res = 1;
            while (b > 0) {
                if (b & 1) res = res * a % MOD;
                a = a * a % MOD;
                b >>= 1;
            }
            return res;
        };

        function<long long(int, int)> nCr = [&](int n, int r) {
            if (r > n) return 0LL;
            long long res = 1;
            for (int i = 1; i <= r; i++) {
                res = res * (n - i + 1) % MOD;
                res = res * modpow(i, MOD - 2) % MOD;
            }
            return res;
        };

        unordered_map<long long, int> memo;

        function<int(int, int, int, int)> dp = [&](int m, int k, int i, int flag) -> int {
            if (m < 0 || k < 0 || m + __builtin_popcount(flag) < k) return 0;
            if (m == 0) return (k == __builtin_popcount(flag)) ? 1 : 0;
            if (i >= n) return 0;

            long long key = (((((long long)m * 51 + k) * 51 + i) << 10) ^ flag);
            if (memo.count(key)) return memo[key];

            long long res = 0;
            for (int c = 0; c <= m; c++) {
                long long mul = nCr(m, c) * modpow(nums[i], c) % MOD;
                int f2 = flag + c;
                res = (res + mul * dp(m - c, k - (f2 % 2), i + 1, f2 / 2)) % MOD;
            }
            return memo[key] = res;
        };

        return dp(M, K, 0, 0);
    }
};
