class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mods;
        int n = nums.size();
        for(int i = 0; i<n; i++) mods[((nums[i] % value) + value) % value]++;
        for(int i = 0; i <= n; i++){
            if(mods.find(i % value) == mods.end() || mods[i % value] == 0) return i;
            else mods[i % value]--;
        }
        return n;
    }
};