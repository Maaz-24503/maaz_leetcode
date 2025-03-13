class Solution {
public:
    int partitionString(string s) {
        vector<bool> seen(26, false);
        int ans = 1;
        for(int i = 0; i<s.size(); i++){
            if(seen[s[i] - 'a']){
                ans++;
                fill(seen.begin(), seen.end(), false);
            }
            seen[s[i] - 'a'] = true;
        }
        return ans;
    }
};