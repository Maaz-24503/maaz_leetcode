class Solution {
public:
    int singleNumber(vector<int>& nums) {
        size_t n = nums.size();
        int x = 0;
        for(int i = 0; i<n; i++) x ^= nums[i];
        return x;
    }
};