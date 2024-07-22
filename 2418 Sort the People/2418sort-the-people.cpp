class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> tbo;
        int n = names.size();
        for(int i = 0; i<n; i++){
            tbo.push_back(make_pair(heights[i], names[i]));
        }
        sort(tbo.begin(), tbo.end());
        vector<string> ans;
        for(int i = 0; i<n; i++){
            ans.push_back(tbo[n-i-1].second);
        }
        return ans;
    }
};