class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            string temp = to_string(nums[i]);
            if(temp.size() % 2 == 0) ans++;
        }
        return ans;
    }
};