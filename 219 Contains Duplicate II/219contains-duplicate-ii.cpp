class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> ind;
        for(int i = 0; i<nums.size(); i++){
            if(ind.find(nums[i]) == ind.end())
                ind[nums[i]] = i;
            else{
                if(i - ind[nums[i]] <= k) return true;
                else ind[nums[i]] = i;
            }
        }
        return false;
    }
};