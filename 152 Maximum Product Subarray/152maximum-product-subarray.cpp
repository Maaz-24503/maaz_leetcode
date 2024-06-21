class Solution {
public:
    int maxi(long long a, long long b, long long c){
        return max(a,max(b,c));
    }
    int maxProduct(vector<int>& nums) {
        long long highest = LLONG_MIN;
        long long left = 1;
        long long right = 1;
        for(int i = 0; i<nums.size(); i++){
            int j = nums.size()-i-1;
            if(nums[i] == 0) left = 1;
            else left *= nums[i];
            if(nums[j] == 0) right = 1;
            else right *= nums[j];
            highest = maxi(highest, nums[i]!=0?left:0, nums[j]!=0?right:0);
            if(abs(left)>INT_MAX || abs(right)>INT_MAX) return highest;
        }
        return highest;
    }
};