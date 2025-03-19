class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        unordered_map<int, int> ind;
        int l = 0, r = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] < pivot) ind[--l] = nums[i];
            if(nums[i] > pivot) ind[++r] = nums[i];
        }
        vector<int> ans;
        for(int i = 1; i<-(l - 1); i++){
            ans.push_back(ind[-i]);
        }
        for(int i = 0; i<n - (-l + r); i++) ans.push_back(pivot);
        for(int i  = 1; i<r+1; i++) ans.push_back(ind[i]);
        return ans;
    }
};