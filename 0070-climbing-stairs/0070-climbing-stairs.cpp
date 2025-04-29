class Solution {
public:
    int climbStairs(int n) {
        return fib(n+1);
    }
    int fib(int n) {
        if(n < 2) return n;
        // | Fk+1  Fk    |
        // | Fk    Fk-1  |

        // Prove by induction for fun
        
        vector<vector<int>> mat{{1, 1}, {1, 0}};
        auto matMul = [](vector<vector<int>>& matA, vector<vector<int>>& matB) {
            vector<vector<int>> ans(2, vector<int>(2));
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    for (int k = 0; k < 2; k++)
                        ans[i][j] += matA[i][k] * matB[k][j];
            return ans;
        };

        function<vector<vector<int>>(int)> fastMul = [&](int i){
            if(i == 1) return mat;
            vector<vector<int>> rec = fastMul(i/2);
            vector<vector<int>> prod = matMul(rec, rec);
            if(i % 2){
                return matMul(mat, prod);
            }
            else return prod;
        };

        vector<vector<int>> comp = fastMul(n - 1);
        return comp[0][0];
    }
};