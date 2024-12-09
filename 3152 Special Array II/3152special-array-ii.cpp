class Solution {
public:
    vector<int> breaks;
    bool BS(int l, int r, int rangeL, int rangeR){
        if (l > r) return true;  
        int mid = (l + r) / 2;
        if (breaks[mid] > rangeL && breaks[mid] <= rangeR) return false;  
        if (breaks[mid] > rangeR) return BS(l, mid - 1, rangeL, rangeR);  
        return BS(mid + 1, r, rangeL, rangeR); 
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for(int i = 1; i<n; i++){
            if(nums[i]%2 == nums[i-1]%2) breaks.push_back(i);
        }
        vector<bool> ans(queries.size());
        for(int i = 0; i<queries.size(); i++){
            ans[i] = BS(0, breaks.size()-1, queries[i][0], queries[i][1]);
        }
        return ans;
    }
};