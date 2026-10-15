class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        auto distinctCount = [&](int i, int j) -> int {
            unordered_set<int> seen;
            int ans = 0;
            for(int k = i; k <= j && k < n; k++) {
                if(!seen.count(nums[k])){
                    seen.insert(nums[k]);
                    ans++;
                }
            }
            return ans;
        };
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int curr = distinctCount(i, j);
                ans += curr * curr;
            }
        }
        return ans;
    }
};