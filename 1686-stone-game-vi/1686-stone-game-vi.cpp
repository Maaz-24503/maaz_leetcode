class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> diff(n);
        for(int i = 0; i<n; i++) diff[i] = {aliceValues[i] + bobValues[i], i};
        sort(diff.rbegin(), diff.rend());
        int score = 0;
        for(int i = 0; i<n; i++){
            if(i % 2 == 0){
                score += aliceValues[diff[i].second];
            } else {
                score -= bobValues[diff[i].second];
            }
        }
        if(score == 0) return 0;
        return score > 0 ? 1 : -1;
    }
};