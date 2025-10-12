class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        vector<long long> dp;
        vector<int> uniqueVals;
        vector<long long> freq;
        int n = power.size();

        for (int i = 0; i < n; i++) {
            if (i == 0 || power[i] != power[i - 1]) {
                uniqueVals.push_back(power[i]);
                freq.push_back(1);
            } else freq.back()++;
        }

        int m = uniqueVals.size();
        dp.resize(m);
        dp[0] = freq[0] * uniqueVals[0];
        for (int i = 1; i < m; i++) {
            long long take = 1LL * freq[i] * uniqueVals[i];
            int j = i - 1;
            while (j >= 0 && uniqueVals[i] - uniqueVals[j] <= 2) j--;
            if (j >= 0) take += dp[j];
            dp[i] = max(dp[i - 1], take);
        }
        return dp[m - 1];
    }
};
