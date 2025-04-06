class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> enc;
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(enc.count(k - nums[i]) && enc[k - nums[i]] != 0) {
                ans++;
                enc[k - nums[i]]--;
            }
            else enc[nums[i]]++;
        }
        return ans;
    }
};