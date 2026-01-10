class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(), piles.rend());
        int n = piles.size(), ans = 0;
        for(int i = 0; i < n/3; i++){
            int k = 2*i + 1;
            ans += piles[k];
        }
        return ans;
    }
};