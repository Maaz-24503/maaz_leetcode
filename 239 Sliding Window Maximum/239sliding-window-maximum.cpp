class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans (n-k+1, 0);
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i<k-1; i++) pq.push({nums[i], i});
        for(int i = 0; i<n-k+1; i++){
            int ind = i + k - 1;
            pq.push({nums[ind], ind});
            while(ind - pq.top().second>=k) pq.pop();
            ans[i] = pq.top().first;
        }
        return ans;
    }
};