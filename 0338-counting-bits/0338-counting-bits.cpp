class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i = 1; i<=n; i++){
            ans[i] = i % 2 == 0 ? ans[i>>1] : ans[i>>1] + 1; 
        }
        return ans;
    }
};