class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int maxVal = 1, maxInd = 0;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] <= dp[j]+1){
                    dp[i] = dp[j] + 1;
                    if(dp[i] > maxVal){
                        maxVal = dp[i];
                        maxInd = i;
                    }
                }
            }
        }
        vector<int> ans;
        while(true){
            ans.push_back(nums[maxInd]);
            if(dp[maxInd] == 1) break;
            for(int i = 0; i<maxInd; i++) 
                if(dp[i] == dp[maxInd] - 1 && nums[maxInd] % nums[i] == 0){
                    maxInd = i;
                    break;
                }
        }
        return ans;
    }
};