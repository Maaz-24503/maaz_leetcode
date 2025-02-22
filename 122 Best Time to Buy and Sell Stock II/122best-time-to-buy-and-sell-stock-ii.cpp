class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought = -1, ans = 0;
        for(int i = 0; i<prices.size()-1; i++){
            if(bought == -1){
                if(prices[i] < prices[i + 1]) bought = prices[i];
            }
            else{
                if(prices[i]>prices[i+1]){
                    ans += prices[i] - bought;
                    bought = -1;
                }
            }
        }
        if(bought != -1) ans += prices[prices.size()-1] - bought;
        return ans;
    }
};