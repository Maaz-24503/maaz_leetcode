class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int countB = 0, ans = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == 'b') countB++;
            else if(countB > 0) {
                countB--;
                ans++;
            }
        }
        return ans;
    }
};