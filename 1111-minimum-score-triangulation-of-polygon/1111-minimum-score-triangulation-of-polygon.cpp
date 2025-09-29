class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> memo(n, vector<int> (n, -1));
        function<int(int, int)> helper = [&](int i, int j) -> int {
            if(abs(i - j) <= 1) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = INT_MAX;
            for(int k = i + 1; k < j; k++){
                // left subshape + current triangle + right subshape
                int leftShape = helper(i, k);
                int currTriangle = values[i] * values[j] * values[k];
                int rightShape = helper(k, j);
                ans = min(ans, leftShape + currTriangle + rightShape);
            }
            return memo[i][j] = ans;
        };
        return helper(0, n - 1);
    }
};