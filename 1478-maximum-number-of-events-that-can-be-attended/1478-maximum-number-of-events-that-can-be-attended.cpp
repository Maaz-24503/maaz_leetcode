class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        priority_queue<int, vector<int>, greater<>> minPq;
        int curr = 0, ans = 0, i = 0;
        while(!minPq.empty() || i < n){
            if(minPq.empty()) curr = events[i][0];
            while(i < n && events[i][0] <= curr) minPq.push(events[i++][1]);
            minPq.pop();
            ans++;
            curr++;
            while(!minPq.empty() && minPq.top() < curr) minPq.pop();
        }
        return ans;
    }
};