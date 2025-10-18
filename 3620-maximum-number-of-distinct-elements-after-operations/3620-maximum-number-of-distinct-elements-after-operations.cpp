class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int counter = INT_MIN, ans = 0;
        for(int i = 0; i<n; i++){
            if(counter < nums[i] - k) {
                ans++;
                counter = nums[i] - k;
            }
            else if(counter < nums[i] + k){
                ans++;
                counter++;
            }
        }
        return ans;
    }
};