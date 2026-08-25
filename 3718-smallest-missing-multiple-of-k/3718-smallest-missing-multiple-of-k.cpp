class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        for(int a = 1; a <= n; a++){
            if(!st.count(a*k)) return a*k;
        }
        return (n + 1) * k;
    }
};