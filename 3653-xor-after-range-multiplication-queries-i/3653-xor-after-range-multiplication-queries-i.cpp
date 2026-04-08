class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size(), MOD = 1e9 + 7;
        for(auto &query : queries){
            int l = query[0], r = query[1], k = query[2], v = query[3];
            for(int idx = l; idx <= r; idx += k)
                nums[idx] = (nums[idx] * 1LL * v) % MOD;
        }
        int ans = nums[0];
        for(int i = 1; i < n; i++) ans ^= nums[i];
        return ans;
    }
};