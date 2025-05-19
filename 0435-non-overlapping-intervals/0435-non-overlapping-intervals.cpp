class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 0, prev = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] >= prev) {
                ans++;
                prev = intervals[i][1];
            }
        }
        return n - ans;
    }
};