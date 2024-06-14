class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), 0);
        for(int i = memo.size()-2; i>=0; i--){
            int maxJump = nums[i];
            int least = INT_MAX-1;
            for(int j = 1; j<=maxJump; j++){
                // cout<<" gothere "<<least, memo[i+j];
                if(i+j<memo.size())least = min(least, memo[i+j]);
                else break;
            }
            memo[i] = least + 1;
            // cout<<memo[i]<<endl;
        }
        return memo[0];
    }
};