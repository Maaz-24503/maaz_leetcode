class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int r = -1, n = nums.size(), count = 0;
        long long ans = 0;
        unordered_map<int, int> freq;
        for(int l = 0; l<n; l++){
            while(count<k){
                r++;
                if(r == n) return ans;
                freq[nums[r]]++;
                count += freq[nums[r]]-1;
            }
            ans += n - r;
            freq[nums[l]]--;
            count -= freq[nums[l]];
        }
        return ans;
    }
};