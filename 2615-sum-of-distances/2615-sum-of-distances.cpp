class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        vector<long long> ans(n);
        for(auto &[num, curr] : mp){
            int m = curr.size();
            vector<long long> preSum (m, 0), postSum (m, 0);
            for(int i = 1; i < m; i++){
                preSum[i] = preSum[i - 1] + curr[i - 1];
                postSum[m - i - 1] = postSum[m - i] + curr[m - i];
            }
            for(int i = 0; i < m; i++) 
                ans[curr[i]] = postSum[i] + ((2 * i - m + 1) * 1LL * curr[i]) - preSum[i];
        }
        return ans;
    }
};