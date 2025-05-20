class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> track(n, 0);
        for(int i = 0; i<queries.size(); i++){
            track[queries[i][0]]++;
            if(queries[i][1] != n - 1) track[queries[i][1] + 1]--;
        }
        for(int i = 1; i<n; i++) track[i] += track[i - 1];
        for(int i = 0; i<n; i++) if(track[i] < nums[i]) return false;
        return true;
    }
};