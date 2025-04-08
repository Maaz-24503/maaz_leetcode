class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), sum = nums[0];
        vector<int> postSum(n, 0);
        for(int i = n-2; i>=0; i--) postSum[i] = postSum[i+1] + nums[i+1];
        if(postSum[0] == 0) return 0;
        for(int i = 1; i<n; i++){
            if(sum == postSum[i]) return i;
            sum += nums[i];
        }
        return -1; 
    }
};