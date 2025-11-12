class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ones = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1) ones++;
        }
        if(ones != 0) return n - ones;
        int smallestSubarray = INT_MAX;
        for(int i = 0; i < n - 1; i++){
            int gcd = nums[i];
            for(int j = i + 1; j < n; j++){
                gcd = __gcd(gcd, nums[j]);
                if(gcd == 1) {
                    smallestSubarray = min(smallestSubarray, j - i + 1);
                    break;
                }
            }
        }
        return smallestSubarray == INT_MAX ? -1 : (smallestSubarray - 1) + (n - 1);
    }
};