class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int ans = 0, n = nums.size();
        long long MOD = 1e9 + 7;
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> freq(2*maxi + 1, 0);
        vector<int> chain(2*maxi + 1, 0);
        long long zeros = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                int prev = nums[i] * 2;
                chain[nums[i]] = (chain[nums[i]] + freq[prev]) % MOD;
                if(nums[i] % 2 == 0) ans = (ans + chain[nums[i] / 2]) % MOD;
                freq[nums[i]]++;
            } else zeros++;
        }
        long long zeroCount = (zeros % MOD) *
        ((zeros - 1 + MOD) % MOD) % MOD *
        ((zeros - 2 + MOD) % MOD) % MOD *
        166666668LL % MOD;
        return (ans + zeroCount) % MOD;
    }
};