class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> memo(n);
        int ans = 0;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                long long diff = (nums[i] + 0LL) - nums[j];
                if(diff<INT_MAX && diff>INT_MIN){
                    int dif = static_cast<int>(diff);
                    memo[i][dif] += 1;
                    if(memo[j].find(dif) != memo[j].end()){ 
                        memo[i][dif] += memo[j][dif];
                        ans += memo[j][dif];
                    }
                }
            }
        }
        return ans;
    }
};