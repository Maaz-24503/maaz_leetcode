class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 0;
        long long prev = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            if (points[i][0] > prev) {
                ans++;
                prev = points[i][1];
            }
        }
        return ans;
    }
};