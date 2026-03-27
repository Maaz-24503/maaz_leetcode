class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        k = k % m;
        for(int i = 0; i < n; i++){
            if(i % 2) {
                for(int j = 0; j < m; j++)
                    if(mat[i][j] != mat[i][(j + k) % m]) return false;
            } else {
                for(int j = 0; j < m; j++)
                    if(mat[i][j] != mat[i][(j - k + m) % m]) return false;
            }
        }
        return true;
    }
};