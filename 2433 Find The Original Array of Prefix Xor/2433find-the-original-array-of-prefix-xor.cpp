class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(1, pref[0]);
        for(int i = 1; i<n; i++){
            ans.push_back(pref[i] ^ pref[i-1]);
        }
        return ans;
    }
};