class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0, diagSqr = 0;
        int n = dimensions.size();
        for(int i = 0; i<n; i++) {
            int currSq = (dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1]);
            if(currSq >= diagSqr) {
                if(currSq == diagSqr) ans = max(ans, dimensions[i][0] * dimensions[i][1]);
                else ans = dimensions[i][0] * dimensions[i][1];
                diagSqr = currSq;
            }
        }
        return ans;
    }
};