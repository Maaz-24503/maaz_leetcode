class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> found;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            found[nums[i]] = i;
        }
        int ans = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            int targetOut = sum - (2*nums[i]);
            if(found.find(targetOut) != found.end()){
                if(found[targetOut] != i) ans = max(ans, targetOut);
            }
        }
        return ans;
    }
};