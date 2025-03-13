class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pre(n, 0);
        for(int i = 0; i<queries.size(); i++){
            pre[queries[i][0]]--;
            if(queries[i][1] != n-1) pre[queries[i][1] + 1]++;
        }
        for(int i = 1; i<n; i++) pre[i] += pre[i-1];
        for(int i = 0; i<n; i++) if(nums[i] + pre[i] > 0) return false;
        return true;
    }
};