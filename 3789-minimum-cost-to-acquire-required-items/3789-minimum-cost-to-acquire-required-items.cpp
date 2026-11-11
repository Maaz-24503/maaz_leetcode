class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long ans = 0;
        if(costBoth >= cost1 + cost2) return cost1 * need1 + cost2 * need2;
        if(need1 > need2) {
            ans = costBoth * need2;
            ans += min(cost1, costBoth) * (need1 - need2);
        } else {
            ans = costBoth * need1;
            ans += min(cost2, costBoth) * (need2 - need1);
        }
        return ans;
    }
};