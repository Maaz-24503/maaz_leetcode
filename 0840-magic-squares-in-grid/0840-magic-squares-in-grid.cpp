class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        function<bool(int, int)> check = [&](int i, int j) -> bool {
            vector<bool> seen(9, false);
            for(int k = 0; k < 9; k++){
                int curr = grid[k / 3 + i][k % 3 + j];
                if(curr > 0 && curr < 10){
                    if(seen[curr - 1]) return false;
                    else seen[curr - 1] = true;
                }
                else return false;
            }
            // if(i == 0 && j == 0) cout<<"1 \n";
            for(int k = 0; k < 9; k++) 
                if(!seen[k]) 
                    return false;
            // if(i == 0 && j == 0) cout<<"2 \n";
            int sum = 0, horSum = 0, verSum = 0;
            for(int p = 0; p < 3; p++){
                for(int q = 0; q < 3; q++){
                    if(p == 0) sum += grid[i + p][j + q];
                    horSum += grid[i + p][j + q];
                    verSum += grid[i + q][j + p]; 
                }
                // if(i == 0 && j == 0) cout<<p<<" "<<horSum<<" "<<verSum<<endl; 
                if(sum != horSum || sum != verSum) return false;
                horSum = 0, verSum = 0;
            }
            // if(i == 0 && j == 0) cout<<"3 \n";
            if(grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != sum) return false;
            if(grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2] != sum) return false;
            return true;
        };
        int ans = 0;
        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < m - 2; j++){
                if(check(i, j)) ans++;
            }
        }
        return ans;
    }
};