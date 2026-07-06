class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), ans = 0, currRight = -1;
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        for(int i = 0; i < n; i++){
            if(currRight < intervals[i][1]){
                ans++;
                currRight = intervals[i][1];
            }
        }
        return ans;
    }
};