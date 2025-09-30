class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++) temp[j] = (temp[j] + temp[j + 1]) % 10;
        }
        return temp[0];
    }
};