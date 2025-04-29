class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long total = 0LL;
        int r = -1, maxi = *max_element(nums.begin(), nums.end()), maxCount = 0;
        for(int l = 0; l<n; l++){
            while(r<n-1 && maxCount < k) if(nums[++r] == maxi) maxCount++;
            if(maxCount >= k) total += n-r;
            else break;
            if(nums[l] == maxi) maxCount--;
        }
        return total;
    }
};