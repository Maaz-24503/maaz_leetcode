class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return false;
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    
    int helper(int top){
        for(int i = top-1; i>1; i--){
            if(isPrime(i)) return i;
        }
        return -1;
    }

    bool primeSubOperation(vector<int>& nums) {
        if(nums[0] > 2) nums[0] -= helper(nums[0]);
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]>2){
                int sub = helper(nums[i] - nums[i-1]);
                if(sub != -1) nums[i] -= sub;
            }
        }
        // for(int i = 0; i<nums.size(); i++) cout<<nums[i]<<" ";
        for(int i = 1; i<nums.size(); i++){
            if(nums[i-1] >= nums[i]) return false;
        }
        return true;
    }
};