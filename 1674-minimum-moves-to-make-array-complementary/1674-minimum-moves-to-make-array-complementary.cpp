class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> target(2*limit + 2, 0);
        for(int i = 0; i < n / 2; i++){
            int a = min(nums[i], nums[n - i - 1]), b = max(nums[i], nums[n - i - 1]);
            target[2] += 2;
            target[1 + a]--;
            target[a + b]--;
            target[a + b + 1]++;
            target[limit + b + 1]++;
        }
        int ans = INT_MAX, curr = 0;
        for(int i = 2; i < target.size(); i++){
            int tar = target[i];
            curr += tar;
            ans = min(ans, curr);
        }
        return ans;
    }
};