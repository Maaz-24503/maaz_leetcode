class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int i = n - 1, j = 0, ans = 0;
        while(i >= 0 && j < m){
            while(i >= 0 && grid[i][j] < 0) i--;
            if(i == -1){
                ans += (m - j) * n;
                return ans;
            }
            ans += n - i - 1;
            j++;
        }
        return ans;
    }
};