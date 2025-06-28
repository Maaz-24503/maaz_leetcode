class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> ind(n);
        for(int i = 0; i < n; i++) ind[i] = {nums[i], i};
        sort(ind.begin(), ind.end(), greater<>());
        vector<pair<int, int>> topK(ind.begin(), ind.begin() + k);
        sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        vector<int> ans;
        for(auto &p : topK) ans.push_back(p.first);
        return ans;
    }
};
