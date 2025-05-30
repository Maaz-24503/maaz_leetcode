class Solution {
private:
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

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> dp(m, 0);
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++)
                if(matrix[i][j] == '1') dp[j]++;
                else dp[j] = 0;
            ans = max(ans, largestRectangleArea(dp));
        }
        return ans;
    }
};