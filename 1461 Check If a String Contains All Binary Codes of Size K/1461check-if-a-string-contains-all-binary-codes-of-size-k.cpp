class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        set<string> seen;
        for(int i = 0; i <= n - k; i++) seen.insert(s.substr(i, k));
        return seen.size() == 1<<k;
    }
};