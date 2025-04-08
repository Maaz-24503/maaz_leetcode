class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        for(int i = n-1; i>=0; i--){
            if(seen.find(nums[i]) != seen.end()){
                return (i/3) + 1;
            }
            else seen.insert(nums[i]);
        }
        return 0;
    }
};