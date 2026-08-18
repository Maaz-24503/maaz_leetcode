class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int &num : nums) freq[num]++;
        int ans = -1, n = nums.size();
        if(k == 1){
            for(auto [num, f] : freq){
                if(f == 1) ans = max(ans, num);
            }
        } else if(n == k) {
            return *max_element(nums.begin(), nums.end());
        } else {
            if(freq[nums[0]] == 1) ans = max(ans, nums[0]);
            if(freq[nums[n - 1]] == 1) ans = max(ans, nums[n - 1]);
        }
        return ans;
    }
};