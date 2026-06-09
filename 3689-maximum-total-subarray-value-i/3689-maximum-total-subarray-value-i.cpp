class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return (k + 0LL) * ((*max_element(nums.begin(), nums.end())) - (*min_element(nums.begin(), nums.end())));
    }
};