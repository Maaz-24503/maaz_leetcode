class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n, nums[0]);
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        long long sum = prefix[n - 1];
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            long long peechey = prefix[i];
            long long aagey = sum - peechey;
            if(peechey >= aagey) ans++;
        }
        return ans;
    }
};