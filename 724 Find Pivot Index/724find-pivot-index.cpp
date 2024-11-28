class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tSum = 0;
        for(int i = 0; i<nums.size(); i++) tSum += nums[i];
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            if((tSum - nums[i])%2 == 0) 
                if(sum == ((tSum - nums[i])/2)) return i;
            sum += nums[i];
        }
        return -1;
    }
};