class Solution {
public:
    double helper(double remaining, int row, int col, vector<vector<double>>& memo){
        if(row<col || col<0) return 0.0;
        if(row == 0 && col == 0) return memo[row][col] = remaining;
        if(memo[row][col] != -1) return memo[row][col];
        double left = (helper(remaining, row-1, col-1, memo)-1.0)/2.0;
        double right = (helper(remaining, row-1, col, memo)-1.0)/2.0;
        double ans = 0.0;
        if(left>0) ans += left;
        if(right>0) ans += right;
        return memo[row][col] = ans;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> memo(102, vector<double>(102, -1));
        return min(helper(poured, query_row, query_glass, memo),1.0);
    }
};