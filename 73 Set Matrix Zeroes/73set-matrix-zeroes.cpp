class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!matrix[i][j]){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto& row : rows){
            for(int i = 0; i<m; i++) matrix[row][i] = 0;
        }
        for(auto& col : cols){
            for(int i = 0; i<n; i++) matrix[i][col] = 0;
        }
    }
};