class Solution {
public:
    int numTrees(int n) {
        vector<int> memo(n+1, -1);
        function<int(int)> helper = [&](int k){
            if(k <= 1) return 1;
            if(memo[k] != -1) return memo[k];
            int ans = 0;
            for(int i = 1; i<=k; i++){
                ans += helper(i-1) * helper(k - i);
            }
            return memo[k] = ans;
        };
        return helper(n);
    }
};