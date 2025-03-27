class Solution {
private:
    int n;
    vector<int> values;
    vector<vector<int>> memo;

    int helper(int l, int r){
        if(r - l == 2) return values[l]*values[l+1]*values[l+2];
        if(r - l < 2) return 0;
        if(memo[l][r] != -1) return memo[l][r];
        int left = values[l], right = values[r], mini = INT_MAX;
        for(int i = l+1; i<r; i++){
            int curr = left*right*values[i];
            int recLeft = helper(l, i), recRight = helper(i, r);
            mini = min(recLeft + recRight + curr, mini);
        }
        return memo[l][r] = mini;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        this->values = values;
        n = values.size();
        memo.resize(n, vector<int> (n, -1));
        return helper(0, n - 1);
    }
};