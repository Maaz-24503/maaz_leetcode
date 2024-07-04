class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> memo(nums.size(), {1, 1});
        int maxi = 1;
        for(int i = 1; i<nums.size(); i++){
            for(int j = 0; j<i; j++){
                if(nums[i]>nums[j]){
                    if(memo[i].first-1<memo[j].first){
                        memo[i].first = memo[j].first + 1;
                        memo[i].second = memo[j].second;
                        if(memo[i].first > maxi) maxi = memo[i].first;
                    }
                    else if(memo[i].first-1 == memo[j].first)
                        memo[i].second += memo[j].second;
                }
            }
        }
        int ways = 0;
        for(int i = 0; i<nums.size(); i++){
            if(memo[i].first == maxi) ways += memo[i].second;
        }
        return ways;
    }
};