class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int &num : nums){
            long long mask = 1;
            while(mask <= num) mask *= 10;
            mask /= 10;
            while(mask > 0){
                ans.push_back((num % (mask * 10)) / mask);
                mask /= 10;
            }
        }
        return ans;
    }
};