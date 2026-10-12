class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bitCounts(32, 0);
        function<void(int)> updateBits = [&](int p) -> void {
            int i = 0;
            while(p > 0) {
                if(p % 2) bitCounts[i]++;
                p >>= 1;
                i++;
            }
        };
        for(int i = 0; i < n; i++) updateBits(nums[i]);
        vector<int> updated;
        for(int i = 0; i < n; i++){
            int curr = 0;
            for(int j = 31; j >= 0; j--){
                curr <<= 1;
                if(bitCounts[j]) {
                    curr++;
                    bitCounts[j]--;
                }
            }
            updated.push_back(curr);
        }
        long long ans = 0, MOD = 1e9 + 7;
        for(int i = 0; i < k; i++){
            ans = ((1LL * updated[i] * updated[i]) + ans) % MOD;
        }
        return (int) ans;
    }
};