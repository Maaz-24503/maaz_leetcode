class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string &word : words) freq[word]++;
        function<bool(const pair<int, string>, const pair<int, string>)> comp = [](const pair<int, string> &a, const pair<int, string> &b) -> bool {
            if (a.first != b.first) return a.first > b.first; 
            return a.second < b.second; 
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
        for (auto &[word, f] : freq) {
            pq.push({f, word});
            if (pq.size() > k) pq.pop();
        }
        vector<string> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
