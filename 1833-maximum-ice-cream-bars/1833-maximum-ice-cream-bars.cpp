class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = *max_element(costs.begin(), costs.end());
        vector<int> freq(maxi + 1, 0);
        int n = costs.size();
        for(int i = 0; i < n; i++){
            freq[costs[i]]++;
        }
        int ans = 0; 
        for(int i = 1; i <= maxi; i++){
            if(i > coins) break;
            if(freq[i] == 0) continue;
            long long possibleCost = min((1LL*coins / i) * i, 1LL * i * freq[i]);
            ans += possibleCost / i;
            coins -= possibleCost;
        }
        return ans;
    }
};