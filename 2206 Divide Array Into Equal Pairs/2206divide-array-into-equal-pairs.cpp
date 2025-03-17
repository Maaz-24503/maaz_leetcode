class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501, 0);
        int n = nums.size();
        for(int i = 0; i<n; i++) freq[nums[i]]++;
        for(int i = 0; i<501; i++) if(freq[i] % 2 != 0) return false;
        return true;
    }
};