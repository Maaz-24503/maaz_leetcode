class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), l = 0, r = -1, sum = 0;
        vector<vector<int>> intervals;
        while(r < n){
            while(r < n - 1 && sum < target){
                sum += arr[++r];
            }
            if(sum == target) intervals.push_back({l, r});
            if(l >= n) break;
            sum -= arr[l++];
            // cout<<r<<" "<<l<<" "<<sum<<endl<<endl;
        }
        // for(int i = 0; i < intervals.size(); i++) cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        if(intervals.size() < 2) return -1;
        sort(intervals.begin(), intervals.end());
        int m = intervals.size();
        vector<int> smallestPost(m, INT_MAX);
        smallestPost[m - 1] = intervals[m - 1][1] - intervals[m - 1][0] + 1;
        for(int i = m - 2; i >= 0; i--){
            smallestPost[i] = min(smallestPost[i + 1], intervals[i][1] - intervals[i][0] + 1);
        }
        function<int(int)> bs = [&](int k) -> int {
            int l = 0, r = m - 1, ans = -1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(intervals[mid][0] <= k){
                    l = mid + 1;
                } else {
                    ans = mid;
                    r = mid - 1;
                }
            }
            return ans;
        };
        
        int ans = INT_MAX;
            // for(int i = 0; i < m; i++) cout<<smallestPost[i]<<" ";
        for(int i = 0; i < m - 1; i++){
            int nextPossible = bs(intervals[i][1]);
            // cout<<nextPossible<<" ";
            if(nextPossible == -1) continue;
            ans = min(ans, intervals[i][1] - intervals[i][0] + 1 + smallestPost[nextPossible]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};