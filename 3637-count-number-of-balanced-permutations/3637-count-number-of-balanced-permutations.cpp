class Solution {
public:
    int countBalancedPermutations(string num) {
        const int MOD = 1e9 + 7;
        int n = num.size();
        int totalSum = 0;
        vector<int> count(10, 0);

        for (char ch : num) {
            int digit = ch - '0';
            count[digit]++;
            totalSum += digit;
        }

        if (totalSum % 2 != 0) return 0;
        int target = totalSum / 2;
        int maxOdd = (n + 1) / 2;

        auto getCombinations = [&](int maxN) {
            vector<vector<long long>> comb(maxN + 1, vector<long long>(maxN + 1, 0));
            for (int i = 0; i <= maxN; i++) {
                comb[i][0] = comb[i][i] = 1;
                for (int j = 1; j < i; j++) {
                    comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
                }
            }
            return comb;
        };

        vector<vector<long long>> comb = getCombinations(maxOdd);
        vector<vector<long long>> dp(target + 1, vector<long long>(maxOdd + 1, 0));
        dp[0][0] = 1;

        int prefixSumDigits = 0;
        int prefixSumTotal = 0;

        for (int digit = 0; digit <= 9; digit++) {
            int freq = count[digit];
            prefixSumDigits += freq;
            prefixSumTotal += digit * freq;

            for (int oddCount = min(prefixSumDigits, maxOdd); oddCount >= max(0, prefixSumDigits - (n - maxOdd)); oddCount--) {
                int evenCount = prefixSumDigits - oddCount;

                for (int sum = min(prefixSumTotal, target); sum >= max(0, prefixSumTotal - target); sum--) {
                    long long waysToMake = 0;

                    for (int j = max(0, freq - evenCount); j <= min(freq, oddCount); j++) {
                        if (digit * j > sum) continue;

                        long long ways = comb[oddCount][j] * comb[evenCount][freq - j] % MOD;
                        waysToMake = (waysToMake + ways * dp[sum - digit * j][oddCount - j] % MOD) % MOD;
                    }

                    dp[sum][oddCount] = waysToMake;
                }
            }
        }

        return dp[target][maxOdd];
    }
};
