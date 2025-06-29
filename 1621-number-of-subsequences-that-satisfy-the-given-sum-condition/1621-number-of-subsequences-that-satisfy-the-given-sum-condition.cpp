class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        vector<int> powers(n+1, 1);
        for(int i = 1; i<=n; i++) powers[i] = (2*1LL*powers[i-1])%MOD;
        int ans = 0;
        int r = n-1;
        for(int l = 0; l<n; l++){
            if(nums[l] > target) break;
            while(r >= l && nums[r] + nums[l] > target) r--;
            if(r < l) break;
            ans += powers[r - l];
            ans %= MOD;
        }
        return ans;
    }
};