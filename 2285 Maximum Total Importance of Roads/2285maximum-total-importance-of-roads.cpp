class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> freq;
        for(int i = 0; i<n; i++) freq.push_back({0, i});
        for(int i = 0; i<roads.size(); i++){
            freq[roads[i][0]].first++;
            freq[roads[i][1]].first++;
        }
        sort(freq.begin(), freq.end());
        long long sum = 0;
        for(int i = 0; i<freq.size(); i++) sum += (long long)(i+1)*freq[i].first;
        return sum;
    }
};