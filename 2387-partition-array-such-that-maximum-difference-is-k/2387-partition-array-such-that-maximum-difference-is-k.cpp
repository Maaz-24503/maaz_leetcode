class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 1, beg = nums[0];
        for(int i = 1; i<n; i++){
            if(nums[i] - beg > k){
                beg = nums[i];
                count++;
            }
        }
        return count;
    }
};