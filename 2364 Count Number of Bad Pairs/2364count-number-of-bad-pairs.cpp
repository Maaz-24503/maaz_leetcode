class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long goodPairs = 0;
        long long n = nums.size();
        unordered_map<int, int> track;
        for(int i = 0; i<n; i++){
            track[nums[i] - i]++;
            goodPairs += (track[nums[i] - i] - 1);
        }
        long long totalPairs = (n*(n-1))/2;
        return totalPairs - goodPairs;
    }
};