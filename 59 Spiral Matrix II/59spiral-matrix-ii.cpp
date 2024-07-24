class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 1));
        vector<bool> iter(3, false);
        int i = 0;
        int j = 0;
        int p = n;
        for(int k = 1; k<=n*n; k++){
            matrix[i][j] = k;
            if(iter[0]){
                i++;
                if(i == p-1){
                    iter[0] = false;
                    iter[1] = true;
                }
            }
            else if(iter[1]){
                j--;
                if(j == n-p){
                    iter[1] = false;
                    iter[2] = true;
                }
            }
            else if(iter[2]){
                i--;
                if(i == n-p+1){
                    iter[2] = false;
                    p -= 1;
                }
            }
            else{
                j++;
                if(j==p-1){
                    iter[0] = true;
                }
            }
        }
        return matrix;
    }
};