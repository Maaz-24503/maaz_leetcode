class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> track;
        int maxi = 1;
        for(int i = 0; i<nums.size(); i++){
            int rt = sqrt(nums[i]);
            if(rt*rt == nums[i]){
                if(track.find(rt) == track.end()) track[nums[i]] = 1;
                else track[nums[i]] = track[rt] + 1;
                maxi = max(maxi, track[nums[i]]);
            }
            else track[nums[i]] = 1;
        }
        return maxi == 1 ? -1 : maxi;
    }
};