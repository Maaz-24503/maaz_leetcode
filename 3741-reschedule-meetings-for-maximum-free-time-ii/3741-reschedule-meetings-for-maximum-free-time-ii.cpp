class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        priority_queue<pair<int, int>> gaps;
        vector<int> gapArr(n + 1, 0);
        gaps.push({startTime[0], 0});
        gapArr[0] = startTime[0];
        gaps.push({eventTime - endTime[n-1], n});
        gapArr[n] = eventTime - endTime[n-1];
        for(int i = 1; i<n; i++){
            gaps.push({startTime[i] - endTime[i - 1], i});
            gapArr[i] = startTime[i] - endTime[i - 1];
        }
        stack<pair<int, int>> temp;
        int ans = 0;
        for(int i = 0; i<n; i++){
            // consider each event being moved
            auto [currTop, ind] = gaps.top();
            while(ind == i || ind == i + 1){
                gaps.pop();
                temp.push({currTop, ind});
                auto t = gaps.top();
                currTop = t.first;
                ind = t.second;
            }
            if(currTop >= endTime[i] - startTime[i]) 
                ans = max(ans, gapArr[i] + gapArr[i + 1] + endTime[i] - startTime[i]);
            else 
                ans = max(ans, gapArr[i] + gapArr[i + 1]);
            while(!temp.empty()){
                pair<int, int> t = temp.top();
                gaps.push(t);
                temp.pop();
            }
        }
        return ans;
    }
};