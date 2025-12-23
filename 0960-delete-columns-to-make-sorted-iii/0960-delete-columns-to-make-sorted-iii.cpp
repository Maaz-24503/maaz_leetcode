class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<int> dp(m, -1);
        function<bool(int,int)> isValid = [&](int i, int j) -> int {
            for(int k = 0; k < n; k++) 
                if(strs[k][i] > strs[k][j]) return false;
            return true;
        };
        function<int(int)> helper = [&](int i) -> int {
            if(i == m - 1) return 1;
            if(dp[i] != -1) return dp[i];
            int ans = 1;
            for(int j = i + 1; j<m; j++) 
                if(isValid(i, j)) ans = max(ans, 1 + helper(j));
            return dp[i] = ans;
        };
        int maxi = 1;
        for(int i = 0; i<m; i++) maxi = max(helper(i), maxi);
        return m - maxi;
    }
};