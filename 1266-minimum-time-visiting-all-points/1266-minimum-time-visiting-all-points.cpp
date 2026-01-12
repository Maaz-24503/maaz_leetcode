class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0, n = points.size();
        vector<int> prev = points[0];
        for(int i = 1; i<n; i++){
            int x = abs(points[i][0] - prev[0]), y = abs(points[i][1] - prev[1]);
            ans += max(x, y); 
            prev = points[i];
        }
        return ans;
    }
};