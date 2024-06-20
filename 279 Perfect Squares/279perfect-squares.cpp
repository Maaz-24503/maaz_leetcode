class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        int i = 1;
        int curr = 1;
        while(curr<=n){
            squares.push_back(curr);
            i++;
            curr = i*i;
        }
        vector<vector<int>> memo(squares.size()+1, vector<int>(n+1, 0));
        for(int i = 0; i<=n; i++){
            memo[0][i] = i;
        }
        for(int i = 0; i<squares.size(); i++){
            for(int j = 1; j<=n; j++){
                if(j-squares[i]>=0) memo[i+1][j] = min(1+memo[i+1][j-squares[i]], memo[i][j]);
                else memo[i+1][j] = memo[i][j];
            }
        }
        return memo[squares.size()][n];
    }
};