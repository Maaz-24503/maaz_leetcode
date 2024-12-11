class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int maxi = -1;
        while(r<nums.size()){
            if(abs(nums[r]-nums[l]) <= 2*k) r++;
            else l++;
            maxi = max(r - l, maxi);
        }
        return maxi;
    }
};