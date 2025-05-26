class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> mon;
        int n = heights.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            while(!mon.empty() && mon.top().first > heights[i]){
                auto [height, ind] = mon.top();
                mon.pop();
                int width = mon.empty() ? i : i - mon.top().second - 1;
                ans = max(ans, height * width);
            }
            mon.push({heights[i], i});
        }
        int end = 0;
        if(!mon.empty()) end = mon.top().first;
        while(!mon.empty()){
            auto [height, ind] = mon.top();
            mon.pop();
            int width = mon.empty() ? n : n - mon.top().second - 1;
            ans = max(ans, height * width);
        }
        return ans;
    }
};