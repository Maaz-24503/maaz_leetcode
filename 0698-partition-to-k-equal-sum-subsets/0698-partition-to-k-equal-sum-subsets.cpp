class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % k != 0) return false;
        int des = sum/k;
        unordered_map<string, bool> memo;
        function<bool(int, int, int, int)> helper = [&](int i, int j, int p, int mask) -> bool {
            string key = to_string(i) + to_string(j) + to_string(p) + to_string(mask);
            if(memo.find(key) != memo.end()) return memo[key];
            if(i == k) return true;
            if(p == 0) return memo[key] = helper(i + 1, 0, des, mask);
            if(j == n) return false;
            if(((1 << j) & mask) == 0 || p < nums[j]) return memo[key] = helper(i, j + 1, p, mask);
            int usedMask = mask;
            usedMask = mask & ~(1 << j);
            return memo[key] = helper(i, j + 1, p - nums[j], usedMask) || helper(i, j + 1, p, mask);
        };
        return helper(0, 0, des, (1 << n) - 1);
    }
};