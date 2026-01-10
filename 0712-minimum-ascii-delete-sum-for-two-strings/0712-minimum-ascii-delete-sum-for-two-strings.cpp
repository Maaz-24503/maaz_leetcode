class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> memo(n + 1, vector<int> (m + 1, 0));
        int sum = 0;
        for(int i = n - 1; i>=0; i--) {
            sum += s1[i];
            memo[i][m] = sum;
        } 
        sum = 0;
        for(int i = m - 1; i>=0; i--) {
            sum += s2[i];
            memo[n][i] = sum;
        } 
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(s1[i] == s2[j]) memo[i][j] = memo[i + 1][j + 1];
                else{
                    memo[i][j] = min(s1[i] + memo[i + 1][j], s2[j] + memo[i][j + 1]);
                }
            }
        }
        return memo[0][0];
    }
};