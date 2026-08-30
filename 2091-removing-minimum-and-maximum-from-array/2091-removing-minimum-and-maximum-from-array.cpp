class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), mini = INT_MAX, maxi = INT_MIN, indMin = -1, indMax = -1;
        if(n == 1) return 1;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                indMax = i;
            }
            if(nums[i] < mini){
                mini = nums[i];
                indMin = i;
            }
        }
        if(indMin > indMax) swap(indMin, indMax);
        int pos1 = indMin + 1, pos2 = indMax - indMin, pos3 = n - indMax;
        return pos1 + pos2 + pos3 - max({pos1, pos2, pos3});
    }
};