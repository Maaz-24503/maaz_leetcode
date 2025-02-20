class Solution {
public:

    int minimumOperations(vector<int>& nums) {
        unordered_set<int> vals;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0) vals.insert(nums[i]);
        }
        return vals.size();
    }
};