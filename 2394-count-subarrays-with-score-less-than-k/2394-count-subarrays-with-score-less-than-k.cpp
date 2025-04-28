class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long total = ((n+0LL)*(n+1LL))/2;
        long long bigger = 0, sum = 0;
        int r = 0;
        for(int l = 0; l<n; l++){
            while(r < n && sum * (r-l) < k) sum += nums[r++];
            if(sum * (r-l) < k) break;
            bigger += (n - r + 1);
            sum -= nums[l];
        }
        return total - bigger;
    }
};