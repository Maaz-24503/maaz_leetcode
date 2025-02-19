class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSum;
        long long sum = 0;
        int ans = 0;
        preSum[0] = 1;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            int target = sum - k;
            // cout<<i<<" "<<target<<" "<<sum<<endl;;
            if(preSum.find(target) != preSum.end()) ans += preSum[target];
            preSum[sum]++;
        }
        return ans;
    }
};