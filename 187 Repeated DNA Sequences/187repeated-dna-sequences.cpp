class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> seen;
        int n = s.size();
        for(int i = 0; i<n - 9; i++){
            string curr = s.substr(i, 10);
            if(seen.find(curr) != seen.end() && seen[curr] == 1) {
                ans.push_back(curr);
            }
            seen[curr]++;
        }
        return ans;
    }
};