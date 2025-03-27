class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int dom = -1;
        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > n/2) dom = nums[i];
        }
        if(dom == -1) return -1;
        int count = 0;
        int total = freq[dom];
        for(int i = 0; i<n; i++){
            if(nums[i] == dom) count++;
            if(count > (i + 1)/2 && (total - count) > (n - i - 1)/2) return i;
        }
        return -1;
    }
};