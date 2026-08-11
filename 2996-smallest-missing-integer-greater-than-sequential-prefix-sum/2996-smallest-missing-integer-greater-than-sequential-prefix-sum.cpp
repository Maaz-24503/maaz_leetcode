class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int sum = nums[0];
        for(int i = 1; i < n && nums[i] == nums[i - 1] + 1; i++) sum += nums[i];
        while(s.count(sum)) sum++;
        return sum;
    }
};