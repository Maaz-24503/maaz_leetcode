class Solution {
    // private:
    //     vector<vector<int>> memo;
    //     int n;
    //     vector<vector<int>> intervals;

    //     int helper(int i){
    //         if(i == n) return 0;

    //     }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });
        int n = intervals.size();
        int currEnd = intervals[0][1];
        int dropped = 0;
        for(int i = 1; i<n; i++){
            if(intervals[i][0] < currEnd) dropped++;
            else currEnd = intervals[i][1];
        }
        return dropped;
    }
};