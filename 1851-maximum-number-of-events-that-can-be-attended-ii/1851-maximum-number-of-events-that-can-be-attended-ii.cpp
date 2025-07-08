class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        auto bs = [&](int target) -> int {
            int l = 0, r = n;
            while(l < r){
                int mid = l + (r - l) / 2;
                if(events[mid][0] <= target) l = mid + 1;
                else r = mid;
            }
            return l;
        };
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));

        // got TLE on recursive approach with memo, gotta tabulate now

        // function<int(int,int)> helper = [&](int i, int j) -> int {
        //     if(j == k || i == n) return 0;
        //     if(dp[i][j] != -1) return dp[i][j];
        //     else return dp[i][j] = max(events[i][2] + helper(bs(events[i][1]), j + 1), helper(i + 1, j));
        // };

        // Jst realized i can store all next as precomp instead of bs everytime

        vector<int> next(n, 0);
        for(int i = 0; i<n; i++) next[i] = bs(events[i][1]);

        for(int i = n - 1; i>=0; i--){
            for(int j = k - 1; j>=0; j--){
                dp[i][j] = dp[i + 1][j];
                dp[i][j] = max(dp[i][j], events[i][2] + dp[next[i]][j + 1]);
            }
        }
        return dp[0][0];
    }
};