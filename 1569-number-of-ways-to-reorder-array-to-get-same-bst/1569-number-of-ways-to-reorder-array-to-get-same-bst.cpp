class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> table(n + 1);
        int MOD = 1e9 + 7;
        for(int i = 0; i < n + 1; i++) {
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; j++) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }
        function<long long (vector<int> &)> dnc = [&](vector<int> &curr) -> long long {
            if(curr.size() == 0) return 1;
            vector<int> left, right;
            int root = curr[0];
            for(int i = 1; i < curr.size(); i++) {
                if(curr[i] < root) left.push_back(curr[i]);
                else right.push_back(curr[i]);
            }
            long long leftCall = dnc(left), rightCall = dnc(right);
            return (((leftCall * rightCall) % MOD) * table[curr.size() - 1][left.size()]) % MOD; 
        };
        return (dnc(nums) - 1) % MOD;
    }
};