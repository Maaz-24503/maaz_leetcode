class Solution {
public:
    bool helper(int i, int j, int score1, int score2, vector<int>& nums, bool turn){
        if(i == j){
            if(turn) score1 += nums[i];
            else score2 += nums[i];
            return score1>=score2;
        }
        if(turn)
            return helper(i+1, j, score1+nums[i], score2, nums, false) || helper(i, j-1, score1 + nums[j], score2, nums, false);
        else
            return helper(i+1, j, score1, score2+nums[i], nums, true) && helper(i, j-1, score1, score2 + nums[j], nums, true);
        
    }
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size() == 0) return false;
        return helper(0, nums.size()-1, 0, 0, nums, true);
    }
};