class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        const long long MOD = 1e9 + 7;

        vector<long long> preSum(n, 0);
        vector<long long> preX(n, 0);
        vector<int> cntNZ(n, 0);

        int d0 = s[0] - '0';
        preSum[0] = d0;
        preX[0] = d0;          
        cntNZ[0] = (d0 != 0) ? 1 : 0;

        for (int i = 1; i < n; i++) {
            int d = s[i] - '0';
            preSum[i] = (preSum[i - 1] + d) % MOD;
            cntNZ[i] = cntNZ[i - 1] + (d != 0 ? 1 : 0);
            if (d != 0) {
                preX[i] = (preX[i - 1] * 10 + d) % MOD;
            } else {
                preX[i] = preX[i - 1]; 
            }
        }

        vector<long long> powTen(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            powTen[i] = (powTen[i - 1] * 10) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            long long sum = preSum[r];
            if (l) sum = (sum - preSum[l - 1] + MOD) % MOD;

            long long x = preX[r];
            if (l) {
                int shift = cntNZ[r] - cntNZ[l - 1]; 
                long long sub = (preX[l - 1] * powTen[shift]) % MOD;
                x = (x - sub + MOD) % MOD;
            }

            long long res = (x * sum) % MOD;
            ans.push_back(static_cast<int>(res));
        }

        return ans;
    }
};