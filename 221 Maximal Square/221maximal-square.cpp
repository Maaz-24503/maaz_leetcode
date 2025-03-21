class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> memo(n, vector<int> (m, 0));
        int ans = 0;
        for(int i = 0; i<n; i++) if(matrix[i][0] == '1') {memo[i][0] = 1; ans = 1;}
        for(int i = 0; i<m; i++) if(matrix[0][i] == '1'){ memo[0][i] = 1; ans = 1;}
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(matrix[i][j] == '1'){
                    int sz = min(memo[i-1][j], memo[i][j-1]);
                    memo[i][j] = matrix[i-sz][j-sz] == '1' ? sz+1 : sz;
                    ans = max(ans, memo[i][j]);
                }
            }
        }
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<m; j++) 
        //         cout<<memo[i][j]<<" "; 
        //     cout<<endl;
        // }
        return ans*ans;
    }
};