class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> mod;
        long long sum = 0;
        for(int i = 0; i<n; i++) sum += nums[i];
        int desired = (int)(sum % p);
        if(desired == 0) return 0;
        int ans = INT_MAX;
        sum = 0;
        mod[0] = -1;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            int curr = sum % p;
            if(mod.find((curr + p - desired) % p) != mod.end()){
                ans = min(ans, i - mod[(curr + p - desired) % p]);
            }
            mod[curr] = i;
        }
        return ans == n ? -1 : ans;
    }
};