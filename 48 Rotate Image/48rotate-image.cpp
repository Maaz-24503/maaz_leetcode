class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        transpose(matrix);
        // deb(matrix);
        reflect(matrix);
    }
private:
    int n;

    void transpose(vector<vector<int>>& matrix){
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n - i; j++){
                // [i][j] -> [n - j - 1][n - i - 1]
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][n - i - 1];
                matrix[n - j - 1][n - i - 1] = temp;
            }
    }

    void reflect(vector<vector<int>>& matrix){
        for(int i = 0; i<n/2; i++)
            for(int j = 0; j<n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = temp;
            }
    }

    void deb(vector<vector<int>>& matrix){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};