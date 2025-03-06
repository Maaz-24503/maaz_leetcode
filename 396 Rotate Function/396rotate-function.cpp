class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int curr = 0, n = nums.size();
        vector<int> preSum(n, 0), postSum(n, 0);
        for(int i = 1; i<nums.size(); i++){
            preSum[i] = nums[i - 1] + preSum[i - 1];
            postSum[n - i - 1] = postSum[n - i] + nums[n - i];
            curr += i*nums[i];
        }
        // for(int i = 0; i<n; i++) cout<<preSum[i]<<" ";
        // cout<<endl;
        // for(int i = 0; i<n; i++) cout<<postSum[i]<<" ";
        int ans = curr;
        // cout<<curr<<endl;
        for(int i = 1; i<n; i++){
            curr -= postSum[i-1];
            // cout<<postSum[i-1]<<" "<<(nums[i-1] * (n-1))<<" ";
            curr += (nums[i-1] * (n-1));
            if(i>1) curr -= preSum[i-1];
            ans = max(ans, curr); 
            // cout<<curr<<endl;
        }
        return ans;
    }
};