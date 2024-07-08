class Solution {
public:
    double helper(int i, int k, vector<int>& nums, vector<vector<double>>& memo){
        if(i >= nums.size()) return 0;
        if(memo[i][k]!=-1) return memo[i][k];
        if(k == 1){
            if(i == nums.size()) return memo[i][k] = 0;
            double ans = 0;
            int count = 0;
            int j = i;
            while(i<nums.size()){
                ans += nums[i];
                i++;
                count++;
            }
            return memo[j][k] = ans/(count*1.0);
        }
        double ans = 0;
        double prev = 0;
        for(int j = i+1; j<=nums.size(); j++){
            prev += nums[j-1];
            ans = max(ans, (prev/(j-i)) + helper(j, k-1, nums, memo));
        }
        return memo[i][k] = ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<vector<double>> memo(nums.size(), vector<double>(k+1, -1));
        return helper(0, k, nums, memo);
    }
};