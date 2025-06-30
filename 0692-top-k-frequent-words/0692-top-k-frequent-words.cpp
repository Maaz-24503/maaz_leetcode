class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        int n = words.size();
        for(string &word : words) freq[word]++;
        vector<pair<int, string>> temp;
        for(auto [word, f] : freq) temp.push_back({f, word});
        sort(temp.begin(), temp.end(), [](const auto &a, const auto &b){
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
        vector<string> ans(k);
        for(int i = 0; i<k; i++) ans[i] = temp[i].second;
        return ans;
    }
};