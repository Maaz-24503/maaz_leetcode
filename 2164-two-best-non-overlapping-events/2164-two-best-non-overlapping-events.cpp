class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n + 1, vector<int> (3, 0));
        
        auto bs = [n, events](int target) -> int {
            int l = 0, r = n;
            while(l < r){
                int mid = (l + r) / 2;
                if(events[mid][0] <= target) l = mid + 1;
                else r = mid;
            }
            return l;
        };

        for(int i = n; i >= 0; i--){
            for(int j = 0; j<=2; j++){
                if(i >= n || j == 0) dp[i][j] = 0;
                else{
                    int pick = events[i][2] + dp[bs(events[i][1])][j - 1];
                    int notPick = dp[i + 1][j];
                    dp[i][j] = max(pick, notPick);
                }
            }
        }
        return dp[0][2];
    }
};