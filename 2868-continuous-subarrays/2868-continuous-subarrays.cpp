class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long sum = ((n + 0LL)*(n+1LL))/2, invalid = 0LL;
        int r = 0;
        map<int, int> freq;
        freq[nums[0]] = 1;
        for(int l = 0; l<n; l++){
            while(r < n - 1 && (freq.empty() || (abs(freq.begin()->first - nums[r + 1]) <= 2 && abs(prev(freq.end())->first - nums[r + 1]) <= 2))){
                r++;
                freq[nums[r]]++;
            }
            invalid += n - r - 1;
            freq[nums[l]]--;
            if(freq[nums[l]] == 0) freq.erase(nums[l]);
        }
        return sum - invalid;
    }
};