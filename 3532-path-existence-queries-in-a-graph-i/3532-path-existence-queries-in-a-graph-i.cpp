class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> breakBefore(n, -1);
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] > maxDiff) breakBefore[i] = i;
            else breakBefore[i] = breakBefore[i - 1];
        }
        vector<bool> ans(queries.size());
        for(int i = 0; i < queries.size(); i++){
            int u = queries[i][0], v = queries[i][1];
            if(u > v) swap(u, v);
            if(breakBefore[v] > u) ans[i] = false;
            else ans[i] = true;
        }
        return ans;
    }
};