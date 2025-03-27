class Solution {
private:
    int n;
    vector<int> nums;
    vector<vector<int>> memo;

    int helper(int l, int r){
        if(r < l) return 0;
        if(r == l){
            return nums[l]*nums[l-1]*nums[l+1];
        }
        if(memo[l][r] != -1) return memo[l][r];
        int maxi = 0;
        for(int i = l; i<=r; i++){
            int curr = nums[i] * nums[l-1] * nums[r+1];
            int recLeft = helper(l, i-1);
            int recRight = helper(i+1, r);
            maxi = max(maxi, curr + recLeft + recRight);
        }
        return memo[l][r] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        this->nums.insert(this->nums.begin(), 1);
        this->nums.push_back(1);
        memo.resize(n+1, vector<int>(n+1, -1));
        return helper(1, n);
    }
};