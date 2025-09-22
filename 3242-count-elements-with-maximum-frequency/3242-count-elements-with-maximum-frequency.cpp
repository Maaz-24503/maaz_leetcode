class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        int n  = nums.size();
        for(int i = 0; i<n; i++) freq[nums[i]]++;
        int maxi = *max_element(freq.begin(), freq.end());
        int ans = 0;
        for(int i = 0; i<freq.size(); i++) if(freq[i] == maxi) ans += maxi;
        return ans;
    }
};