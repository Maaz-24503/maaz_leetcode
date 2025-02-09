class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> oneD(n, 0);
        int tempBest = 0;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = n-1; i>=0; i--){
            maxi = max(maxi, prices[i]);
            oneD[i] = max(oneD[i], maxi - prices[i]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            mini = min(mini, prices[i]);
            tempBest = max(tempBest, prices[i] - mini);
            if(i<n-1) ans = max(ans, tempBest + oneD[i+1]);
            else ans = max(ans, tempBest);
        }
        return ans;
    }
};