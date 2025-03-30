class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> occ(26, -1);
        int n = s.size();
        for(int i = 0; i<n; i++) occ[s[i] - 'a'] = i;
        int far = 0;
        vector<int> ans;
        int sz = 1;
        for(int i = 0; i<n; i++){
            far = max(far, occ[s[i] - 'a']);
            if(far == i) {
                ans.push_back(sz);
                sz = 0;
            }
            sz++;
        }
        return ans;
    }
};