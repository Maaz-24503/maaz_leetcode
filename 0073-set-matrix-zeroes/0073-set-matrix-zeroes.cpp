class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool firstRow = !matrix[0][0];
        bool firstCol = !matrix[0][0];
        for(int i = 1; i<n; i++){
            if(!matrix[i][0]) firstCol = true;
            bool hasZero = false;
            for(int j = 0; j<m; j++) 
                if(!matrix[i][j]){
                    hasZero = true;
                    break;
                }
            if(hasZero) matrix[i][0] = 0;
        }
        for(int j = 1; j<m; j++){
             if(!matrix[0][j]) firstRow = true;
            bool hasZero = false;
            for(int i = 0; i<n; i++)
                if(!matrix[i][j]){
                    hasZero = true;
                    break;
                }
            if(hasZero) matrix[0][j] = 0;
        }
        for(int i = 1; i<n; i++){
            if(!matrix[i][0])
                for(int j = 0; j<m; j++) matrix[i][j] = 0;
        }
        for(int j = 1; j<m; j++){
            if(!matrix[0][j])
                for(int i = 0; i<n; i++) matrix[i][j] = 0;
        }
        if(firstCol) 
            for(int i = 0; i<n; i++) matrix[i][0] = 0;
        if(firstRow) 
            for(int j = 0; j<m; j++) matrix[0][j] = 0;
    }
};