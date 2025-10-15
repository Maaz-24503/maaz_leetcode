class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
        }
        function<bool(int)> check = [&](int k) -> bool {
            for(int i = k - 1; i < n - k; i++) 
                if(dp[i] >= k && dp[i + k] >= k) return true;
            return false;
        };
        // binary search
        int l = 1, r = n/2, ans = 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(check(mid)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};