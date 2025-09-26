class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> ans;
        for(int i = 0; i<numWays.size(); i++){
            if(numWays[i]){
                if(numWays[i] != 1) return vector<int>{};
                ans.push_back(i + 1);
                for(int j = numWays.size() - 1; j > i; j--) numWays[j] -= numWays[j - i - 1];
                numWays[i] = 0;
            }
        }
        return ans;
    }
};