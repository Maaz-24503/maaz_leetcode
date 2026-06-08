class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> before, after;
        int n = nums.size(), equal = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) before.push_back(nums[i]);
            else if(nums[i] > pivot) after.push_back(nums[i]);
            else equal++;
        }
        for(int i = 0; i < equal; i++) before.push_back(pivot);
        for(int i = 0; i < n; i++){
            if(nums[i] > pivot) before.push_back(nums[i]);
        }
        return before;
    }
};