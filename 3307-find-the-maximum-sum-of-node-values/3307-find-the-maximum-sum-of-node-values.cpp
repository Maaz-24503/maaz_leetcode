class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> diff;
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++) 
            if(nums[i] <= (nums[i] ^ k)) 
                diff.push_back((nums[i] ^ k) - nums[i]);
            else
                maxi = max(maxi, (nums[i] ^ k) - nums[i]);
        long long sum = 0LL;
        for(int i = 0; i<diff.size(); i++) sum += diff[i];
        if(diff.size() % 2){ 
            int temp = *min_element(diff.begin(), diff.end());
            if(maxi == INT_MIN || temp < abs(maxi)) sum -= temp;
            else sum += maxi;
        }
        for(int i = 0; i<n; i++) sum += nums[i];
        return sum;
    }
};