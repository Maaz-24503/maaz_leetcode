class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<long long> preSum(n, 0);
        for(int i = 0; i<n; i++){
            if(nums[i] % modulo == k) preSum[i] = 1;
        }
        for(int i = 1; i<n; i++) preSum[i] += preSum[i-1];
        long long ans = 0;
        unordered_map<int, long long> freq{{0,1}};
        for(int i = 0; i<n; i++){
            long long target = (preSum[i] - k) % modulo;
            if(!freq.count(target)) freq[target] = 0;
            ans += freq[target];
            freq[preSum[i] % modulo]++;
        }
        return ans;
    }
};