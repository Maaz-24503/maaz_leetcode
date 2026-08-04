class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0;
        for(int k = nums[0]; k < nums[n - 1]; k++){
            if(nums[i] == k) i++;
            else ans.push_back(k);
        }
        return ans;
    }
};