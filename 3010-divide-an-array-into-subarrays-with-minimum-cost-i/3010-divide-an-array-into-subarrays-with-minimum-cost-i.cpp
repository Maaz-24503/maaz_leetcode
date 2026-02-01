class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int i = 1; i < n; i++){
            int num = nums[i];
            min2 = min(num, min2);
            if(min2 < min1) swap(min1, min2);
        }
        return min1 + min2 + nums[0];
    }
};