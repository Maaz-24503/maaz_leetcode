class Solution {
public:

    vector<int> mostCompetitive(vector<int>& nums, int k) {
        if(k == 0) return vector<int> {};
        vector<int> ans;
        int removeable = nums.size()-k;
        ans.push_back(nums[0]);
        for(int i = 1; i<nums.size(); i++){
            if(ans.back() > nums[i] && removeable>0){
                while(ans.size()>0 && ans.back() > nums[i] && removeable>0){
                    ans.pop_back();
                    removeable--;
                }
                ans.push_back(nums[i]);
            }
            else ans.push_back(nums[i]);
        }
        while(ans.size()>k) ans.pop_back();
        return ans;
    }
};