class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastSeen(26, -1);
        vector<bool> taken(26, false);
        string ans;
        int n = s.size();
        for(int i = 0; i < n; i++){
            lastSeen[s[i] - 'a'] = i;
        }
        for(int i = 0; i < n; i++){
            int curr = s[i] - 'a';
            if(taken[curr]) continue;
            while(ans.size() && ans[ans.size() - 1] > s[i] && lastSeen[ans[ans.size() - 1] - 'a'] > i){
                taken[ans[ans.size() - 1] - 'a'] = false;
                ans.pop_back();
            }
            taken[curr] = true;
            ans += s[i];
        }
        return ans;
    }
};