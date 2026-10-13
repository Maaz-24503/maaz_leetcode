class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            return abs(a) < abs(b);
        });
        long long sub = 0LL, add = 0LL;
        for(int i = 0; i < n/2; i++) sub += nums[i] * nums[i];
        for(int i = n/2; i < n; i++) add += nums[i] * nums[i];
        return add - sub;
    }
};