class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i<n; i++){
            int curr = nums[i];
            for(int j = i; j < n; j++){
                curr = gcd(curr, nums[j]);
                if(curr == k) ans++;
            }
        }
        return ans;
    }
};