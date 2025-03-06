class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        int n = nums.size();
        int length = 2;
        int dif = nums[1] - nums[0];
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == dif) {
                length++;
            } else {
                if (length >= 3) {
                    int s = length - 2;
                    ans += (s * (s + 1)) / 2;
                }
                if (i == n - 1)
                    break;
                length = 2;
                dif = nums[i] - nums[i - 1];
            }
        }
        if (length >= 3) {
            int s = length - 2;
            ans += (s * (s + 1)) / 2;
        }
        return ans;
    }
};