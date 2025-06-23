class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<26; i++){
            char curr = 'A' + i;
            int l = 0, used = 0;
            for(int r = 0; r<n; r++){
                if(s[r] != curr) used++;
                while(used > k){
                    if(s[l] != curr) used--;
                    l++;
                }
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};