class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> pres;
        int n = nums.size();
        for(int i = 0; i<n; i++) pres.insert(nums[i]);
        int elems = pres.size();
        unordered_map<int, int> freq;
        int r = -1, ans = 0;
        for(int l = 0; l<n; l++){
            while(r < n-1 && freq.size() < elems) freq[nums[++r]]++;
            if(freq.size() == elems) ans += n - r;
            freq[nums[l]]--;
            if(!freq[nums[l]]) freq.erase(nums[l]);
        }
        return ans;
    }
};