class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        if(k == 1) return nums;
        int streak = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == nums[i-1] + 1) streak++;
            else streak = 1;
            if(i+1>=k){
                if(streak < k) ans.push_back(-1);
                else ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};