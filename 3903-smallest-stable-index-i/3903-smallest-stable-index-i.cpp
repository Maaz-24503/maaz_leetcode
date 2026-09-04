class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> postMin(n, INT_MAX);
        postMin[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) postMin[i] = min(postMin[i + 1], nums[i]);
        int currMax = nums[0];
        for(int i = 0; i < n; i++){
            currMax = max(nums[i], currMax);
            if(currMax - postMin[i] <= k) return i;
        }
        return -1;
    }
};