class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto [num, fr] : freq){
            pq.push({fr, num});
        }
        vector<int> ans;
        for(int i = 0; i<k; i++){ 
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};