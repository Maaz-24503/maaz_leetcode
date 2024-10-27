class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // sum[1] = a1 - a2 + a3 - a4  <=>  a1 - (a2 - a3 + a4)  <=>  a1 - sum[2]  
        // max[i] = max(a1 - min[i+1], max[i+1])
        // min[i] = min(a1 - max[i+1], min[i+1])

        // vector<long long> maxMemo(nums.size(), 0);
        // vector<long long> minMemo(nums.size(), 0);
        long long mini = min(nums[nums.size()-1], 0);
        long long maxi = max(nums[nums.size()-1], 0);
        for(int i = nums.size()-2; i>=0; i--){
            long long temp = max(nums[i] - mini, maxi);
            mini = min(nums[i] - maxi, mini);
            maxi = temp;
        }
        return maxi;
    }
};