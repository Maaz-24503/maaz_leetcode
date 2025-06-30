class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for(int &num : nums) freq[num]++;
        int ans = 0;
        for(auto [num, f] : freq){
            if(freq.count(num+1)) ans = max(ans, f + freq[num+1]);
        }
        return ans;
    }
};